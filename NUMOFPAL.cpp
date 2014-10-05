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

i64 ans=0;

char arr[1005];
int len;

bool dp[1005][1005];

int main() {

	freopen("Text/NUMOFPAL.txt","r",stdin);

	scanf("%s",arr);

	len=strlen(arr);

	if(len==1)
    {
        ans=1;
    }
    else
    {
        ans+=len;
        for(int i=0;i<len;++i)
        {
            dp[i][i]=1;
        }

        for(int i=0;i<len-1;++i)
        {
            if(arr[i]==arr[i+1])
            {
                dp[i][i+1]=1;
                ++ans;
            }
        }

        for(int i=3;i<=len;++i)
        {
            for(int j=0;j<=len-i;++j)
            {
                if(arr[j]==arr[j+i-1] && dp[j+1][j+i-2])
                {
                    dp[j][j+i-1]=1;
                    ++ans;
                }
            }
        }
    }

    printf("%lld\n",ans);

	return 0;
}
