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


#define MAXX 10000002
#define LMT 3168
#define LEN 666842

bitset<MAXX> flagg;
int primes[LEN],prlen;
int fact[100][2];


void sieve()
{
    int i,j,k;

    for(i=3;i<LMT;i+=2)
    {
        if(!flagg.test(i))
        {
            for(j=i*i,k=i<<1;j<MAXX;j+=k)
            {
                flagg.set(j);
            }
        }
    }

    primes[0]=2;

    for(i=3,j=1;i<MAXX;i+=2)
    {
        if(!flagg.test(i))
        {
            primes[j++]=i;
        }
    }

    prlen=j;
}


int factorize(int n)
{
    int i,k;

    for(i=k=0;i<prlen && primes[i]*primes[i]<=n;++i)
    {
        if(n%primes[i]==0)
        {
            fact[k][0]=primes[i];
            fact[k][1]=0;

            while(n%primes[i]==0)
            {
                n/=primes[i];
                ++fact[k][1];
            }
            ++k;
        }
    }

    if(n>1)
    {
        fact[k][0]=n;
        fact[k][1]=1;
        ++k;
    }

    return k;
}

int num_ways(int n)
{
    int res=1,i;

    for(i=0;i<n;++i)
    {
        res*=(fact[i][1]+1);
    }

    return (res+1)>>1;
}


int main()
{
    freopen("Text/TUTMRBL.txt","r",stdin);

    int n,flen,ways,i,j,f;
    sieve();

    while(true)
    {
        scanf("%d",&n);

        if(!n)
        {
            break;
        }

        flen=factorize(n);
        ways=num_ways(flen);

        printf("%d",n);

        for(i=f=0;i<flen;++i)
        {
            for(j=0;j<fact[i][1];++j,++f)
            {
                printf(" %c %d",(f?'*':'='),fact[i][0]);
            }
        }


        printf("\n");

        printf("With %d marbles, %d different rectangles can be constructed.\n", n, ways);
    }

    return 0;
}
