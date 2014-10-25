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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAX1 10005
#define MAX2 1005
#define INF 99999999

int kmp[MAX2],jumpp[MAX2][26],dp[MAX1][MAX2],len1,len2;
char str1[MAX1],str2[MAX2];
char c;

inline void kmp_preprocess()
{
    int j;
    kmp[0]=kmp[1]=j=0;
    for(int i=2;i<=len2;++i)
    {
        while(j>0 && str2[i]!=str2[j+1])
        {
            j=kmp[j];
        }

        if(str2[i]==str2[j+1])
        {
            ++j;
        }

        kmp[i]=j;
    }
}


inline void solve()
{
    int i,j;

    for(i=0;i<len2;++i)
    {
        for(c='a';c<='z';++c)
        {
            j=i;

            while(j>0 && str2[j+1]!=c)
            {
                j=kmp[j];
            }

            if(str2[j+1]==c)
            {
                ++j;
            }

            jumpp[i][c-'a']=j;
        }
    }


    //MSET(dp,0x7f);

    for(i=0;i<=len1;++i)
    {
        dp[i][len2]=INF;
    }
    for(i=0;i<len2;++i)
    {
        dp[len1][i]=0;
    }

    for(i=len1-1;i;--i)
    {
        for(j=len2-1;j>=0;--j)
        {
            dp[i][j]=min(1+dp[i+1][j],dp[i+1][jumpp[j][str1[i]-'a']]);
        }
    }

    printf("%d\n",dp[1][0]);
}


int main()
{
    freopen("Text/PSTRING.txt","r",stdin);

    while(true)
    {
        if(!gets(&str1[1]))
        {
            break;
        }

        gets(&str2[1]);

        len1=strlen(&str1[1])+1;
        len2=strlen(&str2[1]);

        kmp_preprocess();

        solve();
    }


    return 0;
}
