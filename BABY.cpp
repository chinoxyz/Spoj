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

int n;
int ya[16],yb[16],dp[1<<16];

int solve(int maskk)
{
    int idx=__builtin_popcount(maskk);

    if(idx==n)
    {
        return 0;
    }

    if(dp[maskk]!=-1)
    {
        return dp[maskk];
    }

    int &ret=dp[maskk];
    ret=10000;

    for(int i=0;i<n;++i)
    {
        if((maskk&(1<<i))==0)
        {
            ret=min(ret,abs(idx-i)+abs(yb[idx]-ya[i])+solve(maskk|(1<<i)));
        }
    }

    return ret;
}



int main()
{
    freopen("Text/BABY.txt","r",stdin);


    while(true)
    {
        scanf("%d",&n);

        if(n==0)
        {
            break;
        }

        MSET(dp,-1);

        for(int i=0;i<n;++i)
        {
            scanf("%d",yb+i);
            --yb[i];
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",ya+i);
            --ya[i];
        }

        printf("%d\n",solve(0));
    }



    return 0;
}
