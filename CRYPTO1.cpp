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

const u64 MOD=4000000007LL;

u64 pow_mod(u64 a,u64 p)
{
    //printf("PM\t%llu\t%llu\n",a,p);
    a%=MOD;

    u64 ret=1LL;

    while(p>0LL)
    {
        if(p&1LL)
        {
            ret=(ret*a)%MOD;
        }

        a=(a*a)%MOD;
        p>>=1LL;
    }

    //printf("POWMOD\t%llu\n",ret);

    return ret;
}


u64 kk(u64 p)
{
    u64 ret=(u64)(((p - 1LL) / 2LL - 1LL) / 2LL);

    //printf("KK\t%llu\n",ret);

    return ret;
}


u64 solve(u64 a)
{
    u64 sqrt=pow_mod(a,kk(MOD)+1LL);

    if(sqrt>MOD/2LL)
    {
        sqrt=MOD-sqrt;
    }

    return sqrt;
}


int main() {

    freopen("Text/CRYPTO1.txt","r",stdin);

    //printf("TPPPPPPP\t%llu\n",pow_mod(4,3));

    u64 a;
    scanf("%llu",&a);

    u64 ti=solve(a);

    //printf("%llu\t%llu\n",a,ti);


    time_t now=time(0);
    now-=now;
    now+=ti;

    char *dt=ctime(&now);
    tm *gmtm=gmtime(&now);
    dt=asctime(gmtm);
    cout<<dt<<endl;

    return 0;
}
