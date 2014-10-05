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


#define MAX 100001

struct data {
	int f[6], idx;
};

data orig[MAX], sorted[MAX];

bool comp(data a, data b) {
	for(int i=0;i<6;++i)
		if(a.f[i] < b.f[i]) return true;
		else if(a.f[i] > b.f[i]) return false;
	return true;
}

bool check(data a, data b) {
	for(int i=0;i<6;++i) if(a.f[i]!=b.f[i]) return false;
	return true;
}


bool match(int N) {

	for(int i=0;i<N-1;++i)
	{
		if(check(sorted[i], sorted[i+1]))
		{
			return true;
		}
	}

	return false;
}

int main() {

    freopen("Text/TWINSNOW.txt","r",stdin);
	int N, a;

	scanf("%d", &N);

	for(int i=0;i<N;++i) {
		for(int j=0;j<6;++j) {
			scanf("%d", &a);
			orig[i].f[j] = sorted[i].f[j] = a;
			orig[i].idx = sorted[i].idx = i;
		}
		sort(sorted[i].f, sorted[i].f + 6);
	}
	sort(sorted, sorted + N, comp);

	if(match(N)) printf("Twin snowflakes found.\n");
	else printf("No two snowflakes are alike.\n");

	return 0;
}
