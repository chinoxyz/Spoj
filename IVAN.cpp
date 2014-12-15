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


#define MAXN 2003

int a[MAXN];
int b[MAXN];
int dp[MAXN][MAXN][3];
int l1,l2;

int ans;

void solve()
{
    int ti;
    int i,j,k,l;

    MSET(dp,0x7f);

    dp[1][1][0]=dp[1][1][1]=dp[1][1][2]=(a[1])*(b[1]);

    for(i=1;i<=l1;++i)
    {
        for(j=1;j<=l2;++j)
        {
            if(i>1 && j>1)
            {
                dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=dp[i-1][j-1][0]+a[i]*b[j];
            }

            if(i>1)
            {
                dp[i][j][2]=min(dp[i][j][2],dp[i-1][j][2]+a[i]*b[j]);
            }

            if(j>1)
            {
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+a[i]*b[j]);
            }

            dp[i][j][0]=min(dp[i][j][0],min(dp[i][j][1],dp[i][j][2]));
        }
    }


    ans=dp[l1][l2][0];
}

int main()
{
    freopen("Text/IVAN.txt","r",stdin);

    int i;

    scanf("%d %d",&l1,&l2);

    for(i=1;i<=l1;++i)
    {
        scanf("%d",a+i);
        --a[i];
    }

    for(i=1;i<=l2;++i)
    {
        scanf("%d",b+i);
        --b[i];
    }


    solve();
    printf("%d\n",ans);

    return 0;
}
