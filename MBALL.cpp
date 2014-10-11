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


#define MAXN 100003

u64 dp[MAXN];
u64 arr[]={2,3,6,7,8};



int main()
{
    freopen("Text/MBALL.txt","r",stdin);
    dp[0]=1;

    for(int i=0;i<5;++i)
    {
        for(int j=arr[i];j<MAXN;++j)
        {
            dp[j]+=dp[j-arr[i]];
        }
    }

    //dp[0]=0;

    int cases,n;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        printf("%llu\n",dp[n]);
    }




    return 0;
}
