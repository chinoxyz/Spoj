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

#define MAXN 11
#define MAXM 46000

int interestt[MAXN],costt[MAXN],dp[MAXM];
int n,m;

int main()
{
    freopen("Text/MINVEST.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int years;
    int ti;

    while(cases--)
    {
        MSET(dp,0);
        scanf("%d %d",&n,&years);

        scanf("%d",&m);

        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&costt[i],&interestt[i]);
            costt[i]/=1000;
        }



        for(int i=0;i<MAXM;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(i-costt[j]>=0)
                {
                    ti=interestt[j]+dp[i-costt[j]];
                    dp[i]=max(dp[i],ti);
                }
            }
        }

        for(int i=0;i<years;++i)
        {
            n+=dp[n/1000];
        }

        printf("%d\n",n);
    }


    return 0;
}
