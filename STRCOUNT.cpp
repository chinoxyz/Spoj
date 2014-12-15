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




i64 arr[66][66];


int main()
{
    freopen("Text/STRCOUNT.txt","r",stdin);

    int i,j,k;
    int ti;

    arr[0][0]=arr[1][0]=arr[1][1]=1;
    arr[2][0]=arr[2][2]=1;
    arr[2][1]=2;
    for(i=3;i<64;++i)
    {
        arr[i][0]=1;
        arr[i][i]=1;
        arr[i][i-1]=2;
        ti=i-1;

        for(j=1;j<ti;++j)
        {
            arr[i][j]=1;

            for(k=1;k<=j;++k)
            {
                arr[i][j]+=arr[i-k][j]+arr[i-j-1][k];
            }
        }
    }

    for(i=1;i<64;++i)
    {
        for(j=0;j<i;++j)
        {
            printf("%lld ",arr[i][j]);
        }
        printf("%lld\n",arr[i][i]);
    }

    return 0;
}
