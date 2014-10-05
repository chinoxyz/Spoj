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

#define MAXX 52

u64 gr[MAXX][MAXX],ans;
int n,dest,k,src;
u64 unit[MAXX][MAXX];
u64 res[MAXX][MAXX];
u64 ret[MAXX][MAXX];

void mul(u64 a[MAXX][MAXX],u64 b[MAXX][MAXX])
{
    MSET(res,0);

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                res[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            a[i][j]=res[i][j];
        }
    }
}


void solve()
{
    memcpy(ret,unit,sizeof(unit));

    while(k)
    {
        if(k&1)
        {
            mul(ret,gr);
        }

        mul(gr,gr);
        k>>=1;
    }
}

int main() {

	freopen("Text/TEMPTISL.txt","r",stdin);

	for(int i=0;i<MAXX;++i)
    {
        unit[i][i]=1;
    }

	while(true)
    {
        scanf("%d %d",&n,&k);

        if(n==-1 && k==-1)
        {
            break;
        }
        ans=0;

        scanf("%d %d",&src,&dest);
        --src;
        --dest;

        MSET(gr,0);

        for(int i=0;i<n;++i)
        {
            gr[i][(i+1)%n]=1;
            gr[(i+1)%n][i]=1;
        }

        solve();

        ans=ret[src][dest];

        printf("%llu\n",ans);
    }

	return 0;
}
