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

#define MAXN 10000002
#define MAXD 10000

int primes[MAXD];
bitset<MAXD> bs;
int plenn;
int n;

void sieve()
{
    int sq=sqrt(MAXD);
    for(int i=2;i<=sq;i+=2)
    {
        if(!bs.test(i))
        {
            for(int j=i*i;j<MAXD;j+=i)
            {
                bs.set(j);
            }
        }
    }

    for(int i=3;i<MAXD;i+=2)
    {
        if(!bs.test(i))
        {
            primes[plenn++]=i;
        }
    }


}


int solve(int n)
{

    int ret=0;

    while(!(n&1))
    {
        n>>=1;
    }

    int sq=sqrt(n);
    ret=1;
    int ct;

    for(int i=0;primes[i]<=sq;++i)
    {
        if(n%primes[i]==0)
        {
            ct=0;

            while(n%primes[i]==0)
            {
                ++ct;
                n/=primes[i];
            }

            ret*=(ct+1);
            sq=sqrt(n);
        }
    }

    if(n>2)
    {
        ret<<=1;
    }

    return (ret<<1);
}


int main()
{
    freopen("Text/SEQ6.txt","r",stdin);

    sieve();

    while(true)
    {
        scanf("%d",&n);
        if(!n)
        {
            break;
        }

        printf("%d\n",solve(n));
    }



    return 0;
}
