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


#define MODD 1000000007LL



void multt(i64 fib[2][2],i64 mat[2][2])
{
    i64 temp[2][2]={0};

    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<2;++k)
            {
                temp[i][j]+=fib[i][k]*mat[k][j];
                temp[i][j]%=MODD;
            }
        }
    }

    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            fib[i][j]=temp[i][j];
        }
    }
}



void poww(i64 fib[2][2],i64 n)
{
    if(n<=1)
    {
        return;
    }

    i64 mat[2][2]={{1,1},{1,0}};

    poww(fib,n/2);

    multt(fib,fib);

    if(n&1)
    {
        multt(fib,mat);
    }
}

i64 fibonacci(i64 n)
{
    i64 fib[2][2]={{1,1},{1,0}};
    if(n==0)
    {
        return 0;
    }

    poww(fib,n-1);

    return fib[0][0];
}


int main()
{
    freopen("Text/MAIN74.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    i64 n;

    while(cases--)
    {
        scanf("%lld",&n);
        if(n==0)
        {
            printf("0\n");
        }
        else if(n==1)
        {
            printf("2\n");
        }
        else
        {
            printf("%lld\n",fibonacci(n+3)%MODD);
        }
    }


    return 0;
}
