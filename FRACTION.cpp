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


#define MAXX 9999999

int ans[MAXX][2];



int main()
{
    freopen("Text/FRACTION.txt","r",stdin);

    int m,cases,idx,i;

    int n,x,y,x1,y1,x2,y2;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&m);
        idx=0;
        x=1;
        y=n;

        x1=0;
        x2=1;
        y1=1;
        y2=n;

        ans[idx][0]=0;
        ans[idx][1]=1;
        ++idx;
        ans[idx][0]=1;
        ans[idx][1]=n;
        ++idx;

        while(y!=1)
        {
            x=((y1+n)/y2)*x2-x1;
            y=((y1+n)/y2)*y2-y1;

            ans[idx][0]=x;
            ans[idx][1]=y;
            ++idx;
            x1=x2;
            x2=x;
            y1=y2;
            y2=y;
        }

        REP(i,m)
        {
            scanf("%d",&idx);
            --idx;
            printf("%d/%d\n",ans[idx][0],ans[idx][1]);
        }
    }

    return 0;
}



