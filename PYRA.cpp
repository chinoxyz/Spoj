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
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MAXN 1000000000000000LL

Vu64 vc;

void pree()
{
    vc.PB(1);
    vc.PB(1);
    i64 x=1,y=1,t;

    while(y<MAXN)
    {
        t=x+y;
        x=y;
        y=t;
        vc.PB(y);
    }
}

int main()
{
    freopen("Text/ADV04L.txt","r",stdin);

    pree();
    int cases;

    u64 miles;
    u64 kms=0;

    scanf("%d",&cases);
    Vu64::iterator it;

    while(cases--)
    {
        kms=0;
        scanf("%llu",&miles);

        while(miles>0)
        {
            it=upper_bound(vc.begin(),vc.end(),miles);
            kms+=(*it);
            --it;
            miles-=(*it);

        }

        printf("%llu\n",kms);
    }

    return 0;
}
