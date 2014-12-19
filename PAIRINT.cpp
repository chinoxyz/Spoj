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

const i64 N(11);
const i64 B[N] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 2000000000};
vector<i64> v;

int main()
{
	freopen("Text/PAIRINT.txt","r",stdin);
	int cases;
	scanf("%d",&cases);

	while(cases--)
	{
		v.clear();
		i64 n, m, i, j, x, t, w;
		i64 u;
		cin>>n;
		for (i = 2; i < N; ++i)
		{
			if (n < B[i])
			{
				m = i;
				break;
			}
		}
		for (i = 0; i < m/2; ++i)
		{
			for (t = -B[i+1]+1, u = 10*n-B[i+1]+1; t < B[i+1]; ++t, ++u)
			{
				if (u % 11 == 0)
				{
					for (x = u / 11; t < B[i+1]; t += 11, ++x)
					{
						if (t == (x% B[i+1] - 10*(x%B[i])))
							v.PB(x);
					}
					break;
				}
			}
		}
		for (; i < m; ++i)
		{
			if (n & 1)
				break;

			for (t = 1, x = (n+B[i])/2; x <= n; ++t, x += B[i]/2)
			{
				if (t == (x/B[i] - x/B[i+1]))
					v.PB(x);
			}
		}

		sort(v.begin(), v.end());
		for (i = 1, j = 0; i < v.size(); ++i)
			if (v[i] == v[i-1])
				++j;

		cout<<v.size()-j<<endl;
		for (i = 0; i < v.size(); ++i)
		{
			if (i!=0 && v[i]==v[i-1])
				continue;

			w = (v[i] < B[m-1]) ? (m - 2) : (m - 1);

			cout<<v[i]<<" + "<<setfill('0')<<setw(w)<<n-v[i]<<" = "<<n<<endl;
		}
	}
    return 0;
}
