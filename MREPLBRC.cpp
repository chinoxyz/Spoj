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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64


#define MAXN 205
#define MODD 100000

char arr[MAXN];
bool poss;
i64 dp[MAXN][MAXN];
int n;


i64 solve(int x,int y)
{
    if(x>y)
    {
        return 1;
    }

    i64 &ret=dp[x][y];
    if(ret!=-1)
    {
        return ret;
    }

    ret=0;
    i64 ct=0;

    for(int i=x+1;i<=y;i+=2)
    {
        if(arr[x]=='(' && arr[i]==')') ct=1;
        else if(arr[x]=='{' && arr[i]=='}') ct=1;
        else if(arr[x]=='[' && arr[i]==']') ct=1;
        else if(arr[x]=='?' && arr[i]==')') ct=1;
        else if(arr[x]=='?' && arr[i]=='}') ct=1;
        else if(arr[x]=='?' && arr[i]==']') ct=1;
        else if(arr[x]=='(' && arr[i]=='?') ct=1;
        else if(arr[x]=='{' && arr[i]=='?') ct=1;
        else if(arr[x]=='[' && arr[i]=='?') ct=1;
        else if(arr[x]=='?' && arr[i]=='?') ct=3;
        else    ct=0;

		if(ct==0)
		{
			continue;
		}

        ret+=ct*solve(x+1,i-1)*solve(i+1,y);

        if(ret>MODD)
        {
            poss=true;
            ret%=MODD;
        }
    }

    return ret;
}



int main()
{
    freopen("Text/MREPLBRC.txt","r",stdin);

    scanf("%d",&n);

    scanf("%s",&arr);
    MSET(dp,-1);

    i64 ans=solve(0,n-1);

    if(poss)
    {
        printf("%05lld\n",ans);
    }
    else
    {
        printf("%lld\n",ans);
    }


    return 0;
}
