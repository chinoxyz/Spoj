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
	freopen("Text/GCJ101C.txt","r",stdin);

	int cases;
	scanf("%d",&cases);
	i64 l,p,c;
	int ct;
	i64 ti;
	int ans;

	for(int t=1;t<=cases;++t)
	{
        scanf("%lld %lld %lld",&l,&p,&c);
        ct=0;
        ti=l;

        while(ti<p)
        {
            ti*=c;
            ++ct;
        }

        ans=0;
        while((1<<ans)<ct)
        {
            ++ans;
        }

        printf("Case #%d: %d\n",t,ans);
	}

	return 0;
}
