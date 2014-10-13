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

#define MAXN 105
int dp[MAXN];

int n,k;


int main()
{
    freopen("Text/ABA12C.txt","r",stdin);
    int cases,ct;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&k);
        MSET(dp,-1);
        dp[0]=0;

        for(int i=1;i<=k;++i)
        {
            scanf("%d",&ct);
            if(ct==-1)
            {
                continue;
            }

            for(int j=i;j<=k;++j)
            {
                if(dp[j-i]==-1)
                {
                    continue;
                }

                if(dp[j]==-1)
                {
                    dp[j]=ct+dp[j-i];
                }
                else
                {
                    dp[j]=min(dp[j],ct+dp[j-i]);
                }
            }
        }


        printf("%d\n",dp[k]);
    }




    return 0;
}
