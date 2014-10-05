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



#define INF 100000000

int arr[32];
i64 ans;
i64 hire,salary,sev;
int n;
i64 dp[32][32];


int main() {

	freopen("Text/MKBUDGET.txt","r",stdin);
	int cases=0,i,j,k,ct;
	ct=0;

	while(true)
    {
        ++cases;

        scanf("%d",&n);
        if(n==0)
        {
            break;
        }

        scanf("%lld %lld %lld",&hire,&salary,&sev);
        MSET(arr,0);
        ans=0;

        for(int i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
        }



        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=30;++j)
            {
                dp[i][j]=INF;
            }
        }

        for(int i=arr[1];i<=30;++i)
        {
            dp[1][i]=(hire+salary)*i;
        }

        for(int i=2;i<=n;++i)
        {
            for(int j=arr[i];j<=30;++j)
            {

                for(int k=1;k<=30;++k)
                {


                    if(k<j)
                    {
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+(j-k)*hire+salary*j);
                    }
                    else
                    {
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+(k-j)*sev+salary*j);
                    }


                }
            }
        }

        ans=dp[n][1];

        for(int i=2;i<=30;++i)
        {
            ans=min(ans,dp[n][i]);
        }


        printf("Case %d, cost = $%lld\n",cases,ans);
    }


	return 0;
}
