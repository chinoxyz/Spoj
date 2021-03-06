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


#define MAXN 100001

i64 data[MAXN];
i64 dp[MAXN];
int n;

i64 solve(int pos)
{
    if(pos>=n)
    {
        return 0;
    }

    if(dp[pos]!=-1)
    {
        return dp[pos];
    }

    i64 &ret=dp[pos];
    ret=0;

    if(n-pos<=3)
    {
        for(int i=pos;i<n;++i)
        {
            ret+=data[i];
        }

        return ret;
    }

    i64 accs=0;
    for(int i=1;i<=3;++i)
    {
        accs+=data[pos+i-1];
        ret=max(ret,accs+solve(pos+i*2));
    }

    return ret;
}

int main(){

    freopen("Text/DCEPC501.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        MSET(dp,-1);

        for(int i=0;i<n;++i)
        {
            scanf("%lld",data+i);
        }

        printf("%lld\n",solve(0));
    }



    return 0;
}
