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

#define MOD 1000000007
#define MOD2 1000000006
#define MAXN 200001

const int p = 2,q = 500000003;
const int invp = 250000002;

int poww(i64 a, int b, int c)
{
    i64 ret = 1;
    while(b)
	{
        if(b & 1)
		{
			ret = ret * a % c;
		}
        a = a * a % c;
        b >>= 1;
    }
    return ret;
}

i64 fact[MAXN];

void pree()
{
	fact[0] = 1;

    for(int i = 1;i < MAXN;++i)
	{
        fact[i] = fact[i - 1] * i % q;
	}
}

int main()
{
	freopen("Text/POWPOW.txt","r",stdin);

	pree();

    int cases,a,b,n;
	i64 ti,ncrr,x;

    scanf("%d",&cases);

    while(cases--)
	{
        scanf("%d %d %d",&a,&b,&n);

		ti= poww(fact[n],q - 2,q);
        ncrr = fact[2 * n] * ti % q;
		ncrr= ncrr *ti %q;
        x = ncrr * p * invp % MOD2;
        x = poww(x,b,MOD2);
        x = poww(a,x,MOD);

        printf("%lld\n",x);
    }

    return 0;
}
