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

#define MAXN 102
#define MAXL 1000001

i64 arr[MAXN];
i64 mx,mxsq;
i64 ans[9999999];
int n,asz;
int primes[MAXL];
int plen=0;
bitset<MAXL> bs;

void sieve()
{
    for(int i=3;i<=1000;i+=2)
    {
        if(!bs.test(i))
        {
            for(int j=i*i;j<MAXL;j+=i)
            {
                bs.set(j);
            }
        }
    }

    primes[plen++]=2;

    for(int i=3;i<MAXL;i+=2)
    {
        if(!bs.test(i))
        {
            primes[plen++]=i;
        }
    }
}


void solve()
{

    int ct;
    int mct;

    for(int i=0;i<plen && primes[i]<=mxsq;++i)
    {
        mct=0;
        for(int j=0;j<n;++j)
        {
            ct=0;
            while(arr[j]>1 && arr[j]%primes[i]==0)
            {
                ++ct;
                arr[j]/=primes[i];
            }
            mct=max(mct,ct);
        }

        if(mct>0)
        {
            ans[asz++]=primes[i];
        }
    }

        sort(arr,arr+n);

        if(arr[0]>1)
        {
            ans[asz++]=arr[0];
        }

    for(int i=1;i<n;++i)
    {
        if(arr[i]>1 && arr[i]!=arr[i-1])
        {
            ans[asz++]=arr[i];
        }
    }
}

int main()
{
    freopen("Text/MAIN12B.txt","r",stdin);
    int cases,ct;
    scanf("%d",&cases);
    sieve();


    for(int t=1;t<=cases;++t)
    {
        asz=0;
        mx=0;
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%lld",arr+i);
            mx=max(mx,arr[i]);
        }


        mxsq=sqrt(mx);

        solve();
        printf("Case #%d: %d\n",t,asz);


        for(int i=0;i<asz;++i)
        {
            printf("%lld\n",ans[i]);
        }
    }




    return 0;
}
