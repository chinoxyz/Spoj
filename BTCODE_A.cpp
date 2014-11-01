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

i64 gcdd(i64 x,i64 y)
{
    if(!y)
    {
        return x;
    }

    return gcdd(y,x%y);
}


int main()
{
    freopen("Text/BTCODE_A.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    i64 x1,x2,y1,y2,n1,n2;

    while(cases--)
    {
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);

        x1=abs(x1);
        x2=abs(x2);
        y1=abs(y1);
        y2=abs(y2);

        n1=gcdd(x1,y1);
        n2=gcdd(x2,y2);

        while(n1 && n1<n2)
        {
            n1<<=1;
        }

        if(n1==n2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }





    return 0;
}

