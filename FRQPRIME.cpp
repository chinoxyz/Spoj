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



#define MAXN 100001
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


int n,k;
i64 ans;

int main()
{
    freopen("Text/FRQPRIME.txt","r",stdin);

    sieve();

    int cases,st,nxt;
    i64 x,y;

    scanf("%d",&cases);

    while(cases--)
    {
        ans=0;
        scanf("%d %d",&n,&k);

        if(k==0)
        {
            ans=(i64)n*(i64)(n-1)/2LL;
        }
        else
        {
            st=0;
            nxt=k-1;

            while(true)
            {
                if(nxt>=plen || primes[nxt]>n)
                {
                    break;
                }

                if(st==0)
                {
                    x=1;
                }
                else
                {
                    x=primes[st]-primes[st-1];
                }

                y=n-primes[nxt]+1;

                ans+=x*y;

                ++st;
                ++nxt;
            }
        }

        printf("%lld\n",ans);
    }



    return 0;
}
