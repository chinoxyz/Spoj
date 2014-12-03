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

#define MODD 1000000007LL
#define MN1 (MODD-1LL)




struct matrixx
{
    i64 arr[2][2];
};

matrixx leftt;


matrixx mull(matrixx a,matrixx b)
{
    matrixx ret;

    int i,j,k;
    i64 ti;

    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            ret.arr[i][j]=0LL;
            for(k=0;k<2;++k)
            {
                ti=(a.arr[i][k]*b.arr[k][j]);
                ti%=MN1;
                ret.arr[i][j]+=ti;
                ret.arr[i][j]%=MN1;
            }
        }
    }

    return ret;
}


matrixx calc(matrixx a,i64 p)
{
    //printf("%lld\n",p);
    if(p==(1LL))
    {
        return a;
    }

    matrixx tm=calc(a,p/2LL);

    tm=mull(tm,tm);
    if(p&(1LL))
    {
        tm=mull(tm,a);
    }

    return tm;
}



matrixx solve(matrixx a,i64 p)
{

    if(p<=1LL)
    {
        return a;
    }

    matrixx ret=calc(a,p);


    return ret;
}

i64 poww(i64 x,i64 p)
{
    i64 ret=1LL;

    while(p)
    {
        if(p&1LL)
        {
            ret*=x;
            ret%=MODD;
        }
        p>>=1LL;
        x*=x;
        x%=MODD;
    }
    return ret;
}

int main()
{
    freopen("Text/MNNITAR.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    matrixx tm;
    i64 n;
    i64 ret;

    while(cases--)
    {
        leftt.arr[0][0]=1LL;
        leftt.arr[0][1]=1LL;
        leftt.arr[1][0]=1LL;
        leftt.arr[1][1]=0LL;

        scanf("%lld",&n);
        //printf("%lld\n",n-1LL);
        tm=solve(leftt,n-1LL);

        ret=poww(2LL,tm.arr[0][0]);
        if(n==0LL)
        {
            ret=1LL;
        }
        printf("%lld\n",ret);
    }


    return 0;
}
