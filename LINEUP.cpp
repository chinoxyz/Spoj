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


#define INF 99999

int arr[11][11];
int dp[1<<11];

int solve(int maskk)
{
    int idx=__builtin_popcount(maskk);

    if(idx==11)
    {
        return 0;
    }

    if(dp[maskk]!=-1)
    {
        return dp[maskk];
    }

    int &ret=dp[maskk];

    ret=-INF;

    for(int i=0;i<11;++i)
    {
        if((maskk&(1<<i))==0)
        {
            ret=max(ret,arr[i][idx]+solve(maskk|(1<<i)));
        }
    }

    return ret;

}

int main()
{
    freopen("Text/LINEUP.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        MSET(dp,-1);
        for(int i=0;i<11;++i)
        {
            for(int j=0;j<11;++j)
            {
                scanf("%d",&arr[i][j]);

                if(arr[i][j]==0)
                {
                    arr[i][j]=-INF;
                }
            }
        }

        printf("%d\n",solve(0));
    }





    return 0;
}
