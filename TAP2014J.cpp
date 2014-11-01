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

#define MAXN 100006

bool poss[MAXN];
i64 arr[MAXN];
VI ans;



int main()
{
    freopen("Text/TAP2014J.txt","r",stdin);


    int n;
    i64 ti;
    scanf("%d",&n);

    for(int i=1;i<=n;++i)
    {
        scanf("%lld",arr+i);
    }

    poss[n+1]=true;
    ans.PB(n+1);

    for(int i=n;i>1;--i)
    {
        ti=i+arr[i]+1;
        if(ti>n+1 || !poss[ti])
        {
            continue;
        }

        poss[i]=true;
        ans.PB(i);
    }

    for(int i=ans.size()-1;i>=0;--i)
    {
        printf("%d\n",ans[i]-1);
    }





    return 0;
}
