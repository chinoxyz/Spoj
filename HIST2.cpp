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
#define u64 unsigned i64

#define MAXX 16

int dp[1<<MAXX][MAXX],arr[MAXX],n;
i64 ct[1<<MAXX][MAXX];

int solve(int used,int last_used)
{
    if(used==(1<<n)-1)
	{
		ct[used][last_used] = 1;
		return arr[last_used];
	}

	int &ret = dp[used][last_used];
	if(ret != -1) return ret;

	ret = 0;
	for(int i = 0, val; i < n; i++)
	{
		if(!(used & (1 << i)))
		{
			val = solve(used | (1 << i), i) + abs(arr[i]-arr[last_used]);
			if(val > ret)
			{
				ret = val;
				ct[used][last_used] = 0;
			}
			if(val==ret) ct[used][last_used] += ct[used | (1 << i)][i];
		}
	}
	return ret;
}


int main()
{

    freopen("Text/HIST2.txt","r",stdin);


	int val, maxval;
	i64 cnt;

	while(true)
	{
		scanf("%d", &n);

		if(!n)
		{
			break;
		}

		for(int i = 0; i < n; i++)
		{
			scanf("%d", arr+i);
		}
		maxval = 0;
		MSET(dp,-1);
		MSET(ct,0);

		for(int i = 0; i < n; i++)
		{
			val = solve(1<<i, i) + arr[i];
			if(val > maxval)
			{
				maxval = val;
				cnt = 0;
			}
			if(val==maxval) cnt += ct[1<<i][i];
		}
		maxval += (n << 1);
		printf("%d %lld\n", maxval, cnt);
	}



    return 0;
}
