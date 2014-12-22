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

#define MAXN 25005
#define MAXC 222

char arr[MAXN];
int ct[MAXC];
bool vis[MAXC];

int main ()
{
	freopen("Text/NWERC11E.txt","r",stdin);

	int cases;
	scanf("%d",&cases);
	int n;
	int ret,ti;
	int i;

	while (cases--)
	{
		scanf("%d %s",&n,arr);
		MSET(ct,0);
		MSET(vis,0);
		ret=ti=0;

		for (i=0; i<n; i++)
		{
			++ct[arr[i]];
		}

		for (i=n-1; i>=0; i--)
		{
			if (!vis[arr[i]])
			{
				ret += (ti-(n-1-i))*ct[arr[i]];
				ti += ct[arr[i]];
				vis[arr[i]] = true;
			}
		}

		printf("%d\n",ret*5);
	}

	return 0;
}
