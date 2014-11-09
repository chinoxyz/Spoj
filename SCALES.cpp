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

#define MAXN 1000009

int n,l,d;
char s[MAXN];
int dp[MAXN][2];


void solve()
{
    dp[0][0]=1;

    for(int i=0;i<n;++i)
    {
        for(int c=0;c<2;++c)
        {
            if(!c && s[i]=='0')
            {
                dp[i+1][0]+=dp[i][0];
                dp[i+1][0]%=d;
            }
            else if(!c && s[i]=='1')
            {
                dp[i+1][0]+=dp[i][0];
                dp[i+1][1]+=dp[i][0];

                dp[i+1][0]%=d;
                dp[i+1][1]%=d;
            }
            else if(c && s[i]=='0')
            {
                dp[i+1][1]+=dp[i][1];
                dp[i+1][0]+=dp[i][1];

                dp[i+1][0]%=d;
                dp[i+1][1]%=d;
            }
            else
            {
                dp[i+1][1]+=dp[i][1];
                dp[i+1][1]%=d;
            }
        }
    }

    printf("%d\n",dp[n][0]);
}



int main()
{
    freopen("Text/SCALES.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        MSET(dp,0);
        scanf("%d %d %d",&n,&l,&d);
        scanf("%s",s);

        for(int i=0;i<l/2;++i)
        {
            swap(s[i],s[l-i-1]);
        }

        for(int i=l;i<=n;++i)
        {
            s[i]='0';
        }
        solve();
    }

    return 0;
}
