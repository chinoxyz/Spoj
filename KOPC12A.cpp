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


#define MAXN 10001

struct building
{
    int heightt,cost;

    bool operator<(const building &b) const
    {
        if(heightt==b.heightt)
        {
            return cost<b.cost;
        }

        return heightt<b.heightt;
    }
};


building arr[MAXN];
int n;

i64 calc(int pos)
{
    i64 ret=0;

    for(int i=0;i<n;++i)
    {
        ret+=abs(arr[i].heightt-arr[pos].heightt)*arr[i].cost;
    }

    return ret;
}


i64 solve()
{
    int a=0;
    int d=n-1;
    int b,c;

    while(d-a>=3)
    {
        b=(2*a+d)/3;
        c=(2*d+a)/3;

        if(calc(b)>=calc(c))
        {
            a=b;
        }
        else
        {
            d=c;
        }
    }

    i64 ret=calc(a);

    for(int i=a+1;i<=d;++i)
    {
        ret=min(ret,calc(i));
    }

    return ret;
}

int main()
{
    freopen("Text/KOPC12A.txt","r",stdin);

    int cases;
    scanf("%d",&cases);


    while(cases--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",&arr[i].heightt);
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",&arr[i].cost);
        }

        sort(arr,arr+n);

        printf("%lld\n",solve());
    }



    return 0;
}
