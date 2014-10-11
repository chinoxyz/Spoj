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

#define MAXN 10005
Vi64 dx,y,x;
double ans1,ans2;


int main()
{
    freopen("Text/INTEGMAX.txt","r",stdin);
    i64 ti;
    int n;


    while(true)
    {
        dx.clear();
        x.clear();
        y.clear();
        ans1=ans2=0;

        scanf("%d",&n);
        if(n==-1)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%lld",&ti);
            x.PB(ti);
        }
        x.PB(x[0]);
        x.PB(x[n-1]);
        sort(x.begin(),x.end());

        for(int i=0;i<n;++i)
        {
            scanf("%lld",&ti);
            y.PB(ti);
        }
        sort(y.begin(),y.end());

        for(int i=0;i<n;++i)
        {
            dx.PB(x[i]-x[i+2]);
        }
        sort(dx.begin(),dx.end());

        for(int i=0;i<n;++i)
        {
            ans1+=y[i]*dx[i];
            ans2+=y[i]*dx[n-i-1];
        }

        printf("%.1f\n",(double)(max(fabs(ans1),fabs(ans2))/2.0));



    }



    return 0;
}
