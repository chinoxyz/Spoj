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

#define MAXN 1004
#define INF 999999999999LL
int n,k;
int b;
PII arr[MAXN];
i64 dp[MAXN][MAXN][5];


i64 solve(int pos,int ct,int msk)
{
    //printf("%d\t%d\n",pos,ct);
    if(ct>k)
    {
        return INF;
    }

    if(pos>n)
    {
        return 0;
    }

    i64 &ret=dp[pos][ct][msk];
    if(ret!=-1LL)
    {
        return ret;
    }

    ret=INF;
    int y=arr[pos].second;

    ret=min(ret,solve(pos+1,ct+1,4)+2);
    if(y==1)
    {
        ret=min(ret,solve(pos+1,ct+1,1)+1);
    }
    else
    {
        ret=min(ret,solve(pos+1,ct+1,2)+1);
    }

    if(msk==1)
    {
        if(y==1)
        {
            ret=min(ret,solve(pos+1,ct,1)+arr[pos].first-arr[pos-1].first);
        }
        ret=min(ret,solve(pos+1,ct+1,3)+arr[pos].first-arr[pos-1].first+1);
    }
    else if(msk==2)
    {
        if(y==2)
        {
            ret=min(ret,solve(pos+1,ct,2)+arr[pos].first-arr[pos-1].first);
        }

        ret=min(ret,solve(pos+1,ct+1,3)+arr[pos].first-arr[pos-1].first+1);
    }
    else if(msk==3)
    {
        if(y==1)
        {
            ret=min(ret,solve(pos+1,ct,1)+arr[pos].first-arr[pos-1].first);
        }
        else if(y==2)
        {
            ret=min(ret,solve(pos+1,ct,2)+arr[pos].first-arr[pos-1].first);
        }

        ret=min(ret,solve(pos+1,ct,3)+2*(arr[pos].first-arr[pos-1].first));
    }
    else if(msk==4)
    {
        ret=min(ret,solve(pos+1,ct,4)+2*(arr[pos].first-arr[pos-1].first));
    }

    return ret;
}
void MAIN()
{
    int cases;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&n,&k,&b);
        for(int i=1;i<=n;++i)
        {
            scanf("%d %d",&arr[i].second,&arr[i].first);
        }

        sort(arr+1,arr+n+1);
        MSET(dp,-1);

        printf("%lld\n",solve(1,0,0));
    }
}

int main()
{
	freopen("Text/LAZYCOWS.txt","r",stdin);

	MAIN();

    return (0);
}
