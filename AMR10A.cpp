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

#define MAXN 50005

i64 x[MAXN],y[MAXN];
i64 arr[MAXN];
int n,m;


int main()
{
    freopen("Text/AMR10A.txt","r",stdin);
    int a,b;
    i64 tt,ans,ans2;
    int i;

    scanf("%d %d",&n,&m);
    //cin>>n>>m;

    for(i=1;i<=n;++i)
    {
        scanf("%lld %lld",x+i,y+i);
        //cin>>x[i]>>y[i];
        //printf("%f\t%f\n",x[i],y[i]);

    }
    x[n+1]=x[0];
    y[n+1]=y[0];


    for(i=1;i<=n;++i)
    {
        arr[i]=arr[i-1]+(x[i]*y[i+1]-x[i+1]*y[i]);
        //cout<<arr[i]<<endl;
    }

    tt=abs(arr[n]);


    while(m--)
    {
        scanf("%d %d",&a,&b);
        //cin>>a>>b;
        ans=arr[b]-arr[a];
        ans+=x[b+1]*y[a+1]-x[a+1]*y[b+1];
        ans=abs(ans);
        ans2=tt-ans;
        //printf("A\t%f\t%f\n",ans,ans2);
        ans=min(ans,ans2);
        double ti=ans;
        printf("%.1f\n",ti/2LL);
    }

    return 0;
}
