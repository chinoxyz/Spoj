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
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MODD 10007LL

i64 poww(i64 a,i64 b)
{
    i64 ret=1;
    a%=MODD;

    while(b)
    {
        if(b&1)
        {
            ret*=a;
            ret%=MODD;
        }

        b>>=1;
        a*=a;
        a%=MODD;
    }

    return ret;

}




int main()
{
    freopen("Text/PB.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    i64 n;

    while(cases--)
    {
        scanf("%lld",&n);
        //printf("%lld\n",n);
        printf("%lld\n",poww(n+1,n-1));
    }


    return 0;
}
