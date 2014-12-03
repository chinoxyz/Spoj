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


i64 gcd(i64 a,i64 b)
{
    if(!b)
    {
        return a;
    }

    return gcd(b,a%b);
}


void solve(i64 n,i64 &numm,i64 &denn)
{
    if(n==1)
    {
        numm=denn=1;
    }
    else
    {
        solve(n>>1,numm,denn);
        (n&1)?numm+=denn:denn+=numm;
    }
}



int main()
{
    freopen("Text/NG1FRCTN.txt","r",stdin);

    i64 a,b,d1,d2,n1,n2,g;

    while(true)
    {
        scanf("%lld %lld",&a,&b);
        if(a+b==0)
        {
            break;
        }

        if(a>b)
        {
            swap(a,b);
        }

        solve(a,n1,d1);
        solve(b,n2,d2);
        g=gcd(n1,d2);

        printf("%lld/%lld\n",n1/g,d2/g);
    }



    return 0;
}

