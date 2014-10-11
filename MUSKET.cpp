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

#define MAXN 102

char arr[MAXN][MAXN];
bool ans[MAXN][MAXN];
int n;

void solve()
{
    int ct=0;

    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=1;k<i;++k)
            {
                int t=(j+k)%n;
                if(ans[j][k] && ans[t][i-k] && (arr[j][t]=='1' || arr[(j+i)%n][t]=='1'))
                {
                    ans[j][i]=true;
                }
            }

            if(i==n && ans[j][i])
            {
                ++ct;
            }
        }
    }

    printf("%d\n",ct);

    for(int i=0;i<n;++i)
    {
        if(ans[i][n])
        {
            printf("%d\n",i+1);
        }
    }
}


int main()
{
    freopen("Text/MUSKET.txt","r",stdin);


    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        MSET(ans,0);
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%s",&arr[i]);
            ans[i][1]=true;
        }

        solve();
    }

    return 0;
}
