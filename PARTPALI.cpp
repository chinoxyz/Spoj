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

#define MAXM 1010
#define MAXS 21

int m,s;

unsigned int poww[MAXS];
unsigned int dp[MAXS][MAXM];

int main()
{
    freopen("Text/PARTPALI.txt","r",stdin);

    int i,j,k;
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&m,&s);

        if(s==1)
        {
            printf("%d\n",9/m);
            continue;
        }

        poww[0]=1;

        for(i=1;i<s;++i)
        {
            poww[i]=(poww[i-1]*10)%m;
        }

        MSET(dp,0);

        //for(i=(s+1)/2;i<=s;++i)
        {
            //dp[i][0]=1;
            dp[(s+1)/2][0]=1;
        }

        for(i=(s+1)/2-1;i>=0;--i)
        {
            for(j=0;j<m;++j)
            {
                for(k=i==0;k<=9;++k)
                {
                    dp[i][j]+=dp[i+1][(j+k*(i!=s-i-1?poww[i]+poww[s-i-1]:poww[i]))%m];
                }
            }
        }

        printf("%u\n",dp[0][0]);

    }



    return 0;
}
