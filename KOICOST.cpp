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
#define MODD 1000000000LL

int par[MAXN];
PIPII arr[MAXN];
int n,m;
i64 summ[MAXN];
i64 sz[MAXN];

int get_par(int x)
{
    if(x!=par[x])
    {
        par[x]=get_par(par[x]);
    }

    return par[x];
}

i64 dp[MAXN];



int main()
{
    freopen("Text/KOICOST.txt","r",stdin);

    scanf("%d %d",&n,&m);

    for(int i=0;i<m;++i)
    {
        scanf("%d %d %d",&arr[i].second.first,&arr[i].second.second,&arr[i].first);
    }

    sort(arr,arr+m);

    i64 ans=0;
    int x,y,px,py;

    summ[0]=arr[0].first;

    for(int i=1;i<=n;++i)
    {
        par[i]=i;
        sz[i]=1;
    }

    for(int i=1;i<m;++i)
    {
        summ[i]=summ[i-1]+arr[i].first;
    }

    for(int i=m-1;i>=0;--i)
    {
        x=arr[i].second.first;
        y=arr[i].second.second;
        px=get_par(x);
        py=get_par(y);

        if(px==py)
        {
            dp[i]=0;
        }
        else
        {
            dp[i]=(sz[px]*sz[py])%MODD;
            sz[px]+=sz[py];
            par[py]=px;
        }

        ans+=(dp[i]*summ[i])%MODD;
        ans%=MODD;
    }

    printf("%lld\n",ans);

    return 0;
}
