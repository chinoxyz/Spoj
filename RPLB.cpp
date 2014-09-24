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

#define MAXX 1001

int dp[MAXX][MAXX];
int arr[MAXX];
int n,k;

int solve(int st,int mx)
{
    if(st>=n || mx<=0)
    {
        return 0;
    }

    if(dp[st][mx]!=-1)
    {
        return dp[st][mx];
    }

    int &ret=dp[st][mx];
    ret=0;

    if(arr[st]<=mx)
    {
        ret=max(ret,arr[st]+solve(st+2,mx-arr[st]));
    }

    ret=max(ret,solve(st+1,mx));

    return ret;
}

int main()
{
    freopen("Text/RPLB.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        MSET(dp,-1);
        scanf("%d %d",&n,&k);

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        printf("Scenario #%d: %d\n",t,solve(0,k));
    }

    return 0;
}
