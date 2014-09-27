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


const i64 MODD=761238923LL;

#define MAXN 102

i64 arr[MAXN][MAXN];
i64 ans[MAXN];


void pre_process()
{
    arr[0][0]=1;
    arr[1][1]=1;

    for(int i=2;i<MAXN;++i)
    {
        for(int j=0;j<=i;++j)
        {
            for(int k=0;k<=j;++k)
            {
                arr[i][j]+=arr[i-1][j-k];
                arr[i][j]%=MODD;
            }
        }
    }


    for(int i=1;i<MAXN;++i)
    {
        for(int j=0;j<=i;++j)
        {
            ans[i]+=arr[i][j];
            ans[i]%=MODD;
        }
    }
}

int main()
{
    freopen("Text/QCJ2.txt","r",stdin);

    pre_process();
    int n;

    while(true)
    {
        scanf("%d",&n);

        if(n==0)
        {
            break;
        }

        printf("%lld\n",ans[n]);


    }

    return 0;
}
