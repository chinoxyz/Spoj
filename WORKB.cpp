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

#define MAXN 100000

i64 days[MAXN],num_days,flight_cost,salary;

int main()
{
    freopen("Text/WORKB.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    i64 ans=0;

    for(int t=1;t<=cases;++t)
    {
        ans=0;
        scanf("%lld %lld %lld",&num_days,&flight_cost,&salary);

        for(int i=0;i<num_days;++i)
        {
            scanf("%lld",days+i);
        }
        ans+=(num_days*salary);
        ans+=(flight_cost<<1);

        for(int i=1;i<num_days;++i)
        {
            i64 diff=days[i]-days[i-1]-1;

        ans+=min(2*flight_cost,diff*salary);
        }

        printf("Case #%d: %lld\n",t,ans);
    }

    return 0;
}
