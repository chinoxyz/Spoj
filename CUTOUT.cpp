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



#define MAXN 202
#define MAXD 40001
#define X1 first
#define Y1 second.first
#define X2 second.second.first
#define Y2 second.second.second

int n,r;
PIPIPII points[MAXN];
int ys[MAXN];
PII xs[MAXN];
int ct;
i64 ans;
int lenn;

bool intersects(int a,int b,int c)
{
    if(points[c].Y1 <=ys[a] && points[c].Y2>ys[a])
    {
        return 1;
    }

    if(points[c].Y1<ys[b] && points[c].Y2>=ys[b])
    {
        return 1;
    }

    if(points[c].Y1>=ys[a] && points[c].Y2<=ys[b])
    {
        return 1;
    }

    return 0;
}


void solve(int downn,int upp)
{
    xs[0].first=0;
    xs[0].second=0;
    xs[ct-1].first=n;
    xs[ct-1].second=-n;

    int mx=-1;
    i64 h=ys[upp]-ys[downn];
    //printf("%lld\n",h);
    for(int i=0;i<ct-1;++i)
    {
        //printf("DD\t%d\t%d\n",xs[i].first,xs[i+1].first);
        if( (-xs[i].second)< xs[i+1].first && -xs[i].second>=mx)
        {

            i64 ti=h*(xs[i+1].first+xs[i].second);
            //printf("TI\t%lld\t%d\t%d\t%d\t%d\n",ti,ys[downn],ys[upp],xs[i].second,xs[i+1].first);
            ans=max(ans,ti);
            mx=max(mx,-xs[i+1].second);
        }
        mx=max(mx,-xs[i].second);
    }
}


int main()
{
    freopen("Text/CUTOUT.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        ans=0;
        scanf("%d %d",&n,&r);

        for(int i=0;i<r;++i)
        {
            scanf("%d %d %d %d",&points[i].X1,&points[i].X2,&points[i].Y1,&points[i].Y2);
            ys[2*i]=points[i].Y1;
            ys[2*i+1]=points[i].Y2;
        }

        ys[2*r]=0;
        ys[2*r+1]=n;

        sort(ys,ys+2*r+2);
        lenn=unique(ys,ys+2*r+2)-ys;

        for(int i=0;i<lenn;++i)
        {
            for(int j=i+1;j<lenn;++j)
            {
                ct=0;
                for(int k=0;k<r;++k)
                {
                    if(intersects(i,j,k))
                    {
                        xs[ct].first=points[k].X1;
                        xs[ct].second=-points[k].X2;

                        ++ct;
                    }
                }

                xs[ct].first=-1;
                xs[ct].second=-1;

                ++ct;
                xs[ct].first=n+1;
                xs[ct].second=-(n+1);
                ++ct;

                sort(xs,xs+ct);

                int ti=unique(xs,xs+ct)-xs;
                ct=ti;

                solve(i,j);
            }
        }

        printf("%lld\n",ans);
    }




    return 0;
}
