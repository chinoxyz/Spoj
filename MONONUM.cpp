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

#define MAXN 1000011

double ans[MAXN];
double subb[MAXN];


void pre_process()
{
    for(int i=8;i<MAXN;++i)
    {
        subb[i-8]=1.0;

        for(int j=0;j<8;++j)
        {
            subb[i-8]/=(i-j);
            subb[i-8]*=(j+1);
        }
    }

    for(int i=0;i<MAXN;++i)
    {
        ans[i]=(i+9.0)/9.0;
        ans[i]-=subb[i];
    }
}


int main()
{
    freopen("Text/MONONUM.txt","r",stdin);

    pre_process();

    int n,cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        printf("%.6f\n",ans[n]);
    }




    return 0;
}
