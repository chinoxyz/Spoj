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





//#define gc getchar_unlocked
#define gc getchar

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}




#define MAXN 1000000000LL
#define MAXM 32001
#define MAXL 181

bitset<MAXM> bs;
int primes[MAXM];
int plen;
i64 num;
int n;

inline void sieve()
{

    int i,j;


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
    plen=0;
    primes[plen++]=2;

    for(i=3;i<MAXM;i+=2)
    {
        if(!bs.test(i))
        {
            primes[plen++]=i;
        }
    }

}



int main()
{
    freopen("Text/NDIV.txt","r",stdin);
    sieve();

    int a,b,n;
    int ans=0;
    int ret;
    int ct;
    int i,j,k,ti;
    //scanf("%d %d %d",&a,&b,&n);
    a=readPosInt();
    b=readPosInt();
    n=readPosInt();

    for(ti=a;ti<=b;++ti)
    {
        i=ti;
        ret=1;
        ct=0;
        j=0;
        for(k=primes[0];j<plen && (k*k)<=i;k=primes[j])
        {
            ct=0;
            while((i%k)==0)
            {
                ++ct;
                i/=k;
            }

            ret*=(++ct);
            ++j;
        }

        if(i>1)
        {
            ret*=2;
        }

        if(ret==n)
        {
            ++ans;
        }
    }

    printf("%d\n",ans);



    return 0;
}
