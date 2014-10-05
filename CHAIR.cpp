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


const i64 MODD=1000000003LL;
i64 dp[1002][1002];

i64 ncr(int n,int r)
{
    if(n<0 || r<0 || n<r)
    {
        return 0;
    }

    if(n==r || r==0)
    {
        return 1LL;
    }

    if(dp[n][r]!=-1)
    {
        return dp[n][r];
    }

    return (dp[n][r]=(ncr(n-1,r-1)+ncr(n-1,r))%MODD);
}


int main()
{
    MSET(dp,-1);
    freopen("Text/CHAIR.txt","r",stdin);

    int n,k;

    scanf("%d %d",&n,&k);

    i64 ans=ncr(n-k+1,k);
    ans-=ncr(n-k-1,k-2);
    ans+=MODD;
    ans%=MODD;

    printf("%lld\n",ans);

    return 0;
}
