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

i64 n;

i64 gcd(i64 a,i64 b)
{
    if(b==0LL)
    {
        return a;
    }

    return gcd(b,a%b);
}

i64 summ(i64 ti)
{
    return ti*(ti+1)/2LL;
}


i64 c1()
{
    i64 ret=0LL;
    i64 tn=3LL*n;

    ret+=2LL*summ(((tn+1LL)>>1LL));

    if(!((tn+1LL)&1LL))
    {
        ret-=((tn+1LL)>>1LL);
    }

    ret-=2*summ(((tn-n)>>1LL));

    //printf("C1\t%lld\n",ret);

    return ret;
}


i64 c2()
{
    i64 ret=0LL;

    if(n>1LL)
    {
        ret=summ((n-1LL)>>1LL);
        ret*=2LL;

        if(n&1LL)
        {
            ret-=(((n-1LL)>>1LL));
        }
    }



    return ret;
}


i64 solve()
{
    i64 ret=c1();
    ret+=c2();

    return ret;
}


int main()
{
    freopen("Text/APPROB.txt","r",stdin);

    int cases;
    i64 numm,denn,g;
    scanf("%d",&cases);


    while(cases--)
    {
        scanf("%lld",&n);
        numm=solve();
        denn=n*n*n*6LL;
        g=gcd(numm,denn);
        printf("%lld/%lld\n",numm/g,denn/g);
    }


    return 0;
}
