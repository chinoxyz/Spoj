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


#define MODD 1000000007LL
#define MAXN 101

i64 n,k;

i64 arr[MAXN];
bool mp[MAXN][MAXN];
i64 ct[MAXN];

void solve()
{
    i64 ans=1;
    MSET(mp,0);
    MSET(ct,0);
    i64 ti;

    for(int i=0;i<n;++i)
    {
        ti=k-ct[i];
    }

    printf("%lld\n",ans);
}


int main()
{
    freopen("Text/AMR10J.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld %lld",&n,&k);

        for(int i=0;i<n;++i)
        {
            scanf("%lld",arr+i);
        }
        solve();
    }


    return 0;
}

