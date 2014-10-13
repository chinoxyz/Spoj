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

#define MAXN 3164
bitset<MAXN> bs;
VI primes;
int plen;

void sieve()
{
    int sq=sqrt(MAXN);

    for(int i=3;i<=sq;i+=2)
    {
        if(!bs.test(i))
        {
            for(int j=i*i;j<MAXN;j+=i)
            {
                bs.set(j);
            }
        }
    }

    primes.PB(2);

    for(int i=3;i<MAXN;i+=2)
    {
        if(!bs.test(i))
        {
            primes.PB(i);
        }
    }
    plen=primes.size();
}

int main()
{
    freopen("Text/PSYCHON.txt","r",stdin);
    int cases,i,j,n,ct;
    sieve();
    int ec,oc;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        ec=oc=0;
        i=0;
        while(i<plen && n>1)
        {
            if(n%primes[i]==0)
            {
                ct=0;
                while(n%primes[i]==0)
                {
                    n/=primes[i];
                    ++ct;
                }

                if(ct&1)
                {
                    ++oc;
                }
                else
                {
                    ++ec;
                }
            }
            ++i;
        }

        if(n>1)
        {
            ++oc;
        }

        if(ec>oc)
        {
            printf("Psycho Number\n");
        }
        else
        {
            printf("Ordinary Number\n");
        }
    }



    return 0;
}
