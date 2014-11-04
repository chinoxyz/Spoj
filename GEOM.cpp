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





int main()
{
    freopen("Text/GEOM.txt","r",stdin);


    double x1,y1,x2,y2,l;

    cin>>x1>>y1;
    cin>>l;
    cin>>x2>>y2;

    double ti=pow(x2-x1,2)+pow(y2-y1,2);
    l=l*l/4;

    if(l<ti)
    {
        printf("NO\n");
    }
    else
    {
        double t1=x1+(y1-y2);
        double t2=y1+(x2-x1);
        printf("YES\n");
        printf("%.1f %.1f\n",t1,t2);

    }



    return 0;
}

