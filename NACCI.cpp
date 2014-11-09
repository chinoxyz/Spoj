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

#define MODD 1000000000LL

#define MAXN 30
i64 leftt[MAXN][MAXN];
i64 rightt[MAXN];
i64 unitt[MAXN][MAXN];
i64 mo[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

void pree()
{
    int i,j;

    for(i=0;i<MAXN;++i)
    {
        rightt[i]=MAXN-1LL-i;
        for(j=0;j<MAXN;++j)
        {
            unitt[i][j]=1LL;
        }
    }

    for(i=0;i<MAXN;++i)
    {
        leftt[0][i]=1LL;
    }

    for(i=1;i<MAXN;++i)
    {
        leftt[i][i-1]=1LL;
    }
/*
    for(i=0;i<MAXN;++i)
    {
        for(j=0;j<MAXN;++j)
        {
            printf("%lld,",leftt[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<MAXN;++i)
    {
        printf("%lld\n",rightt[i]);
    }
*/

}

int n,k,l;


void multt(i64 a[MAXN][MAXN],i64 b[MAXN][MAXN])
{
    i64 ti[MAXN][MAXN];
    int i,j,k;
    MSET(ti,0LL);

    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            for(k=0;k<n;++k)
            {
                ti[i][j]+=((a[i][k]*b[k][j])%MODD);
                ti[i][j]%=MODD;
            }
        }
    }
    memcpy(a,ti,sizeof(ti));
}

void multt2(i64 a[MAXN][MAXN],i64 b[MAXN],i64 ret[MAXN])
{
    int i,j,k;

    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            ret[i]+=((a[i][j]*b[MAXN-n+j])%MODD);
            ret[i]%=MODD;
        }
    }
}

void poww(i64 a[MAXN][MAXN],int p)
{
    if(p<=1)
    {
        return ;
    }

    if(p&1)
    {
        i64 ti[MAXN][MAXN];
        memcpy(ti,a,sizeof(ti));

        poww(a,p>>1);
        multt(a,a);
        multt(a,ti);
    }
    else
    {
        poww(a,p>>1);
        multt(a,a);
    }
}


i64 solve()
{
    int p=n-l;
    i64 tarr[MAXN][MAXN];
    memcpy(tarr,leftt,sizeof(tarr));
    i64 ret[MAXN];
    MSET(ret,0LL);

    poww(tarr,l-n+1);
    multt2(tarr,rightt,ret);

    return ret[0];
}


int main()
{
    freopen("Text/NACCI.txt","r",stdin);
    pree();

    int cases;
    i64 ans;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&n,&k,&l);
        if(l<n)
        {
            ans=l;
        }
        else
        {
            ans=solve();
        }

        ans%=mo[k];


        printf("%lld\n",ans);
    }

    return 0;
}
