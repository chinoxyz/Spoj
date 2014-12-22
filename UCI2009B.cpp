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

#define MAXN 1007
VPII factors[MAXN];
int primes[MAXN],pct;
bitset<MAXN> bs;
int ct[MAXN];

void sieve()
{
    int i,j;
    for(i=3;i*i<MAXN;i+=2)
    {
        if(!bs.test(i))
        {
            for(j=i*i;j<MAXN;j+=i)
            {
                bs.set(j);
            }
        }
    }
    primes[pct++]=2;

    for(i=3;i<MAXN;i+=2)
    {
        if(!bs.test(i))
        {
            primes[pct++]=i;
        }
    }
}

void factorize(int numm)
{
    int ti=numm;
    int ct;

    for(int i=0;i<pct;++i)
    {
        ct=0;
        while((ti%primes[i])==0)
        {

            ++ct;
            ti/=primes[i];
        }
        if(ct)
        {
            factors[numm].PB(MP(primes[i],ct));
        }
    }
}

void pree()
{
    sieve();
    for(int i=1;i<MAXN;++i)
    {
        factorize(i);
    }
}
void MAIN()
{
    pree();
    int cases;
    scanf("%d",&cases);
    int n,i,j;
    int numm,denn;

    //printf("DDDD%d\n",factors[3].size());

    while(cases--)
    {
        scanf("%d",&n);
        if(n==0)
        {
            printf("1\n");
            continue;
        }
        else if(n==1)
        {
            printf("A+B\n");
            continue;
        }

        numm=n;
        denn=1;
        MSET(ct,0);

        printf("A^%d+",n);


        for(i=0;i<n;++i)
        {
            for(j=0;j<factors[numm].size();++j)
            {
                ct[factors[numm][j].first]+=factors[numm][j].second;
            }

            for(j=0;j<factors[denn].size();++j)
            {
                ct[factors[denn][j].first]-=factors[denn][j].second;
            }

            for(j=0;j<pct;++j)
            {
                if(ct[primes[j]]==1)
                {
                    printf("%dx",primes[j]);
                }
                else if(ct[primes[j]]>1)
                {
                    printf("%d^%dx",primes[j],ct[primes[j]]);
                }
            }

            if(n-denn==1)
            {
                printf("A");
            }
            else if(n-denn>1)
            {
                printf("A^%d",n-denn);
            }

			if(denn==1)
            {
                printf("B");
            }
			else if(denn>1)
            {
                printf("B^%d",denn);
            }

			if(denn!=n)
            {
                printf("+");
            }

			denn++;
			--numm;
        }

        printf("\n");

    }
}

int main()
{
	freopen("Text/UCI2009B.txt","r",stdin);

	MAIN();

    return (0);
}
