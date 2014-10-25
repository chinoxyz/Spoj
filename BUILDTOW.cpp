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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MODD 1000000007LL


i64 n;


struct matrix
{
    i64 arr[2][2];

    matrix(i64 p,i64 q,i64 r,i64 s)
    {
        arr[0][0]=p;
        arr[0][1]=q;
        arr[1][0]=r;
        arr[1][1]=s;
    }

    matrix()
    {
        matrix(0LL,0LL,0LL,0LL);
    }
};


matrix multt(matrix m1,matrix m2)
{
    matrix ret(0,0,0,0);

    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<2;++k)
            {
                ret.arr[i][j]+=(m1.arr[i][k]*m2.arr[k][j])%MODD;
                ret.arr[i][j]%=MODD;
            }
        }
    }

    return ret;
}


matrix poww(matrix matt,i64 p)
{
    if(p==1LL)
    {
        return matt;
    }

    matrix tm=poww(matt,p/2LL);

    tm=multt(tm,tm);
    if(p&1LL)
    {
        tm=multt(matt,tm);
    }

    return tm;
}



int main()
{
    freopen("Text/BUILDTOW.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    matrix basee(1LL,1LL,1LL,0LL);

    while(cases--)
    {
        scanf("%lld",&n);

        if(n<=1LL)
        {
            printf("$%lld\n",n);
            continue;
        }

        matrix m1=poww(basee,n);
        matrix m2=multt(m1,basee);

        printf("$%lld\n",(m1.arr[0][0]*m2.arr[0][0])%MODD-1LL);
    }



    return 0;
}
