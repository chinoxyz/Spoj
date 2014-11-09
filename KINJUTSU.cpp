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

i64 n,p;

void solve()
{
    i64 pb2=p/2;
    i64 ans=p;

    i64 tn;
    i64 d=0;
    if(n>=pb2)
    {
        n=pb2;
        d=0;
    }
    else
    {
        if(n!=1)
        {
            d=2*(pb2-n)/(n*(n-1));
        }
    }

    //printf("%lld\n",d);

    i64 to,te;
    i64 ti;
    if(n&1)
    {
        te=n/2;
        to=n-n/2;
        ti=to*(2+(to-1)*2*d)/2;
        ans-=ti;
        ans+=(1+(n-1)*d);
    }
    else
    {
        to=n/2;
        te=to;
        ti=to*(2+(to-1)*2*d)/2;
        ans-=ti;
    }

    if(n==1)
    {
        ans=p;
    }



    printf("%lld\n",ans);
}

int main()
{
    freopen("Text/KINJUTSU.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld %lld",&p,&n);
        solve();
    }



    return 0;
}

