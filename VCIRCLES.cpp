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

#define MAXN 1007

double SQR(double x)
{
    return x*x;
}

const double PI=acos(-1.0);
const double EPS=1e-8;

struct pointt
{
    double x,y;
    pointt(double a=0,double b=0)
    {
        x=a;
        y=b;
    }
} p,q,p1,p2;


pointt operator+(const pointt &a,const pointt &b)
{
    return pointt(a.x+b.x,a.y+b.y);
}

pointt operator-(const pointt &a,const pointt &b)
{
    return pointt(a.x-b.x,a.y-b.y);
}

pointt operator*(const pointt &a,const double &b)
{
    return pointt(a.x*b,a.y*b);
}

struct circle
{
    pointt c;
    double r;
} carr[MAXN],carr2[MAXN];

struct segmentt
{
    double l,r;
    pointt st,en;
} sarr[MAXN];

inline bool operator<(const segmentt &a,const segmentt &b)
{
    return ((a.l-b.l<-EPS) ||( (a.l - b.l < EPS) && a.r-b.r<-EPS));
}

inline bool operator<(const circle &a,const circle &b)
{
    return a.r>b.r;
}

inline double sqdistt(pointt a,pointt b)
{
    return SQR(a.x-b.x)+SQR(a.y-b.y);
}

double alpha,lastt,ans;
int n,m;

pointt rotatee(pointt p,double coss,double sinn)
{
    return pointt(p.x*coss-p.y*sinn,p.x*sinn+p.y*coss);
}

pointt calc(circle c1,circle c2,pointt &p1,pointt &p2)
{
    pointt tp=c2.c-c1.c;

    double d=sqdistt(c1.c,c2.c);

    double coss=(SQR(c1.r)+d-SQR(c2.r))/(2.0*c1.r*sqrt(d));
    double sinn=sqrt(1-SQR(coss));

    p1=rotatee(tp,coss,-sinn)*(c1.r/sqrt(d));
    p2=rotatee(tp,coss,sinn)*(c1.r/sqrt(d));
}


void filterr()
{
    sort(carr2,carr2+m);

    n=0;
    bool skipp;

    for(int i=0;i<m;++i)
    {
        if(carr2[i].r==0)
        {
            break;
        }

        skipp=0;

        for(int j=0;j<n;++j)
        {
            if(sqdistt(carr2[i].c,carr[j].c)<=SQR(carr2[i].r-carr[j].r))
            {
                skipp=1;
                break;
            }
        }

        if(skipp)
        {
            continue;
        }

        carr[n++]=carr2[i];
    }
}


void solve()
{
    filterr();

    ans=0;
    double l,r;

    for(int i=0;i<n;++i)
    {
        //cout<<ans<<endl;
        m=0;

        for(int j=0;j<n;++j)
        {
            if(i==j)
            {
                continue;
            }

            if(sqdistt(carr[i].c,carr[j].c)>=SQR(carr[i].r+carr[j].r))
            {
                continue;
            }

            calc(carr[i],carr[j],p1,p2);

            l=atan2(p1.y,p1.x);
            r=atan2(p2.y,p2.x);

            if(l<r)
            {
                sarr[m].st=p1+carr[i].c;
                sarr[m].en=p2+carr[i].c;

                sarr[m].l=l;
                sarr[m++].r=r;
            }
            else
            {
                sarr[m].st=p1+carr[i].c;
                sarr[m].en=carr[i].c;
                sarr[m].en.x-=carr[i].r;
                sarr[m].l=l;
                sarr[m++].r=PI;

                sarr[m].st=carr[i].c;
                sarr[m].st.x-=carr[i].r;
                sarr[m].en=p2+carr[i].c;
                sarr[m].l=-PI;
                sarr[m++].r=r;
            }
        }

        if(m)
        {
            sort(sarr,sarr+m);
            lastt=sarr[0].r;
            p=sarr[0].en;

            for(int j=0;j<m;++j)
            {
                if(sarr[j].l<lastt)
                {
                    if(sarr[j].r>lastt)
                    {
                        lastt=sarr[j].r;
                        p=sarr[j].en;
                    }
                }
                else
                {
                    alpha=sarr[j].l-lastt;
                    ans+=0.5*SQR(carr[i].r)*(alpha-sin(alpha));
                    q=sarr[j].st;
                    ans+=(p.x*q.y-p.y*q.x)/2.0;
                    p=sarr[j].en;
                    lastt=sarr[j].r;
                }
            }

            alpha=2*PI-lastt+sarr[0].l;
            ans+=0.5*SQR(carr[i].r)*(alpha-sin(alpha));
            q=sarr[0].st;
            ans+=(p.x*q.y-p.y*q.x)/2.0;
        }
        else
        {
            ans+=SQR(carr[i].r)*PI;
        }
    }
    //cout<<ans<<endl;

    printf("%.5f\n",ans);
}




int main()
{
    freopen("Text/VCIRCLES.txt","r",stdin);

    scanf("%d",&m);

    for(int i=0;i<m;++i)
    {
        //scanf("%f %f %f",&carr2[i].c.x,&carr2[i].c.y,&carr2[i].r);
        cin>>carr2[i].c.x>>carr2[i].c.y>>carr2[i].r;
    }

    solve();


    return 0;
}

