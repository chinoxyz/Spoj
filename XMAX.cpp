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

#define MAXN 100022

i64 arr[MAXN];
i64 bitt[66];
int n;


int main()
{
    freopen("Text/XMAX.txt","r",stdin);

    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%lld",arr+i);
    }

    for(int i=0;i<n;++i)
    {
        for(int j=62;j>=0;--j)
        {
            if(!(arr[i]&(1LL<<j)))
            {
                continue;
            }

            if(bitt[j])
            {
                arr[i]^=bitt[j];
            }
            else
            {
                bitt[j]=arr[i];
                break;
            }
        }
    }

    i64 ans=0;

    for(int i=62;i>=0;--i)
    {
        if(ans&(1LL<<i))
        {
            continue;
        }

        ans^=bitt[i];
    }

    printf("%lld\n",ans);


    return 0;
}

