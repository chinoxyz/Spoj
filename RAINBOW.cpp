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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXN 1002
#define MAXC 1002
#define MAXM 2000000

int n,c;
int to[MAXM],first_edge[MAXN],nxt[MAXM];
int weights[MAXN];
int gps;
int gpw[MAXN];
int gpc[MAXN];
bool vis[MAXN];
int wss;
int ctp;
int num_edges;
int dp[MAXC];

void add_edge(int u,int v)
{
    to[num_edges]=v;
    nxt[num_edges]=first_edge[u];
    first_edge[u]=num_edges++;

    to[num_edges]=u;
    nxt[num_edges]=first_edge[v];
    first_edge[v]=num_edges++;
}

int dfs(int node)
{
    ++ctp;
    wss+=weights[node];
    vis[node]=true;

    for(int i=first_edge[node];i>-1;i=nxt[i])
    {
        if(!vis[to[i]])
        {
            dfs(to[i]);
        }
    }
}


int solve()
{
    MSET(dp,0);

    for(int i=1;i<=gps;++i)
    {
        for(int j=c;j-gpw[i]>=0;--j)
        {
            dp[j]=max(dp[j],dp[j-gpw[i]]+gpc[i]);
        }
    }

    int ret=0;

    for(int i=0;i<=c;++i)
    {
        ret=max(ret,dp[i]);
    }

    return ret;
}



int main()
{
    freopen("Text/RAINBOW.txt","r",stdin);
    int m,ti;

    while(true)
    {
        scanf("%d %d",&n,&c);
        //printf("%d\t%d\n",n,c);

        if(n+c==0)
        {
            break;
        }

        num_edges=0;
        MSET(first_edge,-1);
        MSET(vis,0);
        gps=0;
        MSET(gpw,0);
        MSET(gpc,0);

        for(int i=0;i<n;++i)
        {
            scanf("%d",weights+i);
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",&m);

            for(int j=0;j<m;++j)
            {
                scanf("%d",&ti);
                --ti;
                add_edge(i,ti);
                //printf("EE\t%d\t%d\n",i,ti);
            }
        }

        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                ctp=0;
                wss=0;
                dfs(i);

                ++gps;
                gpw[gps]=wss;
                gpc[gps]=ctp;
            }
        }

        printf("%d\n",solve());
    }


    return 0;
}
