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

const i64 MODD=1000000007LL;

i64 a,b,c;


i64 poww(i64 x,i64 y,i64 MODD)
{
    if(x==0LL && y==0LL)
    {
        return 1LL;
    }
    i64 ret=1;

    while(y)
    {
        if(y&1LL)
        {
            ret*=x;
            ret%=MODD;
        }
        x*=x;
        x%=MODD;
        y>>=1;
    }


    return ret;
}


int main()
{
    freopen("Text/POWERUP.txt","r",stdin);

    while(true)
    {
        scanf("%lld %lld %lld",&a,&b,&c);

        if(a==-1LL && b==-1LL && c==-1LL)
        {
            break;
        }
        a%=MODD;
        b%=MODD;
        c%=MODD;

        i64 ti=poww(b,c,MODD-1LL);
        ti%=(MODD-1LL);
        //ti=max(ti,1LL);
        i64 ans=poww(a,ti,MODD);

        if(a==0LL)
        {
            if(ti==0LL)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            ans%=MODD;
            printf("%lld\n",ans);
        }
    }


    return 0;
}
