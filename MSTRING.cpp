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

#define MAXN 1005
#define INF 9999999

char str1[MAXN],str2[MAXN];
int l1,l2,dp[MAXN][MAXN];

int solve(int x,int y)
{
    if(x==l1)
    {
        return INF;
    }

    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }

    int &ret=dp[x][y];
    ret=solve(x+1,y);
    for(int i=y;i<l2;++i)
    {
        if(str1[x]==str2[i])
        {
            ret=min(ret,1+solve(x+1,i+1));
            return ret;

        }
    }

    ret=1;

    return ret;
}




int main()
{
    freopen("Text/MSTRING.txt","r",stdin);

    scanf("%s %s",str1,str2);
    l1=strlen(str1);
    l2=strlen(str2);
    MSET(dp,-1);
    printf("%d\n",solve(0,0));



    return 0;
}
