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
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
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


#define MAXN 3333
#define MAXM 15555
#define INF 99999999

int a,b;
int firstt[MAXN],nxt[MAXM<<1],to[MAXM<<1];
int e;
bool poss;
int ans;
VI arr;
int mn;
int distt[MAXN];
int darr[2][MAXN];
int n,m;


void joinn(int x,int y)
{
    to[e]=y;
    nxt[e]=firstt[x];
    firstt[x]=e++;
}


void add_edge(int x,int y)
{
    joinn(x,y);
    joinn(y,x);
}

void dfs(int node,int d,int p)
{
    //printf("%d\t%d\n",p,node);
    if(distt[node])
    {
        if(mn>distt[node])
        {
            mn=distt[node];
            arr.clear();
            arr.PB(node);
        }
        else if(mn==distt[node])
        {
            arr.PB(node);
        }

        return;
    }

    distt[node]=d;


    for(int i=firstt[node];i!=-1;i=nxt[i])
    {
        if(to[i]!=p)
        {
            dfs(to[i],d+1,node);
        }
    }
}

void djikstra(int st,int pos)
{


    queue<PII > q;
    q.push(MP(0,st));
    int x,d;

    while(!q.empty())
    {
        d=q.front().first;
        x=q.front().second;
        q.pop();

        if(d>=darr[pos][x])
        {
            continue;
        }
        darr[pos][x]=d;

        for(int i=firstt[x];i!=-1;i=nxt[i])
        {
            q.push(MP((d+1),to[i]));
        }
    }
}


void solve()
{
    MSET(darr,0x7f);
    arr.clear();
    mn=INF;
    MSET(distt,0);

    dfs(a,1,-1);

    djikstra(a,0);
    djikstra(b,1);

    mn=0;
    if(arr.size()==0)
    {
        poss=1;
        for(int i=1;i<=n;++i)
        {
            if(darr[0][i]<darr[1][i])
            {
                mn=max(mn,darr[1][i]);
            }
        }

        ans=mn;
    }
    else
    {
        for(int i=0;i<arr.size();++i)
        {
            //printf("DD\t%d\n",arr[i]);
            if(darr[0][arr[i]]<darr[1][arr[i]])
            {
                return;
            }
        }

        poss=1;

        for(int i=1;i<=n;++i)
        {
            if(darr[0][i]<darr[1][i])
            {

                mn=max(mn,darr[1][i]);
            }
            //printf("MN\t%d\t%d\n",i,mn);
        }

        ans=mn;
        //printf("NAAA\t%d\t%d\n",ans,mn);
    }
}

void MAIN()
{
    int cases;
    scanf("%d",&cases);
    int x,y;

    while(cases--)
    {
        MSET(firstt,-1);
        e=0;
        poss=0;
        ans=0;

        scanf("%d %d %d %d",&n,&m,&a,&b);
        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&x,&y);
            add_edge(x,y);
        }

        solve();

        if(!poss)
        {
            printf("No\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
}

int main()
{
	freopen("Text/CHASE1.txt","r",stdin);

    MAIN();

	return 0;
}

