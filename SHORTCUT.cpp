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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>



#define MAXN 333333
#define INF 0x7f7f7f7f

struct Point
{
	int x, y, i;
};

Point arr[MAXN], tmp[MAXN];
char buff[MAXN];
int ansst, ansen, ansdistt;

inline bool sortX(const Point &a, const Point &b)
{
	return ((a.x==b.x)? a.y < b.y : a.x < b.x);
}

inline bool sortY(const Point &a, const Point &b)
{
	return ((a.y==b.y)? a.x < b.x : a.y < b.y);
}

void solveX(int n)
{
	int st, en, distt, i;
	sort(tmp, tmp+n, sortX);
	for(i = 1; i < n; i++)
	{
		if(tmp[i-1].x==tmp[i].x && abs(tmp[i-1].i - tmp[i].i) > 1)
		{
			distt = abs(tmp[i-1].y - tmp[i].y);
			st = min(tmp[i-1].i, tmp[i].i);
			en = max(tmp[i-1].i, tmp[i].i);
			if(distt > ansdistt) continue;
			if(distt==ansdistt)
			{
				if(st > ansst) continue;
				if(st==ansst && en <= ansen) continue;
			}
			ansdistt = distt;
			ansst = st;
			ansen = en;
		}
	}
}

void solveY(int n)
{
	int st, en, distt, i;
	sort(tmp, tmp+n, sortY);
	for(i = 1; i < n; i++)
	{
		if(tmp[i-1].y==tmp[i].y && abs(tmp[i-1].i - tmp[i].i) > 1)
		{
			distt = abs(tmp[i-1].x - tmp[i].x);
			st = min(tmp[i-1].i, tmp[i].i);
			en = max(tmp[i-1].i, tmp[i].i);
			if(distt > ansdistt) continue;
			if(distt==ansdistt)
			{
				if(st > ansst) continue;
				if(st==ansst && en <= ansen) continue;
			}
			ansdistt = distt;
			ansst = st;
			ansen = en;
		}
	}
}

int main() {

	freopen("Text/SHORTCUT.txt","r",stdin);

	int cases, n, i;
	cin>>cases;
	while(cases--)
	{
		cin>>n;
		cin>>buff;
		arr[0].x = arr[0].y = arr[0].i = 0; tmp[0] = arr[0];
		ansdistt = INF; ansen = -INF; ansst = INF;
		for(i = 1; i <= n; i++)
		{
			switch(buff[i-1])
			{
				case 'N': arr[i].x = arr[i-1].x; arr[i].y = arr[i-1].y+1; arr[i].i = i; break;
				case 'S': arr[i].x = arr[i-1].x; arr[i].y = arr[i-1].y-1; arr[i].i = i; break;
				case 'E': arr[i].x = arr[i-1].x+1; arr[i].y = arr[i-1].y; arr[i].i = i; break;
				case 'W': arr[i].x = arr[i-1].x-1; arr[i].y = arr[i-1].y; arr[i].i = i; break;
			}
			tmp[i] = arr[i];
		}

		solveY(n + 1);
		solveX(n + 1);

		printf("%d %d %d ", ansdistt, ansst, ansen);

		if(arr[ansst].x < arr[ansen].x) printf("E\n");
		if(arr[ansst].x > arr[ansen].x) printf("W\n");
		if(arr[ansst].y < arr[ansen].y) printf("N\n");
		if(arr[ansst].y > arr[ansen].y) printf("S\n");
	}
	return 0;
}
