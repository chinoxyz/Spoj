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

//#define gc getchar_unlocked
#define gc getchar

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}


inline i64 readPosLLD()
{
    i64 ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}


#define MAXN 5
i64 arr[MAXN];
i64 n,m,a,d;

void pree()
{
    arr[0]=a;

    for(int i=1;i<MAXN;++i)
    {
        arr[i]=arr[i-1]+d;
    }
}

inline i64 gcd(i64 a,i64 b)
{
    if(!b)
    {
        return a;
    }

    return gcd(b,a%b);
}
inline i64 calc(i64 numm,int msk)
{
    i64 lcm=1;
    i64 g;

    for(int i=0;i<5;++i)
    {
        if(!(msk&(1<<i)))
        {
            continue;
        }

        g=gcd(lcm,arr[i]);
        lcm=lcm*arr[i]/g;
    }

    return numm/lcm;
}

inline i64 solve(i64 numm)
{
    i64 ti;
    int ti2;
    i64 ret=0;
    for(int i=1;i<(1<<5);++i)
    {
        ti=calc(numm,i);
        ti2=__builtin_popcount(i);
        if(ti2&1)
        {
            ret+=ti;
        }
        else
        {
            ret-=ti;
        }
    }

    return ret;
}

int main()
{
    freopen("Text/EASYMATH.txt","r",stdin);

    int cases;
    //scanf("%d",&cases);
    cases=readPosInt();

    while(cases--)
    {
        //scanf("%lld %lld %lld %lld",&n,&m,&a,&d);
        n=readPosLLD();
        m=readPosLLD();
        a=readPosLLD();
        d=readPosLLD();

        pree();
        printf("%lld\n",m-n+1-(solve(m)-solve(n-1)));
    }


    return 0;
}
