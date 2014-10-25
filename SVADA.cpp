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

#define MAXX 99999999999999999LL
#define MAXN 999999

i64 n,m;
i64 tot;

i64 arr[MAXN][2],barr[MAXN][2];

i64 calc(i64 a[][2],i64 v,i64 lenn)
{
    i64 ret=0;

    for(i64 i=0;i<lenn;++i)
    {
        if(a[i][0]<=v)
        {
            ret+=((v-a[i][0])/a[i][1])+1;
        }
    }


    return ret;
}



bool solve(i64 v)
{
    i64 ct1=calc(arr,v,n);
    i64 ct2=calc(barr,tot-v,m);

    if(ct1<=ct2)
    {
        return true;
    }

    return false;
}


int main()
{
    freopen("Text/SVADA.txt","r",stdin);

    scanf("%lld",&tot);
    scanf("%lld",&n);
    for(i64 i=0;i<n;++i)
    {
        scanf("%lld %lld",&arr[i][0],&arr[i][1]);
    }

    scanf("%lld",&m);

    for(i64 i=0;i<m;++i)
    {
        scanf("%lld %lld",&barr[i][0],&barr[i][1]);
    }

    i64 st=0LL,en=tot;

    while(st<en)
    {
        i64 midd=(st+en+1LL)/2LL;
        if(solve(midd))
        {
            st=midd;
        }
        else
        {
            en=midd-1LL;
        }
    }

    printf("%lld\n",st);

    return 0;
}
