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

#define INF 999999999999999LL

#define MAXX 100001
#define MAXN 10001

int n;

i64 allx,ally;

i64 cumx[MAXX],cumy[MAXX],cntx[MAXX],cnty[MAXX],ans,arr[MAXN][2];

i64 solvex(int pos)
{
    i64 ret=0;

    ret+=allx;
    ret-=n*arr[pos][0];
    ret+=2*arr[pos][0]*cntx[arr[pos][0]];
    ret-=2*cumx[arr[pos][0]];
    return ret;
}


i64 solvey(int pos)
{
    i64 ret=0;

    ret+=ally;
    ret-=n*arr[pos][1];
    ret+=2*arr[pos][1]*cnty[arr[pos][1]];
    ret-=2*cumy[arr[pos][1]];
    return ret;
}


int main()
{
    freopen("Text/PLONK.txt","r",stdin);

    int cases;
    i64 ret;

    scanf("%d",&cases);


    while(cases--)
    {
        scanf("%d",&n);
        MSET(cumx,0);
        MSET(cumy,0);
        MSET(cntx,0);
        MSET(cnty,0);
        ans=INF;
        allx=ally=0;

        for(int i=0;i<n;++i)
        {
            scanf("%d %d",&arr[i][0],&arr[i][1]);
            ++cntx[arr[i][0]];
            ++cnty[arr[i][1]];
            cumx[arr[i][0]]+=arr[i][0];
            cumy[arr[i][1]]+=arr[i][1];
            allx+=arr[i][0];
            ally+=arr[i][1];
        }

        for(int i=1;i<MAXX;++i)
        {
            cumx[i]+=cumx[i-1];
            cumy[i]+=cumy[i-1];

            cntx[i]+=cntx[i-1];
            cnty[i]+=cnty[i-1];
        }

        for(int i=0;i<n;++i)
        {
            ret=solvex(i);
            ret+=solvey(i);

            ans=min(ans,ret);
        }

        printf("%lld\n",ans);

    }



    return 0;
}
