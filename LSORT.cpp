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

#define MAXN 1002
int arr[MAXN];
int pos[MAXN];
int dp[MAXN][MAXN];
int lthan[MAXN][MAXN];
int n,j,ti;

void solve()
{
    for(int i=1;i<=n;++i)
    {
        dp[i][i]=pos[i];
    }

    for(int l=2;l<=n;++l)
    {
        for(int i=1;i<=n-l+1;++i)
        {
            j=i+l-1;

            dp[i][j]=dp[i+1][j];
            dp[i][j]+=l*(pos[i]-lthan[pos[i]][j]+lthan[pos[i]][i]);

            ti=dp[i][j-1];
            ti+=l*(pos[j]-lthan[pos[j]][j-1]+lthan[pos[j]][i-1]);
            dp[i][j]=min(dp[i][j],ti);
        }
    }

    printf("%d\n",dp[1][n]);


}

int main()
{
    freopen("Text/LSORT.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
            pos[arr[i]]=i;

            for(int j=1;j<=n;++j)
            {
                lthan[i][j]=lthan[i-1][j];
                if(j>=arr[i])
                {
                    ++lthan[i][j];
                }
            }
        }

        solve();
    }


    return 0;
}
