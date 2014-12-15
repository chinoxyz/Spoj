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

#define MAXN 1003
#define MODD 1000000007LL

i64 ans;
i64 factt[MAXN<<1];
i64 invv[MAXN];
i64 n,m;
i64 summ;
i64 arr[MAXN];

void pree()
{
    MSET(invv,-1);
    factt[0]=factt[1]=1;

    for(int i=2;i<MAXN<<1;++i)
    {
        factt[i]=(factt[i-1]*i)%MODD;
    }
}


inline i64 poww(i64 x,i64 p)
{
    i64 ret=1;

    while(p)
    {
        if(p&1LL)
        {
            ret*=x;
            ret%=MODD;
        }
        p>>=1;
        x*=x;
        x%=MODD;
    }

    return  ret;
}

inline i64 finvv(i64 numm)
{
    if(invv[numm]==-1)
    {
        invv[numm]=poww(factt[numm],MODD-2LL);
    }

    return invv[numm];
}

int main()
{
    freopen("Text/BRPAR.txt","r",stdin);

    int cases;
    scanf("%d",&cases);

    pree();


    while(cases--)
    {
        scanf("%lld",&m);
        summ=0;

        for(int i=0;i<m;++i)
        {
            scanf("%lld",arr+i);
            summ+=arr[i];
        }

        ans=1;
        ans*=factt[summ<<1];
        ans%=MODD;
        ans*=finvv(summ+1);
        ans%=MODD;

        for(int i=0;i<m;++i)
        {
            ans*=finvv(arr[i]);
            ans%=MODD;
        }

        printf("%lld\n",ans);
    }


    return 0;
}

