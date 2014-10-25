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

#define INF 999999999999999999LL

VI arr;

i64 n;
int mx;
int a,s,t;

inline int cs(int ps)
{
    int ret=(78901 + 31*ps) % 699037;
    return ret;
}

inline int ct(int pt)
{
    i64 ret=(23456 + 64*pt) % 2097151;
    return ret;
}

inline int ca(int &s,int &t)
{
    s=cs(s);
    t=ct(t);
    int ret=(s%100 +1)*(t%100 +1);

    return ret;
}



inline void solve()
{
    i64 summ=0,i,j,mn,mnj;
    int si,sj,ti,tj;

    si=sj=s;
    ti=tj=t;

    mn=n+1;
    mnj=-1;
    i=j=0;

    while(j<n)
    {
        while(summ<=mx && j<n)
        {
            summ+=ca(sj,tj);
            ++j;
        }

        while(summ>mx)
        {
            summ-=ca(si,ti);
            ++i;
        }

        if(j-i<mn)
        {
            mnj=j;
            mn=j-i;
        }
    }

    printf("%lld\n",mn);
}



int main()
{
    freopen("Text/RAIN3.txt","r",stdin);

    int cases;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %lld %d",&s,&t,&n,&mx);
        solve();
    }


    return 0;
}
