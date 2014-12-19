#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
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


#define MAXN 1003

int n,leftt,rightt,tleftt,trightt;
int arr[MAXN];

int main()
{
	freopen("Text/QN01.txt","r",stdin);

	int mx=-1,ti;
	int i,j;
	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		scanf("%d",arr+i);
	}

	for (i=0; i<n; i++)
	{
		ti=arr[i];
		tleftt=i;
		if (mx<ti)
		{
			mx=ti;
			leftt=tleftt;
			rightt=i;
		}

		for (j=i+1; j<n; j++)
		{
			ti=ti^arr[j];
			if (mx<ti)
			{
				mx=ti;
				leftt=tleftt;
				rightt=j;
			}
		}
	}
	printf("%d\n%d %d\n",mx,leftt+1,rightt+1);
	return 0;
}
