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



#define MAXN 10002

i64 x[MAXN],y[MAXN];
int n;

i64 dp[MAXN/2][MAXN/2];


int main()
{

    freopen("Text/MPILOT.txt","r",stdin);

    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%lld %lld",x+i,y+i);
    }


    for(int i=1;i<=n/2;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(i==j)
            {
                dp[i][j]=dp[i][j-1]+x[i+j-1];
            }
            else
            {
                if(j>0)
                {
                    dp[i][j]=min(dp[i][j-1]+x[i+j-1],dp[i-1][j]+y[i+j-1]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j]+y[i+j-1];
                }

            }
        }
    }

    printf("%lld\n",dp[n/2][n/2]);


    return 0;
}
