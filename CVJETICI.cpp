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

#define MAXN 100000

int bit_tree[100001],prevv[100001];

void update(int idx, int val){
    for(int x = idx;x <= 100000;)
    {
        bit_tree[x] += val;
        x += x & -x;
    }

}

int query(int idx){
    int ret = 0;

    for(int x = idx;x > 0;)
    {
        ret += bit_tree[x];
        x -= x & -x;
    }


    return ret;
}


int main()
{
    freopen("Text/CVJETICI.txt","r",stdin);

	int n;

    scanf("%d",&n);

    for(int i = 0,l,r;i < n;++i)
    {
        scanf("%d %d",&l,&r);

        int ans1 = query(l),ans2 = query(r);

        printf("%d\n",ans1 + ans2 - prevv[l] - prevv[r]);
        prevv[l] = ans1;
        prevv[r] = ans2;

        update(l + 1,1);
        update(r,-1);
    }

	return 0;
}
