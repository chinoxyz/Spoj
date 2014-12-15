#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>
#include <cassert>
#include<cmath>


using namespace std;


#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MAXN 2002
#define MAXB 33
#define INF 99999999
int n,b;

int arr[MAXN][MAXB];
int leftt[MAXN],rightt[MAXN];
int summ[MAXB];
int to[MAXN*MAXN],firstt[MAXN];
int nxt[MAXN*MAXN];
int e;
int distt[MAXN];

void add_edge(int x,int y)
{
    to[e]=y;
    nxt[e]=firstt[x];
    firstt[x]=e++;
}

bool bfs()
{
    int u,v;
    int i;

    queue<int> q;

    for(i=1;i<=n;++i)
    {
        if(leftt[i]==0)
        {
            distt[i]=0;
            q.push(i);
        }
        else
        {
            distt[i]=INF;
        }
    }

    distt[0]=INF;

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        if(u)
        {
            for(i=firstt[u];i!=-1;i=nxt[i])
            {
                v=to[i];

                if(distt[rightt[v]]==INF)
                {
                    distt[rightt[v]]=distt[u]+1;
                    q.push(rightt[v]);
                }
            }
        }
    }

    return distt[0]!=INF;
}


bool dfs(int u)
{
    int i,v;

    if(u)
    {
        for(int i=firstt[u];i!=-1;i=nxt[i])
        {
            v=to[i];
            if(distt[rightt[v]]==distt[u]+1)
            {
                if(dfs(rightt[v]))
                {
                    leftt[u]=v;
                    rightt[v]=u;
                    distt[u]=INF;
                    return 1;
                }
            }
        }

        distt[u]=INF;
        return 0;
    }

    return 1;
}



int hopcroft_karp()
{
    int ret=0;
    MSET(leftt,0);
    MSET(rightt,0);
    int i;

    while(bfs())
    {
        for(i=1;i<=n;++i)
        {
            if(leftt[i]==0 && dfs(i))
            {
                ++ret;
            }
        }
    }

    return ret;
}

bool tryy(int v)
{
    int st,en;
    int i,j,k,l;

    for(i=1;i<=b;++i)
    {
        j=i+v-1;
        if(j>b)
        {
            break;
        }

        e=0;
        MSET(firstt,-1);

        for(k=1;k<=n;++k)
        {
            for(l=i;l<=j;++l)
            {
                st=summ[arr[k][l]-1]+1;
                en=summ[arr[k][l]];

                while(st<=en)
                {
                    add_edge(k,st);
                    ++st;
                }
            }
        }

        if(hopcroft_karp()==n)
        {
            return 1;
        }
    }

    return 0;

}

int main()
{
    freopen("Text/STEAD.txt","r",stdin);

    scanf("%d %d",&n,&b);
    int i,j;

    for(i=1;i<=n;++i)
    {
        for(j=1;j<=b;++j)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=1;i<=b;++i)
    {
        scanf("%d",&summ[i]);
        summ[i]+=summ[i-1];
    }

    int st=1;
    int en=b;
    int midd;

    while(st<en)
    {
        midd=(st+en)>>1;

        if(tryy(midd))
        {
            en=midd;
        }
        else
        {
            st=midd+1;
        }
    }

    printf("%d\n",st);


    return 0;
}

