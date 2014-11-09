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

u64 n,m;
int k;


inline bool solve(u64 numm)
{
    int ct=0;

    while(numm)
    {
        ct+=(1&numm);
        numm>>=1;
        ct-=(1&numm);
        numm>>=1;
    }

    ct=abs(ct);

    if(ct==k)
    {
        return true;
    }

    return false;
}



int main()
{
    freopen("Text/HAP01.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int ans;

    while(cases--)
    {
        ans=0;
        scanf("%llu %llu %d",&m,&n,&k);

        for(u64 i=m;i<=n;++i)
        {
            if(solve(i))
            {
                ++ans;
            }
        }

        printf("%d\n",ans);
    }



    return 0;
}
