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



#define MAXN 205
#define INF 999999999


int n;
int arr[MAXN];
int dp[MAXN][MAXN][MAXN];


int solve(int idx,int w,int b)
{

    if(idx==n)
    {
        return 0;
    }

    if(dp[idx][w][b]!=-1)
    {
        return dp[idx][w][b];
    }

    int &ret=dp[idx][w][b];

    if(arr[idx]<arr[b])
    {
        ret=solve(idx+1,w,idx);
    }

    if(arr[idx]>arr[w])
    {
        if(ret==-1)
        {
            ret=solve(idx+1,idx,b);
        }
        else
        {
            ret=min(ret,solve(idx+1,idx,b));
        }
    }

    if(ret==-1)
    {
        ret=1+solve(idx+1,w,b);
    }
    else
    {
        ret=min(ret,1+solve(idx+1,w,b));
    }

    return ret;
}


int main()
{
    freopen("Text/BORW.txt","r",stdin);


    while(true)
    {
        scanf("%d",&n);
        if(n==-1)
        {
            break;
        }

        arr[0]=-INF;
        arr[1]=INF;
        n+=2;

        for(int i=2;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        MSET(dp,-1);

        int ret=solve(2,0,1);

        printf("%d\n",ret);
    }


    return 0;
}
