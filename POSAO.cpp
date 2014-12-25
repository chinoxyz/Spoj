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
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
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

i64 n,k;
i64 ans;

void MAIN()
{
    scanf("%lld %lld",&n,&k);

    if(k>=n)
    {
        ans=2LL*n-1LL;
    }
    else
    {
        ans=2LL*k;
        n=n*n-k*(k+1LL);
        //ans+=ceil(n/k);
        if(n%k)
        {
            ans+=n/k+1LL;
        }
        else
        {
            ans+=n/k;
        }
    }

    printf("%lld\n",ans);
}

int main()
{
	freopen("Text/POSAO.txt","r",stdin);

    MAIN();

	return 0;
}

