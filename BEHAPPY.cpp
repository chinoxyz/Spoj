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

#define MAXM 21
#define MAXX 101

int n,m;
int b[MAXX];
i64 dp[MAXX][MAXX];


i64 solve(int st,int leftt)
{
    if(st>=m && leftt==0)
    {
        return 1;
    }

    if(st>=m)
    {
        return 0;
    }

    if(leftt==0)
    {
        return 1;
    }

    if(dp[st][leftt]!=-1)
    {
        return dp[st][leftt];
    }

    i64 &ret=dp[st][leftt];

    ret=0;

    for(int i=0;i<=min(leftt,b[st]);++i)
    {
        ret+=solve(st+1,leftt-i);
    }

    return ret;
}

int main()
{
    freopen("Text/BEHAPPY.txt","r",stdin);
    int ti;
    i64 ret;

    while(true)
    {
        MSET(dp,-1);
        ret=0;
        scanf("%d %d",&m,&n);

        if(n==0 && m==0)
        {
            break;
        }

        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&ti,b+i);
            n-=ti;
            b[i]-=ti;
        }

        if(n<0)
        {
            ret=0;
        }
        else
        {
            ret=solve(0,n);
        }

        printf("%d\n",ret);
    }


    return 0;
}
