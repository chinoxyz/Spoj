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

#define MAXL 1005


int main()
{
    freopen("Text/UOFTBB.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    int l,n;
    vector<i64>::iterator it;

    int c,r,d,m,ti;


    while(cases--)
    {
        scanf("%d %d",&l,&n);

        vector<i64> dp(l,0);

        for(int i=0;i<n;++i)
        {
            scanf("%d %d %d",&c,&r,&d);
            --c;

            for(int i=max(0,c-r);i<=min(l-1,c+r);++i)
            {
                dp[i]+=d;
            }
        }

        for(int i=1;i<l;++i)
        {
            dp[i]+=dp[i-1];
        }

        scanf("%d",&m);

        for(int i=0;i<m;++i)
        {
            scanf("%d",&ti);
            it=lower_bound(dp.begin(),dp.end(),ti);

            if(it==dp.end())
            {
                printf("Bloon leakage\n");
            }
            else
            {
                printf("%d\n",it-dp.begin()+1);
            }
        }
    }

    return 0;
}
