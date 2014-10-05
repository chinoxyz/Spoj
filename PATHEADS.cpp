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

#define MAX 1000001
#define N 100001

int cnt[MAX], ans[MAX], arr[N];

int main()
{
    freopen("Text/PATHEADS.txt","r",stdin);


	int i, j, n, mx = -1;

	scanf("%d", &n);

	for(i = 0; i < n; ++i)
    {
        scanf("%d", arr+i);

		mx = arr[i] > mx? arr[i] : mx;

		++cnt[arr[i]];
	}

	for(i = 0; i < n; ++i)
    {
		if(arr[i] > 1 && cnt[arr[i]])
		{
			for(j = arr[i]; j <= mx; j += arr[i])
			{
                ans[j] += cnt[arr[i]];
			}

			cnt[arr[i]] = 0;
		}
	}
	for(i = 0; i < n; ++i)
    {
         printf("%d\n", ans[arr[i]] - 1 + cnt[1]);
    }
	return 0;
}
