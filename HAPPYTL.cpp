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

#define MAXN 10001
#define MAXM 101

int x[MAXN],y[MAXN],st[MAXN],en[MAXN];




int main()
{
    freopen("Text/HAPPYTL.txt","r",stdin);

    int n,m,u,v;
    int ans;

    while(true)
    {
        scanf("%d %d",&n,&m);

        if(n+m==0)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d %d %d %d",x+i,y+i,st+i,en+i);
            en[i]+=st[i];
        }


        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&u,&v);
            v+=u;
            ans=0;

            for(int j=0;j<n;++j)
            {
                if(st[j]<=u && en[j]>u || st[j]<v && en[j]>=v || st[j]>=u && en[j]<=v)
                {
                    ++ans;
                }
            }

            printf("%d\n",ans);
        }
    }



    return 0;
}
