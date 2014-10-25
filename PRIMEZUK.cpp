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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXN 4294967297LL
#define MAXM 65537
#define MAXL 257

bitset<MAXM> bs;
VI primes;
int plen;
i64 num;
int n;

void sieve()
{

    i64 i,j;
    bs.set(0);
    bs.set(1);


    for(j=4;j<MAXM;j+=2)
    {
        bs.set(j);
    }


    for(i=3;i<MAXL;i+=2)
    {
        if(!bs.test(i))
        {
            for(j=i*i;j<MAXM;j+=i)
            {
                bs.set(j);
            }
        }
    }
    primes.PB(2);

    for(i=3;i<MAXM;i+=2)
    {
        if(!bs.test(i))
        {
            primes.PB(i);
        }
    }
    plen=primes.size();

}

i64 solve()
{
    i64 ret=0;

    for(int i=0;i<plen;++i)
    {
        if(num%(i64)primes[i])
        {
            continue;
        }

        while((num%(i64)primes[i])==0)
        {
            num/=(i64)primes[i];
        }

        ret=primes[i];
    }

    if(num>1LL)
    {
        ret=num;
    }

    return ret;
}


int main()
{
    freopen("Text/PRIMEZUK.txt","r",stdin);
    sieve();

    int cases;
    scanf("%d",&cases);
    i64 ret;
    int ti;

    for(int t=1;t<=cases;++t)
    {
        num=1;
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",&ti);
            num*=ti;
        }
        ++num;

        ret=solve();
        printf("Case #%d: %lld\n",t,ret);
    }



    return 0;
}
