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

#define MAXN 101

int arr[MAXN];

inline i64 poww(i64 numm,i64 p)
{
    i64 ret=1;

    while(p)
    {
        if(p&1LL)
        {
            ret*=numm;
        }
        p>>=1;
        numm*=numm;
    }

    return ret;
}

inline i64 nthRootM1(i64 numm,int n)
{
    i64 ret=pow(numm,1.0/n)-1;

    while(true)
    {
        if(pow(ret*1.0,n*1.0)>1e18 || poww(ret,n)>numm)
        {
            return ret-1;
        }
        ++ret;
    }
}

inline i64 solve(i64 numm)
{
    i64 ret=numm;

    int i=1;
    i64 ti;

    while(++i)
    {
        ti=nthRootM1(numm,i);
        if(ti==1)
        {
            return ret;
        }
        ret+=(ti-1)*arr[i];
    }
}

void pree()
{
    int i,j;
    for(i=1;i<MAXN;++i)
    {
        arr[i]=i;

        for(j=1;j<i;++j)
        {
            if(i%j==0)
            {
                arr[i]-=arr[j];
            }
        }
    }
}
int main()
{
    freopen("Text/INTEGER1.txt","r",stdin);

    pree();
    i64 a,b;

    while(true)
    {
        scanf("%lld %lld",&a,&b);
        if(a==0LL && b==0LL)
        {
            break;
        }

        printf("%lld\n",solve(b)-solve(a-1));
    }

    return 0;
}
