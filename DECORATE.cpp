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


#define MAXN 444
#define MAXD 1000004

PIPIPII points[MAXN];
int ys[MAXN<<1];
int xs[MAXN<<1];
int w,h;
bool poss;
int answ,ansh;
int n;
int xct,yct;

#define X1 first
#define Y1 second.first
#define X2 second.second.first
#define Y2 second.second.second
int ct;
int rw,rh;


bool intersects(int x11,int y11,int x12,int y12,int x21,int y21,int x22,int y22)
{

    if(x11>=x22 || x12<=x21)
    {
        return 0;
    }

    if(y12<=y21 || y22<=y11)
    {
        return 0;
    }

    return 1;
}

inline bool solve(int x1,int y1,int x2,int y2)
{
    if(x2>w || y2>h)
    {
        return 0;
    }

    for(int i=0;i<n;++i)
    {
        if(intersects(x1,y1,x2,y2,points[i].X1,points[i].Y1,points[i].X2,points[i].Y2))
        {
            return 0;
        }
    }

    poss=1;
    return 1;
}

int main()
{
    freopen("Text/DECORATE.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int i,j,k;
    int lenn;

    while(cases--)
    {

        poss=0;
        scanf("%d %d %d",&n,&w,&h);

        for(i=0;i<n;++i)
        {
            scanf("%d %d %d %d",&points[i].X1,&points[i].Y1,&points[i].X2,&points[i].Y2);
            ys[2*i]=points[i].Y1;
            ys[2*i+1]=points[i].Y2;

            xs[2*i]=points[i].X1;
            xs[2*i+1]=points[i].X2;
        }

        scanf("%d %d",&rw,&rh);
        ys[2*n]=0;
        ys[2*n+1]=h;

        xs[2*n]=0;
        xs[2*n+1]=w;


        sort(ys,ys+2*n+2);
        sort(xs,xs+2*n+2);

        xct=unique(xs,xs+2*n+2)-xs;
        yct=unique(ys,ys+2*n+2)-ys;

        for(int i=0;i<yct;++i)
        {
            for(int j=0;j<xct;++j)
            {
                solve(xs[j],ys[i],xs[j]+rw,ys[i]+rh);
                if(poss)
                {
                    answ=xs[j];
                    ansh=ys[i];
                    break;
                }
            }

            if(poss)
            {
                break;
            }
        }

        if(poss)
        {
            printf("%d %d\n",answ,ansh);
        }
        else
        {
            printf("Fail!\n");
        }


    }


    return 0;
}
