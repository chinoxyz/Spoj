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


#define MAXN 1000001
int ans[MAXN],up[MAXN],lo[MAXN];

void pre_comp()
{
    up[2]=lo[2]=1;
    ans[1]=1;
    ans[2]=2;

    for(int i=3;i<MAXN;++i)
    {
        lo[i]=(ans[i-2]+up[i-1])%100000;
        up[i]=(ans[i-2]+lo[i-1])%100000;
        ans[i]=(ans[i-1]+ans[i-2]+up[i-1]+lo[i-1])%100000;
    }
}

int main()
{
    freopen("Text/BYTESH1.txt","r",stdin);

    pre_comp();

    int cases,n;

    scanf("%d\n",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]%10000);
    }


    return 0;
}
