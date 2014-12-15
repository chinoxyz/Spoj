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

#define MAXN 104
#define INF 99999999

char a[MAXN];
char b[MAXN];
int lenn,m,l;
bool poss;
bool arr[MAXN][MAXN];
int leftt[MAXN];
int rightt[MAXN];
int distt[MAXN];



bool bfs()
{
    int i,u,v;
    queue<int> q;

    for(int i=1;i<=m;++i)
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
            for(int i=1;i<=m;++i)
            {
                if(!arr[u][i])
                {
                    continue;
                }
                v=i;

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
        for(int i=1;i<=m;++i)
        {
            if(!arr[u][i])
            {
                continue;
            }
            v=i;

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
    MSET(distt,0);

    while(bfs())
    {
        for(int i=1;i<=m;++i)
        {
            if(leftt[i]==0 && dfs(i))
            {
                ++ret;
            }
        }
    }

    return ret;
}



bool similar(int x,int y)
{
    int st1=(x-1)*l;
    int st2=(y-1)*l;

    for(int i=0;i<l;++i)
    {
        if(!(a[st1+i]==b[st2+i] || a[st1+i]=='?' || b[st2+i]=='?'))
        {
            return 0;
        }
    }

    return 1;
}

void modifyy(int pos)
{
    int node=(pos/l)+1;

    for(int i=1;i<=m;++i)
    {
        if(similar(node,i))
        {
            arr[node][i]=1;
        }
        else
        {
            arr[node][i]=0;
        }
    }
}

void lexicall()
{
    for(int i=0;i<lenn;++i)
    {
        if(a[i]=='?')
        {
            for(char j='a';j<='f';++j)
            {
                a[i]=j;

                modifyy(i);

                if(hopcroft_karp()==m)
                {
                    break;
                }
            }
        }
    }
}


void solve()
{
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(similar(i,j))
            {
                arr[i][j]=1;
            }
            else
            {
                arr[i][j]=0;
            }
        }
    }

    if(hopcroft_karp()==m)
    {
        poss=1;
        lexicall();
    }
    else
    {
        //printf("DD\n");
        poss=0;
    }
}

int main()
{
    freopen("Text/HC12II.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        poss=0;
        scanf("%d",&m);
        scanf("%s %s",a,b);
        lenn=strlen(a);
        l=lenn/m;

        solve();

        printf("Case #%d: ",t);

        if(poss)
        {
            printf("%s\n",a);
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }


    return 0;
}
