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


#define MODD 1000000007LL
i64 n;


i64 poww(i64 x,i64 p)
{
    i64 ret=1;

    while(p)
    {
        if(p&1)
        {
            ret*=x;
            ret%=MODD;
        }

        p>>=1;
        x*=x;
        x%=MODD;
    }

    return ret;
}

int main()
{
    freopen("Text/LOCKER.txt","r",stdin);

    int cases;
    i64 n,ans;

    scanf("%d",&cases);


    while(cases--)
    {
        scanf("%lld",&n);

        if(n<=4)
        {
            printf("%d\n",n);
        }
        else
        {
            if(n%3==0)
            {
                ans=poww(3,n/3);
            }
            else if(n%3==1)
            {
                ans=(4*poww(3,(n-4)/3))%MODD;
            }
            else
            {
                ans=(2*poww(3,(n-2)/3))%MODD;
            }

            printf("%lld\n",ans);
        }
    }



    return 0;
}
