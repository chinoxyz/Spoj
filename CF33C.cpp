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

#define MAXN 100005
#define INF 99999999
int arr[MAXN];
int fp[MAXN],fn[MAXN],rp[MAXN],rn[MAXN];

int main()
{
    freopen("Text/CF33C.txt","r",stdin);
    int cases;
    int n;
    int ans;

    scanf("%d",&cases);

    while(cases--)
    {
        ans=-INF;

        scanf("%d",&n);

        for(int i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
            fn[i]=fn[i-1]-arr[i];
            fp[i]=max(fn[i],arr[i]+max(fp[i-1],fn[i-1]));
        }
        arr[n+1]=0;
        rp[n+1]=0;
        rn[n+1]=0;

        for(int i=n;i>0;--i)
        {
            rn[i]=rn[i+1]-arr[i];
            rp[i]=max(rn[i],arr[i]+max(rp[i+1],rn[i+1]));
        }

        for(int i=0;i<=n;++i)
        {
            ans=max(ans,fp[i]+rp[i+1]);
        }

        printf("%d\n",ans);
    }


    return 0;
}
