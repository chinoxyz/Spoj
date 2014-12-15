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


#define MAXN 3003
const i64 INF64=0x7f7f7f7f7f7f7f7fLL;
const int INF=0x7f7f7f7f;

int arr[MAXN];
i64 dp[MAXN][11];
int n,m;
i64 summ[MAXN];
i64 barr[MAXN][MAXN];

i64 solve(int pos,int c)
{
    if(pos==n)
    {
        return 0;
    }

    if(c==m-1)
    {
        return barr[pos][n-1];
    }

    i64 &ret=dp[pos][c];

    if(ret!=-1)
    {
        return ret;
    }

    ret=barr[pos][n-1];

    for(int i=pos;i<n;++i)
    {
        ret=min(ret,barr[pos][i]+solve(i+1,c+1));
    }

    return ret;
}




int main()
{
    freopen("Text/MAP.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    int ret;
    int i,j,k;
    int midd;

    while(cases--)
    {
        ret=INF;
        MSET(dp,-1);


        scanf("%d %d",&n,&m);

        for(i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        sort(arr,arr+n);


        for(i=1;i<=n;++i)
        {
            summ[i]=summ[i-1]+arr[i-1];
        }

        for(i=0;i<n;++i)
        {
            barr[i][i]=0;

            for(j=i+1;j<n;++j)
            {
                midd=(i+j)>>1;

                barr[i][j]=summ[j+1]-summ[midd+1];
                barr[i][j]-=summ[midd+1]-summ[i];
                if(j-i+1&1)
                {
                    barr[i][j]+=arr[midd];
                }
            }
        }


        ret=solve(0,0);
        printf("%d\n",ret);
    }


    return 0;
}
