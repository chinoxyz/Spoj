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



int main()
{
    freopen("Text/BALIFE.txt","r",stdin);

    int a[9000], m, n, i, val, diff;
	while(scanf("%d", &n)==1 && n>0) {
		for(i = val = 0; i < n; i++) {
			scanf("%d", &a[i]);
			val += a[i];
		}
		if(val % n) printf("-1\n");
		else {
			val /= n;
			for(i = m = 0; i < n-1; i++) {
				diff = a[i] - val;
				a[i+1] += diff;
				if(diff < 0) diff = -diff;
				m = m > diff? m : diff;
			}
			printf("%d\n", m);
		}
	}

    return 0;
}
