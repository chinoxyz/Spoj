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

#define MAXN 1000000000000000002LL
#define MAXK 1000000000002LL
#define MK 1000012LL

i64 md[MK];
i64 primes[MK];
int np=0;


void pree()
{
    md[1]=1LL;
    i64 j;
    for(i64 i=2LL;i<MK;++i)
    {
        if(md[i]==0LL)
        {
            md[i]=i;
            primes[np++]=i;
            for(j=i*i;j<MK;j+=i)
            {
                if(!md[j])
                {
                    md[j]=i;
                }
            }
        }
    }
}


i64 solve(i64 n,i64 k)
{

    int st=0;
    i64 d;
    i64 ct,ti;

    i64 ret=MAXN;
    i64 td;
    i64 ct2;



    while(k>=MK && st<np)
    {
        if((k%primes[st])==0LL)
        {
            d=primes[st];
            ct2=0LL;

            while((k%primes[st])==0LL)
            {
                k/=primes[st];
                ++ct2;
            }

            ct=0LL;
            td=d;

            while((n/d))
            {
                ct+=(n/d);
                if(d>(MAXN/td))
                {
                    break;
                }
                d*=td;
            }

            ret=min(ret,ct/ct2);
        }
        ++st;
    }

    if(k>=MK)
    {
        d=k;
        td=d;

        ct=0LL;

        while((n/d))
        {
            ct+=(n/d);
            if(d>(MAXN/td))
            {
                break;
            }
            d*=td;
        }

        ret=min(ret,ct);
    }
    else
    {
        while(k>1LL)
        {
            d=md[k];
            ct2=0LL;

            while((k%d)==0LL)
            {
                ++ct2;
                k/=d;
            }

            ct=0LL;
            td=d;

            while((n/d))
            {
                ct+=(n/d);
                if(d>(MAXN/td))
                {
                    break;
                }
                d*=td;
            }

            ret=min(ret,ct/ct2);
        }
    }

    return ret;
}

int main()
{
    freopen("Text/GCPC11A.txt","r",stdin);

    pree();

    int cases;

    scanf("%d",&cases);
    i64 n,k;

    while(cases--)
    {
        scanf("%lld %lld",&n,&k);

        printf("%lld\n",solve(n,k));
    }



    return 0;
}

