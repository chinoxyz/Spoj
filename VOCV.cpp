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
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 100012
#define MODD 10007
#define INF 99999999


VI adj[MAXN];
bool vis[MAXN][2];
PII dp[MAXN][2];


PII dfs(int curr,int par,bool par_inc)
{
    if(vis[curr][par_inc])
    {
        return dp[curr][par_inc];
    }

    vis[curr][par_inc]=true;

    int i,j=adj[curr].size();

    PII t,ret(par_inc,1);
    bool flagg=1;

    for(i=0;i<j;++i)
    {
        if(adj[curr][i]!=par)
        {
            flagg=0;
            PII q(INF,0);

            if(par_inc)
            {
                t=dfs(adj[curr][i],curr,0);

                if(t.first<q.first)
                {
                    q=t;
                }
                else if(t.first==q.first)
                {
                    q.second=(q.second+t.second)%MODD;
                }
            }

            t=dfs(adj[curr][i],curr,1);
            if(t.first<q.first)
            {
                q=t;
            }
            else if(t.first==q.first)
            {
                q.second=(q.second+t.second)%MODD;
            }

            ret.first+=q.first;
            ret.second=(ret.second*q.second)%MODD;
        }
    }

    return dp[curr][par_inc]=ret;

}



int main()
{
    freopen("Text/VOCV.txt","r",stdin);

    int cases,n,x,y;
    scanf("%d",&cases);


    while(cases--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            adj[i].clear();
        }

        for(int i=1;i<n;++i)
        {
            scanf("%d %d",&x,&y);
            --x;
            --y;
            adj[x].PB(y);
            adj[y].PB(x);
        }

        MSET(vis,0);

        PII q=dfs(0,-1,1),t=dfs(0,-1,0);

        if(q.first>t.first)
        {
            q=t;
        }
        else if(q.first==t.first)
        {
            q.second=(q.second+t.second)%MODD;
        }
        //printf("%d %d\n",ans[0][1].first,(ans[0][1]).second%MODD);
        printf("%d %d\n",q.first,q.second%MODD);

    }




    return 0;
}
