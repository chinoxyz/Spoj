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


#define MAXN 63

i64 dp[MAXN][2][MAXN][MAXN];
char arr[3][MAXN];
int lenn[3];

i64 solve()
{
    i64 ret=0;

    for(int i=0;i<=lenn[0];++i)
    {
        for(int j=0;j<=lenn[1];++j)
        {
            if(arr[0][i]==arr[2][lenn[2]-1])
            {
                dp[lenn[2]-1][0][i][j]=1;
            }

            if(arr[1][j]==arr[2][lenn[2]-1])
            {
                dp[lenn[2]-1][1][i][j]=1;
            }
        }
    }

    for(int i=lenn[2]-2;i>=0;--i)
    {
        for(int j=lenn[0];j>=0;--j)
        {
            for(int k=lenn[1];k>=0;--k)
            {
                if(arr[2][i]==arr[0][j])
                {
                    int ti=0;
                    for(int l=j+1;l<lenn[0];++l)
                    {
                        ti+=dp[i+1][0][l][k];
                    }

                    for(int l=k;l<lenn[1];++l)
                    {
                        ti+=dp[i+1][1][j+1][l];
                    }
                    dp[i][0][j][k]=ti;
                }

                if(arr[2][i]==arr[1][k])
                {
                    int ti=0;

                    for(int l=j;l<lenn[0];++l)
                    {
                        ti+=dp[i+1][0][l][k+1];
                    }

                    for(int l=k+1;l<lenn[1];++l)
                    {
                        ti+=dp[i+1][1][j][l];
                    }

                    dp[i][1][j][k]=ti;
                }
            }
        }
    }

    for(int i=0;i<lenn[0];++i)
    {
        ret+=dp[0][0][i][0];
    }

    for(int i=0;i<lenn[1];++i)
    {
        ret+=dp[0][1][0][i];
    }

    return ret;
}



int main()
{
    freopen("Text/SSHUFFLE.txt","r",stdin);

    int cases;
    scanf("%d",&cases);

    while(cases--)
    {
        for(int i=0;i<3;++i)
        {
            scanf("%s",&arr[i]);
            lenn[i]=strlen(arr[i]);
            //printf("%s\t%d\n",arr[i],lenn[i]);
        }

        MSET(dp,0);

        printf("%lld\n",solve());
    }



    return 0;
}

