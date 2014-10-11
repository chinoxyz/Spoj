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

#define MAXN 552
#define MAXK 3302
long double dp[MAXN][MAXK]={0};
int n,k;


void pree()
{
    for(int i=1;i<=6;++i)
    {
        dp[1][i]=1.0/6.0;
    }

    for(int i=2;i<MAXN;++i)
    {
        for(int j=i;j<MAXK;++j)
        {
            for(int l=1;l<=6;++l)
            {
                if(j-l>0)
                {
                    dp[i][j]+=dp[i-1][j-l]/6.0;
                }
            }
        }
    }

}

int main()
{
    freopen("Text/AE2A.txt","r",stdin);

    pree();

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&k);

        if(n<MAXN && k<MAXK)
        {
            printf("%d\n",(int)(100*dp[n][k]));
        }
        else
        {
            printf("0\n");
        }
    }

    return 0;
}
