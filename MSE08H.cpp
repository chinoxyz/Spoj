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


#define MODD 1000000007LL
#define MAXN 1001

i64 ephi(i64 numm)
{
    i64 ret=1;

    for(i64 i=2;i*i<=numm;++i)
    {
        if(numm%i==0)
        {
            numm/=i;
            ret*=(i-1);

            while(numm%i==0)
            {
                numm/=i;
                ret*=i;
            }
        }
    }

    if(numm>1)
    {
        ret*=(numm-1);
    }

    return (ret%MODD);
}

i64 arr[MAXN];

int main()
{
    freopen("Text/MSE08H.txt","r",stdin);
    int n;
    i64 ret;


    while(scanf("%d",&n)!=EOF)
    {
        ret=1;
        for(int i=0;i<n;++i)
        {
            scanf("%lld",arr+i);
            ret*=ephi(arr[i]);
            ret%=MODD;
        }

        printf("%lld\n",ret);

    }


    return 0;
}
