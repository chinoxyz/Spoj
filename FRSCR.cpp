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


int n,m,p;

int a[2][999];
int x,ti;
int ans,lo,hi,midd,ti1,ti2;
int ret;

int calc(int v,int idx,int n)
{
    ret=0;


    for(int i=0;i<n;++i)
    {
        x=a[idx][i];
        ti=(sqrt(x*x+8*x*v)-x)/(2.0*x);

        ret+=ti;
    }

    return ret;
}
void solve()
{
    ans=0;

    lo=0;
    hi=p;

    while(lo<hi)
    {
        //printf("DD\t%d\t%d\n",lo,hi);
        midd=(lo+hi)>>1;

        ti1=calc(midd,0,n);
        ti2=calc(p-midd,1,m);

        if(ti1>ti2)
        {
            hi=midd;
        }
        else
        {
            ans=max(ans,ti1);
            if(ti1==ti2)
            {
                break;
            }
            lo=midd+1;
        }

    }

    printf("%d\n",ans);
}


int main()
{
    freopen("Text/FRSCR.txt","r",stdin);

    int cases;
    int i;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&p);
        scanf("%d %d",&n,&m);

        for(i=0;i<n;++i)
        {
            scanf("%d",&a[0][i]);
        }

        for(i=0;i<m;++i)
        {
            scanf("%d",&a[1][i]);
        }

        solve();
    }


    return 0;
}

