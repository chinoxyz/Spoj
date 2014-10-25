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

#define MAXN 66
#define MAXW 32005

i64 dp[MAXN][MAXW];
VI atts[MAXN];
int n,w;
int ctm;

int weights[MAXN];
int impp[MAXN];
bool mainn[MAXN];
i64 dpt[11][MAXW];


void solve()
{
    i64 ret=0;
    int sz;
    i64 vall;
    i64 tw,ti;

    for(int i=1;i<=n;++i)
    {
        if(mainn[i])
        {

            MSET(dpt,0);
            ++ctm;
            sz=atts[i].size();
            vall=0;

            for(int j=0;j<=w;++j)
            {
                dp[ctm][j]=dp[ctm-1][j];
            }


            for(int j=0;j<(1<<sz);++j)
            {
                tw=weights[i];
                ti=impp[i];
                vall=tw*ti;

                for(int k=0;k<sz;++k)
                {
                    if(j&(1<<k))
                    {
                        tw+=weights[atts[i][k]];
                        ti+=impp[atts[i][k]];
                        vall+=(i64)weights[atts[i][k]]*(i64)impp[atts[i][k]];
                    }
                }

                for(int k=w;k-tw>=0;--k)
                {
                    dpt[j][k]=dp[ctm-1][k-tw]+vall;
                    dp[ctm][k]=max(dp[ctm][k],dpt[j][k]);
                }
            }

        }
    }


    ret=0;

    for(int i=0;i<=w;++i)
    {
        ret=max(ret,dp[ctm][i]);
    }

    printf("%lld\n",ret);
}



int main()
{
    freopen("Text/BACKPACK.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    int x,y,z;


    while(cases--)
    {

        scanf("%d %d",&w,&n);
        //printf("%d\t%d\n",n,w);

        for(int i=1;i<=n;++i)
        {
            atts[i].clear();
        }

        MSET(dp,0);
        MSET(mainn,0);
        ctm=0;

        for(int i=1;i<=n;++i)
        {
            scanf("%d %d %d",&x,&y,&z);

            weights[i]=x;
            impp[i]=y;

            if(z)
            {
                atts[z].PB(i);
            }
            else
            {
                mainn[i]=1;
            }
        }


        solve();
    }



    return 0;
}
