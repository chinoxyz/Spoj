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



#define MAXN 62


u64 n;

u64 ncr[MAXN][MAXN];


void pre_calc()
{
    for(int i=1;i<MAXN;++i)
    {
        ncr[i][0]=1;
        ncr[i][i]=1;
    }

    for(int i=1;i<MAXN;++i)
    {
        for(int j=1;j<i;++j)
        {
            ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
            //printf("%llu\n",ncr[i][j]);
        }
    }
}

u64 ans[MAXN];


int main()
{
    pre_calc();

    freopen("Text/NOVICE63.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    ans[0]=0;
    ans[1]=1;

    for(int i=2;i<MAXN;++i)
    {
        ans[i]+=ans[i-1];

        if(i&1)
        {
            ans[i]+=ncr[i][i/2];
        }

    }



    while(cases--)
    {
        scanf("%llu",&n);

        int x=(int)log2(n);

        u64 ret=ans[x-1];

        if(x==1)
        {
            ret=1;
        }

        printf("%llu\n",ret);
    }

    return 0;
}
