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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXN 1000002
#define MODD 1000000007LL
i64 ans[MAXN];


int main()
{
    freopen("Text/NOVICE62.txt","r",stdin);
    ans[1]=0;
    ans[2]=1;

    for(i64 i=3;i<MAXN;++i)
    {
        ans[i]=((i-1)*((ans[i-1]+ans[i-2])%MODD))%MODD;
    }

    int cases;

    scanf("%d",&cases);
    int n;

    while(cases--)
    {
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }


    return 0;
}
