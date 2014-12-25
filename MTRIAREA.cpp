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
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 50005

struct Point
{
    double x,y;
};

Point st[MAXN];
Point arr[MAXN];
Point mn;


int top;
int n;
double ans;

inline double distancee(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


inline double crossProduct(Point p1,Point p2,Point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}


inline bool cmp(Point p1,Point p2)
{
    double ti=crossProduct(mn,p1,p2);
    if(ti>0)
    {
        return 1;
    }

    if(ti<0)
    {
        return 0;
    }

    return (distancee(mn,p1)<distancee(mn,p2));

}



inline void convexHull()
{
    int i;

    for(i=1;i<n;++i)
    {
        if(arr[i].y<arr[0].y || (arr[i].y==arr[0].y && arr[i].x<arr[0].x))
        {
            swap(arr[0],arr[i]);
        }
    }

    mn=arr[0];

    sort(arr+1,arr+n,cmp);
    st[0]=arr[0];
    st[1]=arr[1];
    top=1;

    for(i=2;i<n;++i)
    {
        while(top>=1 && crossProduct(st[top-1],st[top],arr[i])<=0)
        {
            --top;
        }
        st[++top]=arr[i];
    }
    n=top+1;
}



inline void solve()
{
    ans=0;
    if(n<3)
    {
        return;
    }

    int i,j,k;

    convexHull();
    if(n<3)
    {
        return;
    }

    if(n==3)
    {
        ans=fabs(crossProduct(st[0],st[1],st[2]))*.5;
        return;
    }

    i=0;
    j=1;
    k=2;

    int a,b,c;
    a=0;
    b=1;
    c=2;

    while(true)
    {

        while(true)
        {
            while(fabs(crossProduct(st[i],st[j],st[k]))<=fabs(crossProduct(st[i],st[j],st[(k+1)%n])))
            {
                k=(k+1)%n;
            }

            if(fabs(crossProduct(st[i],st[j],st[k]))<=fabs(crossProduct(st[i],st[(j+1)%n],st[k])))
            {
                j=(j+1)%n;
            }
            else
            {
                break;
            }
        }

        if(fabs(crossProduct(st[i],st[j],st[k]))>fabs(crossProduct(st[a],st[b],st[c])))
        {
            a=i;
            b=j;
            c=k;
        }

        i=(i+1)%n;
        if(i==j)
        {
            j=(j+1)%n;
        }

        if(j==k)
        {
            k=(k+1)%n;
        }

        if(i==0)
        {
            break;
        }
    }

    ans=fabs(crossProduct(st[a],st[b],st[c]))*0.5;

}

void MAIN()
{
    int i;
    while(true)
    {
        scanf("%d",&n);
        if(n==-1)
        {
            break;
        }

        for(i=0;i<n;++i)
        {
            //scanf("%f %f",&arr[i].x,&arr[i].y);
            cin>>arr[i].x>>arr[i].y;
        }

        solve();
        printf("%.2f\n",ans);
        //cout<<ans<<endl;
    }

}

int main()
{
	freopen("Text/MTRIAREA.txt","r",stdin);

    MAIN();

	return 0;
}

