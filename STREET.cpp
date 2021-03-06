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


#define MAXN 502
#define INF 99999999


int dp[MAXN][MAXN];
int heightt[MAXN];

int n,k,t;

int solve(int bpos,int kpos)
{
    if(bpos>n)
    {
        return -INF;
    }

    if(bpos==n || kpos==k)
    {
        return 0;
    }

    if(dp[bpos][kpos]!=-1)
    {
        return dp[bpos][kpos];
    }

    int &ret=dp[bpos][kpos];


    ret=-INF;
    int mn=INF;
    ret=max(ret,solve(bpos+1,kpos));

    for(int i=0;i<t && (bpos+i)<n;++i)
    {
        mn=min(mn,heightt[bpos+i]);
        ret=max(ret,(i+1)*mn+solve(bpos+i+1,kpos+1));
    }

    return ret;
}

int main()
{
    freopen("Text/STREET.txt","r",stdin);

    scanf("%d %d %d",&n,&k,&t);
    MSET(dp,-1);

    for(int i=0;i<n;++i)
    {
        scanf("%d",heightt+i);
    }

    printf("%d\n",solve(0,0));



    return 0;
}
