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


#define INF 1000000004
#define MAXX 100006


int arr[MAXX];
int summ[MAXX];


int main()
{

    freopen("Text/ACPC11C.txt","r",stdin);

    int cases,n;
    int ans;

    scanf("%d",&cases);

    while(cases--)
    {
        ans=INF;
        MSET(arr,0);
        MSET(summ,0);

        scanf("%d",&n);

        for(int i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
            summ[i]=summ[i-1]+arr[i];
        }


        for(int i=1;i<=n;++i)
        {
            ans=min(ans,summ[n]-arr[i] + min(summ[i-1],summ[n]-summ[i]) );
        }

        printf("%d\n",ans);
    }


    return 0;
}
