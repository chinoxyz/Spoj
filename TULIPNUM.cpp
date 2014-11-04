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


#define MAXN 100002

int arr[MAXN];
int dp[MAXN];
int dp2[MAXN];


int main()
{
    freopen("Text/TULIPNUM.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    int n,q,x,y;
    int i;
    dp[1]=1;
    dp2[1]=1;

    for(int t=1;t<=cases;++t)
    {
        getchar();
        scanf("%d %d",&n,&q);
        scanf("%d",arr+1);

        for(i=2;i<=n;++i)
        {
            scanf("%d",arr+i);
            if(arr[i]==arr[i-1])
            {
                dp[i]=dp[i-1];
                dp2[i]=dp2[i-1];
            }
            else
            {
                dp[i]=1+dp[i-1];
                dp2[i]=i;
            }
        }

        printf("Case %d:\n",t);

        while(q--)
        {
            scanf("%d %d",&x,&y);

            printf("%d\n",dp[y]-dp[dp2[x]-1]);
        }
    }



    return 0;
}

