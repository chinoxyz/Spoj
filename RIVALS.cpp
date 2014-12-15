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
#define MAXN 2000007

i64 fact[MAXN];

void pree()
{
    fact[0]=fact[1]=1;

    for(i64 i=2;i<MAXN;++i)
    {
        fact[i]=(i*fact[i-1])%MODD;
    }
}


i64 poww(i64 x,i64 p)
{
    i64 ret=1;

    while(p)
    {
        if(p&1LL)
        {
            ret*=x;
            ret%=MODD;
        }
        p>>=1;
        x*=x;
        x%=MODD;
    }

    return ret;
}

i64 invv(i64 x)
{
    return poww(x,MODD-2LL);
}

int solve(int x,int y)
{
    i64 ret=1;

    ret*=fact[x+y];
    ret%=MODD;

    ret*=invv(fact[x]);
    ret%=MODD;

    ret*=invv(fact[y]);
    ret%=MODD;


    return ret;
}

int main()
{
    freopen("Text/RIVALS.txt","r",stdin);
    pree();
    int cases;
    int x,y;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",solve(x,y));
    }

    return 0;
}

