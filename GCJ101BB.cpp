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

#define MAXN 55

int pos[MAXN];
int sp[MAXN];

int main()
{
    freopen("Text/GCJ101BB.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int i,ans,x,y,n,b,k,t;
    int ti;

    for(int tt=1;tt<=cases;++tt)
    {
        scanf("%d %d %d %d",&n,&k,&b,&t);

        x=y=0;

        for(i=0;i<n;++i)
        {
            scanf("%d",pos+i);
        }

        for(i=0;i<n;++i)
        {
            scanf("%d",sp+i);
        }

        i=n-1;
        ans=0;

        while(i>=0 && x<k)
        {
            ti=pos[i]+sp[i]*t;
            if(ti<b)
            {
                ++y;
            }
            else
            {
                ++x;
                ans+=y;
            }
            --i;
        }

        if(x==k)
        {
            printf("Case #%d: %d\n",tt,ans);
        }
        else
        {
            printf("Case #%d: IMPOSSIBLE\n",tt);
        }

    }


    return 0;
}
