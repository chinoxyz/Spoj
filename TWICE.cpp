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

#define MAXN 200009
#define MUL 1000000007LL

int n;
char arr[MAXN];
i64 poww[MAXN];
i64 summ[MAXN];
i64 hashes[MAXN];

void pree()
{
    poww[0]=1;
    summ[0]=0;

    for(int i=0;i<n;++i)
    {
        summ[i+1]=arr[i]+summ[i]*MUL;
        poww[i+1]=poww[i]*MUL;
    }
}

i64 calc(int i,int j)
{
    return summ[j]-summ[i]*poww[j-i];
}

bool checkk(int lenn)
{
    for(int i=0;i+lenn<=n;++i)
    {
        hashes[i]=calc(i,i+lenn);
    }

    sort(hashes,hashes+n-lenn+1);

    for(int i=0;i+1+lenn<=n;++i)
    {
        if(hashes[i]==hashes[i+1])
        {
            return 1;
        }
    }

    return 0;
}

int solve()
{
    pree();

    int st=0,en=n;
    int midd;

    while(st+1<en)
    {
        midd=(st+en)>>1;
        if(checkk(midd))
        {
            st=midd;
        }
        else
        {
            en=midd;
        }
    }

    return st;
}

int main()
{
    freopen("Text/TWICE.txt","r",stdin);

    scanf("%d %s",&n,arr);

    printf("%d\n",solve());

    return 0;
}
