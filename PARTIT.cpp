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


#define MAXM 222
#define MAXN 12

i64 dp[MAXM][MAXN][MAXM];




void init()
{
    MSET(dp,0);

    for(int i=1;i<=220;++i)
    {
        dp[i][1][i]=1LL;
    }

    for(int i=2;i<=10;++i)
    {
        for(int j=i;j<=220;++j)
        {
            for(int k=1;k<=j;++k)
            {
                for(int l=k;l<=220;++l)
                {
                    dp[j][i][k]+=dp[j-k][i-1][l];
                }
            }
        }
    }

}

void solve(int m,int n,i64 k,int lastt)
{
    if(n<=0)
    {
        return;
    }

    i64 summ=0;
    int ti=lastt;

    while(summ<k)
    {
        //printf("DD\n");
        summ+=dp[m][n][ti];
        if(summ>=k)
        {
            break;
        }
        ++ti;
    }

    if(summ>0)
    {
        summ-=dp[m][n][ti];
    }
    printf("%d ",ti);
    solve(m-ti,n-1,k-summ,ti);


}


int main() {

    freopen("Text/PARTIT.txt","r",stdin);

    int cases;
    int n,m;
    i64 k;

    init();


    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %lld",&m,&n,&k);
        //printf("%d\t%d\t%lld\n",m,n,k);
        solve(m,n,k,1);
        printf("\n");
    }

    return 0;
}
