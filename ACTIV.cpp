#include <bits/stdc++.h>

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


#define MAXN 100004
#define MODD 100000000

int dp[MAXN][2];


PII arr[MAXN];
int n;
VI::iterator it;

void solve()
{
    MSET(dp,0);

    VI v;

    dp[0][1]=1;
    int diff;

    v.PB(arr[0].first);

    for(int i=1;i<n;++i)
    {
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MODD;
        it=upper_bound(v.begin(),v.end(),arr[i].second);
        diff=it-v.begin();

        if(arr[i].second<v[0])
        {
            dp[i][1]=1;
        }
        else
        {
            --diff;
            dp[i][1]=1;
            dp[i][1]+=dp[diff][1]+dp[diff][0];
            dp[i][1]%=MODD;
        }

        v.PB(arr[i].first);
    }

    int ans=(dp[n-1][0]+dp[n-1][1])%MODD;

    printf("%08d\n",ans);


}

int main()
{
    freopen("Text/ACTIV.txt","r",stdin);

    while(true)
    {
        scanf("%d",&n);

        if(n==-1)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d %d",&arr[i].second,&arr[i].first);
        }

        sort(arr,arr+n);

        solve();
    }





    return 0;
}

