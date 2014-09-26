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

#define MAXN 100002

i64 arr[MAXN];
i64 s1[MAXN];
i64 s2[MAXN];

int main(){

    freopen("Text/PAIRSUM.txt","r",stdin);

    int n,m,x,y;
    i64 ans;

    scanf("%d",&n);

    scanf("%lld",&arr[0]);
    s1[0]=arr[0];
    s2[0]=arr[0]*arr[0];
    for(int i=1;i<n;++i)
    {
        scanf("%lld",arr+i);
        s1[i]=s1[i-1]+arr[i];
        s2[i]=s2[i-1]+s1[i]*arr[i];
    }

    scanf("%d",&m);

    while(m--)
    {
        scanf("%d %d",&x,&y);
        ans=s2[y];
        if(x>0)
        {
            ans-=((s1[x-1])*(s1[y]-s1[x-1]));
            ans-=s2[x-1];
        }

        printf("%lld\n",ans);
    }

    return 0;
}
