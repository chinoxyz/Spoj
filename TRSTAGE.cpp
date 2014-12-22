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


#define INF 99999999

#define MAXN 11
#define MAXM 33

double dp[1<<MAXN][MAXM];
int gr[MAXM][MAXM];
int e;
int a,b;
int p;
int tickets[MAXN];
bool poss;
double ans;
int n,m;

void joinn(int x,int y,int v)
{
    gr[x][y]=v;
}

void add_edge(int x,int y,int v)
{
    joinn(x,y,v);
    joinn(y,x,v);
}


void initt()
{
    poss=0;
    for(int i=0;i<(1<<n);++i)
    {
        fill(dp[i],dp[i]+m,INF);
    }
    --a;
    --b;
    MSET(gr,-1);
}

void solve()
{

    dp[(1<<n)-1][a]=0;
    ans=INF;
    for(int s=(1<<n)-1;s>=0;--s)
    {
        ans=min(ans,dp[s][b]);
        for(int v=0;v<m;++v)
        {
            for(int i=0;i<n;++i)
            {
                if(s&(1<<i))
                {
                    for(int u=0;u<m;++u)
                    {
                        if(gr[v][u]>0)
                        {
                            dp[s&~(1<<i)][u]=min(dp[s&~(1<<i)][u],dp[s][v]+(double)gr[v][u]/tickets[i]);
                        }
                    }
                }
            }
        }
    }

    if(ans<INF)
    {
        poss=1;
    }

}

void MAIN()
{
    int x,y,i;
    int z;

    while(true)
    {
        scanf("%d %d %d %d %d",&n,&m,&p,&a,&b);
        if(n+m+p+a+b==0)
        {
            break;
        }

        initt();

        for(i=0;i<n;++i)
        {
            scanf("%d",tickets+i);
        }

        for(i=0;i<p;++i)
        {
            scanf("%d %d %d",&x,&y,&z);
            --x;
            --y;
            add_edge(x,y,z);
        }

        solve();
        if(poss)
        {
            //cout<<ans<<endl;
            printf("%.3f\n",ans);
        }
        else
        {
            printf("Impossible\n");
        }
    }
}

int main() {

	freopen("Text/TRSTAGE.txt","r",stdin);

    MAIN();

	return 0;
}
