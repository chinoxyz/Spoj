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

#define MAXN 103
#define MAXK 5
#define INF 99999999

int n, k;
int arr[MAXN];


int dp[MAXN][MAXN][MAXK];

int solve( int l, int r, int ct )
{
    if( l > r )
	{
		return 0;
	}
    if( l == r )
	{
		return k-1-ct;
	}

    int &ret = dp[l][r][ct];

    if( ret != -1 )
	{
		return ret;
	}
    ret = INF;

    if( ct < k-1 )
	{
		ret = solve( l, r, ct+1 ) + 1;
	}
	else if( ct == k-1 )
	{
		ret = solve( l+1, r, 0 );
	}

    for( int i = l+1; i <= r; ++i )
	{
        if( arr[i] != arr[l] )
		{
			continue;
		}

		ret=min(ret,solve( l+1, i-1, 0 ) + solve( i, r, min( k-1, ct+1 ) ));
    }

    return ret;
}

int main( void )
{
	freopen("Text/ZUMA.txt","r",stdin);

    scanf( "%d %d", &n, &k );

    for( int i = 0; i < n; ++i )
	{
        scanf( "%d", arr + i );
	}

    MSET(dp,-1);
    printf( "%d\n", solve( 0, n-1, 0 ) );

    return (0);
}
