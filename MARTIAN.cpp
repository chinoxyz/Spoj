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

#define MAXX 502
int n,m;

i64 ans[MAXX][MAXX];
i64 data1[MAXX][MAXX];
i64 data2[MAXX][MAXX];
i64 row1[MAXX][MAXX];
i64 col1[MAXX][MAXX];
i64 row2[MAXX][MAXX];
i64 col2[MAXX][MAXX];
i64 bestt;
i64 all_sum1,all_sum2;


int main() {

    freopen("Text/MARTIAN.txt","r",stdin);


    while(true)
    {
        scanf("%d %d",&n,&m);

        if(n==0 || m==0)
        {
            break;
        }

        bestt=0;
        MSET(ans,0);
        MSET(data1,0);
        MSET(data2,0);
        MSET(row1,0);
        MSET(col1,0);
        MSET(row2,0);
        MSET(col2,0);
        all_sum1=0;
        all_sum2=0;

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%lld",&data1[i][j]);
                all_sum1+=data1[i][j];
                row1[i][j]+=row1[i][j-1]+data1[i][j];
                col1[i][j]+=col1[i-1][j]+data1[i][j];
            }
        }

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%lld",&data2[i][j]);
                all_sum2+=data2[i][j];
                row2[i][j]+=row2[i][j-1]+data2[i][j];
                col2[i][j]+=col2[i-1][j]+data2[i][j];
            }
        }

        bestt=max(all_sum1,all_sum2);




        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                ans[i][j]=max(ans[i][j-1]+col2[i][j],ans[i-1][j]+row1[i][j]);
                bestt=max(bestt,ans[i][j]);
            }
        }

        printf("%lld\n",bestt);
    }


    return 0;
}
