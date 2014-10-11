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


double heros(double a,double b,double c)
{
    double ret=0;

    double s=(a+b+c)/2.0;

    ret=sqrt(s*(s-a)*(s-b)*(s-c));

    return ret;
}


double dist(double x1,double y1,double x2,double y2)
{
    return pow(x1-x2,2)+pow(y1-y2,2);
}



int main()
{
    freopen("Text/LCPC12E.txt","r",stdin);

    int cases;
    double x1,y1,x2,y2,r,l,r2,ans,hr,basee;

    cin>>cases;

    for(int t=1;t<=cases;++t)
    {
        cin>>x1>>y1>>x2>>y2>>r>>l;
        double basee=sqrt(dist(x1,y1,x2,y2));
        r2=l/sqrt(2.0);
        hr=heros(r,r2,basee);
        ans=4.0*hr/basee;

        if(r+r2<=basee)
        {
            printf("%d. No problem\n",t);
        }
        else
        {
            printf("%d. %.3f\n",t,ans);
        }
    }



    return 0;
}
