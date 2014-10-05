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


#define MAXN 12
int ans[MAXN][MAXN];

void pree()
{
    ans[1][1]=1;
    ans[0][0]=1;

    for(int i=2;i<MAXN;++i)
    {
        for(int j=1;j<MAXN;++j)
        {
            ans[i][j]+=ans[i-1][j-1];
            for(int k=j;k<MAXN;++k)
            {
                //printf("DD\n");
                ans[i][k]+=ans[i-1][k];
            }
        }
    }


    for(int i=1;i<MAXN;++i)
    {
        for(int j=1;j<i;++j)
        {
            ans[i][i]+=ans[i][j];
        }
    }
}


int main()
{
    freopen("Text/NOVICE43.txt","r",stdin);

    pree();

    int cases,n;
    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n][n]);
    }


    return 0;
}
