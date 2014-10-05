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
#define Vi64 vector<i64>
#define Vu64 vector<u64>


int powerr[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

void solve(int num, int p, int arr[], int flag)
{
	int n, i;
	n = num / powerr[p];

	for(i=0;i<n;i++)
	{
		arr[i] += powerr[p];
	}

	arr[i] += num % powerr[p] + 1;

	if(flag)
	{
		arr[0] -= powerr[p];

	}

	if(p==0)
	{
		return;
	}

	for(i=0;i<10;i++)
	{
		arr[i] += n*p*powerr[p-1];
	}

	if(flag)
	{
		arr[0] -= (powerr[p]-1)/9;
	}

	solve(num % powerr[p], p-1, arr, 0);
}

int main()
{
    freopen("Text/MDIGITS.txt","r",stdin);
	int p1, p2, i, a, b, c;
	while(scanf("%d%d",&a,&b)==2 && a+b)
	{
		if(a>b)
		{
			c = a;
			a = b;
			b = c;
		}
		a--;
		int arr1[10] = {1};
		int arr2[10] = {1};
		if(a)
		{
			p1 = (int)floor(log10(a));
			solve(a, p1, arr1, 1);
		}
		p2 = (int)floor(log10(b));
		solve(b, p2, arr2, 1);
		printf("%d",arr2[0]-arr1[0]);
		for(i=1; i<10; i++) printf(" %d",arr2[i]-arr1[i]);
		printf("\n");
	}
	return 0;
}
