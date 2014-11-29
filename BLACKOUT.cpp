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

#define MAXN 2002
#define MAXK 1002

int arr[MAXN][MAXN];
int dp[MAXK];
int n,m,q,k;

int main()
{
    freopen("Text/BLACKOUT.txt","r",stdin);
    int p,areaa;
    int x1,y1,x2,y2;

    MSET(dp,-1);
    dp[0]=0;

    scanf("%d %d %d %d",&n,&m,&q,&k);

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&arr[i][j]);
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }

    while(q--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        areaa=(x2-x1+1)*(y2-y1+1);
        p=arr[x2][y2]+arr[x1-1][y1-1]-arr[x1-1][y2]-arr[x2][y1-1];

        //printf("%d\t%d\n",areaa,p);

        for(int i=k;i-p>=0;--i)
        {
            if(dp[i-p]>=0)
            {
                dp[i]=max(dp[i],dp[i-p]+areaa);
            }
        }
    }
    int ans=0;

    for(int i=0;i<=k;++i)
    {
        ans=max(ans,dp[i]);
    }

    printf("%d\n",ans);



    return 0;
}
