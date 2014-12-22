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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MODD 1000000007LL

struct Matrix
{
    i64 arr[2][2];
};

Matrix basee,unitt;


inline void multt(Matrix &a,Matrix b)
{
    Matrix t;
    int i,j,k;

    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            t.arr[i][j]=0;
            for(k=0;k<2;++k)
            {
                t.arr[i][j]+=(a.arr[i][k]*b.arr[k][j]);
                t.arr[i][j]%=MODD;
            }
        }
    }

    a=t;
}


inline void poww(Matrix &m,i64 p)
{
    Matrix ret=unitt;

    while(p)
    {
        if(p&1)
        {
            multt(ret,m);
        }
        p>>=1;
        multt(m,m);
    }

    m=ret;
}

int main( void )
{
   freopen("Text/BUZZOFF.txt","r",stdin);

    basee.arr[0][0]=basee.arr[0][1]=basee.arr[1][0]=1;
    basee.arr[1][1]=0;

    unitt.arr[0][0]=unitt.arr[1][1]=1;
    unitt.arr[0][1]=unitt.arr[1][0]=0;

   int cases;
   i64 n;

   scanf("%d",&cases);
   Matrix leftt;

   while(cases--)
   {
       leftt=basee;

       scanf("%lld",&n);
       poww(leftt,n+2);

       leftt.arr[0][0]=(leftt.arr[0][0]+MODD-2)%MODD;
       printf("%lld\n",leftt.arr[0][0]);
   }

   return 0;
}
