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

#define MAXN 101

int n,m,dp[MAXN][MAXN][MAXN];


int main()
{
    freopen("Text/STEVE.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&m);

        dp[0][0][0]=0;
        dp[1][0][0]=dp[1][1][0]=1;

        for(int ct=2;ct<=n;++ct)
        {
            for(int i=0;i<=n;++i)
            {
                dp[ct][i][ct-i]=dp[i][0][0];
            }

            for(int tot=ct-1;tot>=0;--tot)
            {
                for(int x=0;x<=tot;++x)
                {
                    int y=tot-x;
                    int ret=0;

                    if(ct-x-y<=m)
                    {
                        ret=ct-dp[y][0][0];
                    }

                    if(ct-x-y>1)
                    {
                        for(int i=1;i<=min(ct-x-y-1,m);++i)
                        {
                            int ans=MAXN;

                            for(int j=1;j<=min(ct-x-y-i,m);++j)
                            {
                                ans=min(ans,dp[ct][x+i][y+j]);
                            }

                            ret=max(ret,ans);
                        }
                    }

                    dp[ct][x][y]=ret;
                }
            }
        }

        printf("%d\n",dp[n][0][0]);
    }




    return 0;
}

