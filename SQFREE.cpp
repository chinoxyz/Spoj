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
#define i64 long long

#define MAXN 10000010
#define MAXP 670000

bool fl[MAXN];
int summ[MAXN],mu[MAXN],primes[MAXP];
int np=0;


void pree()
{
    mu[1]=1;
    int i,j;
    int ti;

    for(i=2;i<MAXN;++i)
    {
        if(!fl[i])
        {
            primes[np++]=i;
            mu[i]=-1;
        }

        for(j=0;j<np && (ti=i*primes[j])<MAXN;++j)
        {
            fl[ti]=1;
            if(!(i%primes[j]))
            {
                mu[ti]=0;
                break;
            }

            mu[ti]=-mu[i];
        }
    }

    for(i=1;i<MAXN;++i)
    {
        summ[i]=summ[i-1]+mu[i];
    }
}


int main()
{
    freopen("Text/SQFREE.txt","r",stdin);

    pree();

    int cases;

    scanf("%d",&cases);

    i64 ret,td,n;
    int nxt;

    while(cases--)
    {
        scanf("%lld",&n);
        ret=0;

        for(i64 i=1;i*i<=n;)
        {
            td=n/i/i;
            nxt=sqrt(n/td);
            ret+=(summ[nxt]-summ[i-1])*td;
            i=nxt+1;
        }

        printf("%lld\n",ret);
    }



    return 0;
}

