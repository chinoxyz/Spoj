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


#define MAXK 10
#define MAXM 20
#define MAXN 100
#define INF 99999999999999LL


i64 k,m,r,n;
i64 locs[MAXM][2];
i64 sols[MAXN][3];

bitset<MAXN> covers[MAXM];

i64 dist(i64 x1,i64 y1,i64 x2,i64 y2)
{
    return pow(x1-x2,2)+pow(y1-y2,2);
}


i64 calc(int maskk)
{
    bitset<MAXN> ans;

    for(int i=0;i<m;++i)
    {
        if(maskk &(1<<i))
        {
            ans|=covers[i];
        }
    }

    i64 ret=0;

    for(int i=0;i<n;++i)
    {
        if(ans.test(i))
        {
            ret+=sols[i][2];
        }
    }

    return ret;
}

void solve()
{

    i64 ret=0;

    unsigned int st=(1ull<<k)-1;
    unsigned int en=st<<(m-k);

    while(st!=en)
    {
        ret=max(ret,calc(st));

        unsigned int t = (st | (st - 1)) + 1;
        st = t | ((((t & -t) / (st & -st)) >> 1) - 1);
    }

    ret=max(ret,calc(st));

    printf("%lld\n",ret);

}


int main()
{
    freopen("Text/PIZZALOC.txt","r",stdin);

    scanf("%lld %lld",&k,&r);
    r*=r;

    scanf("%lld",&m);

    for(int i=0;i<m;++i)
    {
        scanf("%lld %lld",&locs[i][0],&locs[i][1]);
    }

    scanf("%lld",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%lld %lld %lld",&sols[i][0],&sols[i][1],&sols[i][2]);

        for(int j=0;j<m;++j)
        {
            if(r>=dist(sols[i][0],sols[i][1],locs[j][0],locs[j][1]))
            {
                covers[j].set(i);
            }
        }
    }

    solve();


    return 0;
}
