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
    freopen("Text/CRAN01.txt","r",stdin);

    int cases,n,x,y,m,ans,mx,mn;
    int nx,ny;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&m);
        scanf("%d %d",&x,&y);

        int ans=0;

        nx=1;
        ny=1;

        mx=max(abs(x-nx),abs(y-ny));
        mn=min(abs(x-nx),abs(y-ny));

        ans=max(ans,2*mn+mx-mn);


        nx=n;
        ny=1;

        mx=max(abs(x-nx),abs(y-ny));
        mn=min(abs(x-nx),abs(y-ny));

        ans=max(ans,2*mn+mx-mn);


        nx=1;
        ny=m;

        mx=max(abs(x-nx),abs(y-ny));
        mn=min(abs(x-nx),abs(y-ny));

        ans=max(ans,2*mn+mx-mn);




        nx=n;
        ny=m;

        mx=max(abs(x-nx),abs(y-ny));
        mn=min(abs(x-nx),abs(y-ny));

        ans=max(ans,2*mn+mx-mn);

        printf("%d\n",ans);

    }


    return 0;
}
