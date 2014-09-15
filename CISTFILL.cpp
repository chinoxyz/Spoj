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


#define MAXX 50005
#define ITERATIONS 50

const double INF=999999999,EPS=1e-9;

struct cist
{
    double bottom,top,width,depth,area;
};


cist cisterns[MAXX];
int num_cisterns;
double lowestt,highestt;

double volume_upto(double levell)
{
    double ret=0;

    int i;
    double topp;

    REP(i,num_cisterns)
    {
        topp=min(cisterns[i].top,levell);

        if(cisterns[i].bottom+EPS<topp)
        {
            ret+=cisterns[i].area*(topp-cisterns[i].bottom);
        }
    }

    return ret;
}


double solve(double vol)
{
    double midd,highh,loww;

    highh=highestt;
    loww=lowestt;

    int i;

    REP(i,ITERATIONS)
    {
        midd=(highh+loww)/2.0;

        if(volume_upto(midd)+EPS<vol)
        {
            loww=midd;
        }
        else
        {
            highh=midd;
        }
    }

    return loww;
}

int main()
{
    freopen("Text/CISTFILL.txt","r",stdin);

    int cases,i;
    scanf("%d",&cases);
    double p,q,r,s,input_vol,ret;

    while(cases--)
    {
        scanf("%d",&num_cisterns);
        lowestt=INF;
        highestt=-INF;

        REP(i,num_cisterns)
        {
            scanf("%lf %lf %lf %lf",&p,&q,&r,&s);
            cisterns[i].bottom=p;
            cisterns[i].top=p+q;
            cisterns[i].width=r;
            cisterns[i].depth=s;
            cisterns[i].area=r*s;

            lowestt=min(lowestt,p);
            highestt=max(highestt,cisterns[i].top);
        }

        scanf("%lf",&input_vol);

        if(volume_upto(highestt)+EPS<input_vol)
        {
            printf("OVERFLOW\n");
        }
        else
        {
            ret = solve(input_vol);
			printf("%.2lf\n", ret + EPS);
        }
    }

    return 0;
}


