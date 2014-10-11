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

#define MAXN 2001

#define INF 99999999

int arr[MAXN];

int dp[MAXN][MAXN];
int n;

int solvemx(int pos,int prevv);
int solvemy(int pos,int prevv);



inline int solvemy(int pos,int prevv)
{
    if(pos==n)
    {
        return 0;
    }

    if(dp[pos][prevv]!=-1)
    {
        return dp[pos][prevv];
    }

    int &ret=dp[pos][prevv];

    ret=INF;

    int mx=prevv<<1;

    for(int i=1;i<=mx && pos+i<=n;++i)
    {
        ret=min(ret,solvemx(pos+i,i));
    }

    return ret;
}


inline int solve(int pos,int mx)
{
    if(pos==n)
    {
        return 0;
    }

    if(mx+pos>n)
    {
        return solve(pos,n-pos);
    }

    if(dp[pos][mx]!=-1)
    {
        return dp[pos][mx];
    }

    int &ret=dp[pos][mx];
    ret=0;

    if(mx==1)
    {
        ret=arr[pos]-solve(pos+1,2);
        return ret;
    }



    ret=max(solve(pos,mx-1),arr[pos]-solve(pos+mx,2*mx));

    return ret;
}


//#define gc getchar_unlocked
#define gc getchar

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}


int main()
{
    freopen("Text/XOINC.txt","r",stdin);

    MSET(dp,-1);

    n=readPosInt();

    for(int i=0;i<n;++i)
    {
        arr[i]=readPosInt();
    }

    for(int i=n-2;i>=0;--i)
    {
        arr[i]+=arr[i+1];
    }

    printf("%d\n",solve(0,2));



    return 0;
}
