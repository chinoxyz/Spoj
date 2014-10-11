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


#define MAXN 101
#define MAXB 13
#define INF 999999999

int gr[MAXN][MAXN];

int parcels[MAXB][2];
int n,m,st,b,leftt,ans;
int dp[1<<MAXB][MAXN];

void floyd()
{
    for(int k=0;k<n;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(gr[i][k]==-1 || gr[k][j]==-1)
                {
                    continue;
                }

                if(gr[i][j]!=-1)
                {
                    gr[i][j]=min(gr[i][j],gr[i][k]+gr[k][j]);
                }
                else
                {
                    gr[i][j]=gr[i][k]+gr[k][j];
                }


            }
        }
    }
}


void solve()
{
    floyd();

    for(int i=0;i<n;++i)
    {
        gr[i][i]=0;
    }

    for(int i=1;i<(1<<b);++i)
    {
        for(int j=0;j<b;++j)
        {
            if(i&(1<<j))
            {
                leftt=i^(1<<j);

                if(leftt==0)
                {
                    dp[i][j]=gr[st][parcels[j][0]]+gr[parcels[j][0]][parcels[j][1]];
                    continue;
                }

                for(int k=0;k<b;++k)
                {
                    if(leftt&(1<<k))
                    {
                        if(dp[i][j]==-1)
                        {
                            dp[i][j]=dp[leftt][k]+gr[parcels[k][1]][parcels[j][0]]+gr[parcels[j][0]][parcels[j][1]];
                        }
                        else
                        {
                            dp[i][j]=min(dp[i][j],dp[leftt][k]+gr[parcels[k][1]][parcels[j][0]]+gr[parcels[j][0]][parcels[j][1]]);
                        }

                    }
                }
            }
        }
    }

    ans=INF;

    for(int i=0;i<b;++i)
    {
        ans=min(ans,dp[(1<<b)-1][i]+gr[parcels[i][1]][st]);
    }

    printf("%d\n",ans);


}

int main()
{
    freopen("Text/COURIER.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    int x,y,z,ti;

    while(cases--)
    {
        MSET(gr,-1);
        MSET(dp,-1);
        scanf("%d %d %d",&n,&m,&st);
        --st;

        for(int i=0;i<m;++i)
        {
            scanf("%d %d %d",&x,&y,&z);
            --x;
            --y;

            if(gr[x][y]==-1)
            {
                gr[x][y]=gr[y][x]=z;
            }
            else
            {
                gr[x][y]=gr[y][x]=min(z,gr[x][y]);
            }

            //printf("%d\t%d\t%d\n",x,y,z);
        }

        scanf("%d",&ti);
        b=0;
        for(int i=0;i<ti;++i)
        {
            scanf("%d %d %d",&x,&y,&z);
            --x;
            --y;
            //printf("%d\t%d\t%d\n",x,y,z);

            for(int j=0;j<z;++j)
            {
                parcels[b][0]=x;
                parcels[b][1]=y;
                ++b;
            }
        }
/*
        for(int i=0;i<b;++i)
        {
            printf("%d\t%d\n",parcels[i][0],parcels[i][1]);
        }
*/
        //printf("%d\n",b);

        solve();
    }


    return 0;
}
