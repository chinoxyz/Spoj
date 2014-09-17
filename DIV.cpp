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


#define MAXX 1000000
#define MAXSQ 1000


int primes[MAXX+10];

void prime_sieve()
{

    int i,k;

    for(i=2;i<=MAXX;++i)
    {
        if(primes[i]==0)
        {
            primes[i]=i;

            for(i64 j=(i64)i*(i64)i;j<=MAXX;j+=i)
            {
                if(primes[j]==0)
                {
                    primes[j]=i;
                }
            }
        }
    }

    //printf("DD\n");

}


int divisor_count(int num)
{
    int prevv=0,cnt=0,ret=1;

    while(num>1)
    {
        if(primes[num]!=prevv)
        {
            ret*=(cnt+1);
            cnt=1;
            prevv=primes[num];
        }
        else
        {
            ++cnt;
        }
        num/=primes[num];
    }

    return ret*(cnt+1);
}

int main()
{
    //freopen("Text/FRACTION.txt","r",stdin);

    MSET(primes,0);

    prime_sieve();

    int d,i,p,q,cnt=0;

    for(i=2;i<=MAXX;++i)
    {
        d=divisor_count(i);
        p=primes[d];
        if(p==d)
        {
            continue;
        }

        q=primes[d/p];

        if(q==p || q!=d/p)
        {
            continue;
        }

        ++cnt;

        if((cnt%9)==0)
        {
            printf("%d\n",i);
        }
    }


    return 0;
}



