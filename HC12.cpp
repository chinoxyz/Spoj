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


#define MAXN 10001
#define MAXM 1001
#define MODD 1000000007LL

i64 ncr[MAXM][MAXM];
i64 arr[MAXN];
i64 factt[MAXN];

void pree()
{

    int i,j;
    factt[0]=1;

    for(i=1;i<MAXN;++i)
    {
        factt[i]=(i*factt[i-1])%MODD;
    }
}

i64 poww(i64 n,i64 p)
{
    i64 ret=1;

    while(p)
    {
        if(p&1LL)
        {
            ret*=n;
            ret%=MODD;
        }
        p>>=1;
        n*=n;
        n%=MODD;
    }

    return ret;
}

i64 cinv(i64 n)
{
    return poww(n,MODD-2);

}


inline i64 calc(int n,int r)
{
    i64 ret=factt[n];
    ret*=cinv(factt[r]);
    ret%=MODD;
    ret*=cinv(factt[n-r]);
    ret%=MODD;

    return ret;
}


int main()
{
    freopen("Text/HC12.txt","r",stdin);
    int cases;
    pree();

    scanf("%d",&cases);
    i64 ret;
    int i;
    int n,k;

    for(int t=1;t<=cases;++t)
    {
        scanf("%d %d",&n,&k);

        for(i=1;i<=n;++i)
        {
            scanf("%lld",arr+i);
        }

        sort(arr+1,arr+n+1);

        ret=0;

        for(i=n;i>=k;--i)
        {
            ret+=((arr[i]*calc(i-1,k-1))%MODD);
            ret%=MODD;
        }

        printf("Case #%d: %lld\n",t,ret);

    }

    return 0;
}
