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

#define MAXN 10001
bitset<MAXN> bs;


void sieve()
{
    int sq=sqrt(MAXN);

    for(int i=2;i<=sq;++i)
    {
        if(!bs.test(i))
        {
            for(int j=i*i;j<MAXN;j+=i)
            {
                bs.set(j);
            }
        }
    }
}




int main()
{
    freopen("Text/PROBLEM4.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    sieve();

    for(int t=1;t<=cases;++t)
    {
        int n;
        scanf("%d",&n);

        printf("%d:",t);

        if(n==3)
        {
            printf("2\n");
        }
        else if(!bs.test(n))
        {
            printf("1\n");
        }
        else
        {
            printf("NOTPRIME\n");
        }
    }


    return 0;
}

