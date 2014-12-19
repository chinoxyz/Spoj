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


#define MAXN 999
#define PI acos(-1.0)

struct Point
{
    double x,y,angle;
}arr[MAXN];

double distancee(double x1,double y1,double x2,double y2)
{
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

bool cmp(Point a,Point b)
{
    return a.angle<b.angle;
}


void MAIN()
{
    int i,n,ans;
    double x,y,r;
    int m;

    while(true)
    {
        //scanf("%f %f %f",&x,&y,&r);
        cin>>x>>y>>r;
        //printf("%f\t%f\t%f\n",x,y,r);
        if(r<0)
        {
            break;
        }

        //scanf("%d",&n);
        cin>>n;
        m=0;
        ans=0;
        r*=r;

        for(i=0;i<n;++i)
        {
            //scanf("%f %f",&arr[m].x,&arr[m].y);
            cin>>arr[m].x>>arr[m].y;
            if(distancee(x,y,arr[m].x,arr[m].y)<=r)
            {
                arr[m].angle=atan2(y-arr[m].y,x-arr[m].x);
                ++m;
            }
        }

        sort(arr,arr+m,cmp);

        for(i=0;i<m;++i)
        {
            arr[i+m].angle=arr[i].angle+2*PI;
        }

        n=0;
        m<<=1;

        for(i=0;i<m;++i)
        {
            if(arr[i].angle-arr[n].angle>PI)
            {
                ans=max(ans,i-n);
                ++n;
            }
        }

        printf("%d\n",ans);
    }
}

int main()
{
	freopen("Text/TRANSMIT.txt","r",stdin);

    MAIN();

	return 0;
}
