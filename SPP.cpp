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


i64 larr[16][16],rarr[16],MODD,tarr[16][16];
int dimm,n;


void multt(i64 a[16][16],i64 b[16][16])
{
    MSET(tarr,0);

    for(int i=0;i<dimm;++i)
    {
        for(int j=0;j<dimm;++j)
        {
            for(int k=0;k<dimm;++k)
            {
                tarr[i][j]+=a[i][k]*b[k][j];
                tarr[i][j]%=MODD;
            }
        }
    }

    memcpy(a,tarr,sizeof(tarr));
}



void poww(i64 a[16][16],i64 p)
{
    i64 b[16][16];

    for(int i=0;i<dimm;++i)
    {
        for(int j=0;j<dimm;++j)
        {
            a[i][j]=0;
            b[i][j]=larr[i][j];
        }
        a[i][i]=1;
    }

    while(p>0)
    {
        if(p&1)
        {
            multt(a,b);
        }

        p>>=1;
        multt(b,b);
    }
}


i64 solve(i64 pos)
{
    i64 ret=0;

    if(pos<=n)
    {
        for(int i=1;i<=pos;++i)
        {
            ret+=rarr[n-i];
            ret%=MODD;
        }
    }
    else
    {
        i64 res[16][16];
        poww(res,pos-n);

        for(int i=0;i<dimm;++i)
        {
            ret+=res[n][i]*rarr[i];
            ret%=MODD;
        }
    }

    return ret;
}




int main()
{
    freopen("Text/SPP.txt","r",stdin);

    int cases;

    i64 x,y,ans;

    scanf("%d",&cases);

    while(cases--)
    {
        MSET(larr,0);
        scanf("%d",&n);
        dimm=n+1;

        rarr[n]=0;

        for(int i=n-1;i>=0;--i)
        {
            scanf("%lld",rarr+i);
            rarr[n]+=rarr[i];
        }

        for(int i=1;i<n;++i)
        {
            larr[i][i-1]=1;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%lld",&larr[0][i]);
            larr[n][i]=larr[0][i];
        }
        larr[n][n]=1;

        scanf("%lld %lld %lld",&x,&y,&MODD);

        ans=(((solve(y)-solve(x-1))%MODD)+MODD)%MODD;

        printf("%lld\n",ans);
    }





    return 0;
}
