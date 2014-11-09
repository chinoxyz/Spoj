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

const int MAXN=2000002;
const int MAXN2=MAXN<<1;

i64 factt[MAXN2];
i64 invv[MAXN2];
i64 n;

inline void pree()
{
    MSET(invv,-1LL);
    invv[0]=invv[1]=1LL;
    factt[0]=factt[1]=1LL;

    for(int i=2;i<MAXN2;++i)
    {
        factt[i]=factt[i-1]*i;
        factt[i]%=MODD;
    }
}


inline i64 poww(i64 n,i64 p)
{
    i64 ret=1LL;

    while(p)
    {
        if(p&1LL)
        {
            ret*=n;
            ret%=MODD;
        }
        p>>=1;
        n*=n;
        n%=MODD;
    }

    return ret;
}

inline i64 calc(i64 n)
{
    return poww(n,MODD-2LL);
}

inline i64 minv(i64 n)
{
    if(invv[n]==-1LL)
    {
        invv[n]=calc(n);
    }

    return invv[n];
}


inline i64 ncr(i64 n,i64 r)
{
    i64 ret=factt[n];
    ret%=MODD;
    ret*=minv(n-r);
    ret%=MODD;
    ret*=minv(r);
    ret%=MODD;

    return ret;
}



int main()
{
    freopen("Text/KOPC12B.txt","r",stdin);
    int cases;
    i64 ti;
    pree();
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld",&n);
        ti=ncr((n<<1)-1LL,n-1LL);
        ti%=MODD;
        ti*=n;
        ti%=MODD;
        printf("%lld\n",ti);
    }

    return 0;
}
