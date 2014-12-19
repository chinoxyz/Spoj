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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 veszor<i64>
#define Vu64 veszor<u64>


#define PI acos(-1.0)

int l1,l2,l3,m1,m2,m3;
int sh,sm,ss,eh,em,es;
char arr[233];
double ans=0;

struct Point
{
    double x,y;
    Point(double l,double angle)
    {
        x=l*cos(angle);
        y=l*sin(angle);

    }
};



void solve()
{
    ans=0;

    int st=sh*3600+sm*60+ss;
    int et=eh*3600+em*60+es;

    double x1,y1,x2,y2;

    Point hour(l1/2.0,(double)st/43200*2*PI);
    Point minute(l2/2.0,(double)st/3600*2*PI);
    Point second(l3/2.0,(double)st/60*2*PI);

    x1 = 1.0 / (m1 + m2 + m3)*(second.x * m3 + minute.x * m2 + hour.x * m1);
    y1 = 1.0 / (m1 + m2 + m3)*(second.y * m3 + minute.y * m2 + hour.y * m1);

    for (int i = st+1; i <= et; ++i)
    {
        Point hour(l1 / 2.0, (double) i / 43200 * 2 * PI);
        Point minute(l2 / 2.0, (double) i / 3600 * 2 * PI);
        Point second(l3 / 2.0, (double) i / 60 * 2 * PI);

        x2 = 1.0 / (m1 + m2 + m3)*(second.x * m3 + minute.x * m2 + hour.x * m1);
        y2 = 1.0 / (m1 + m2 + m3)*(second.y * m3 + minute.y * m2 + hour.y * m1);

        ans += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));


        x1 = x2;
        y1 = y2;
    }

    printf("%.2f\n",ans);
}



void MAIN()
{
    while(true)
    {
        scanf("%d",&l1);
        if(l1==-1)
        {
            break;
        }

        scanf("%d %d %d %d %d",&l2,&l3,&m1,&m2,&m3);

        scanf("%s",arr);
        sscanf(arr,"%d:%d:%d",&sh,&sm,&ss);

        scanf("%s",arr);
        sscanf(arr,"%d:%d:%d",&eh,&em,&es);

        solve();

    }

}

int main()
{
	freopen("Text/JUMP1.txt","r",stdin);

    MAIN();

	return 0;
}
