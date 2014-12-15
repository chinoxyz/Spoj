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

const LD EPS=1e-15;

LD integration(LD h,LD w,LD f,LD x)
{
    return -(w-2*x)*sqrt((w*w*w*w+16*h*h*(w-2*x)*(w-2*x))/(w*w*w*w))/4
		-(w*w*asinh(4*h*(w-2*x)/(w*w)))/(16*h);
}

LD solve(LD h,LD w,LD f,LD x)
{
    return 2*(f*x+integration(h,w,f,w/2)-integration(h,w,f,x));
}


int main()
{
    freopen("Text/CIVIL.txt","r",stdin);
    LD h,f,w,a,b,c,d,v1,v2,ti,ti2,ti3;

    while(true)
    {
        cin>>h>>w>>f;
        //scanf("%Lf %Lf %Lf",&h,&w,&f);
        if(h==0)
        {
            break;
        }

        a=64*(h*h);
        b=-a*w;

        ti=w*w;

        c=16*(h*h)*ti+ti*ti-(f*f)*ti*ti;
        d=b*b-4*a*c;
        if(d<0)
        {
            v1=v2=-1;
        }
        if(d>=0)
        {
            ti2=sqrt(b*b-4*a*c);
            v1=(-b+ti2)/(2*a);;
            v2=(-b-ti2)/(2*a);;
        }

        pair<LD,LD> ans;
        ans.first=1e200;
        ans=min(ans,MP(solve(h,w,f,0),0.0L));
        ans=min(ans,MP(solve(h,w,f,w/2),w/2));

        if(v1>=0 && v1<=w/2)
        {
            ans=min(ans,MP(solve(h,w,f,v1),v1));
        }

        if(v2>=0 && v2<=w/2)
        {
            ans=min(ans,MP(solve(h,w,f,v2),v2));
        }

        ti3=ans.second-w/2;

        printf("%.3Lf\n",4*h/ti*ti3*ti3+1e-15);
    }

    return 0;
}
