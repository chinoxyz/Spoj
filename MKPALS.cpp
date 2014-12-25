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

#define MAXN 33
char a[MAXN],b[MAXN];
int lenn;
int cost;
int alenn;
int arr[MAXN];
VI v;


void expandd()
{
    a[0]='^';
    for(int i=1;i<=lenn;++i)
    {
        a[2*i-1]='#';
        a[2*i]=b[i-1];
    }
    lenn=2*lenn+3;
    a[lenn-2]='#';
    a[lenn-1]='$';
    a[lenn]=0;
}

void solve()
{
    MSET(arr,0);
    v.clear();
    expandd();

    int c=0,r=0;
    int im;

    for(int i=1;i<lenn-1;++i)
    {
        im=2*c-i;

        arr[i]=(r>i)?min(r-i,arr[im]):0;

        while(a[i+1+arr[i]]==a[i-1-arr[i]])
        {
            ++arr[i];
        }

        if(i+arr[i]>r)
        {
            c=i;
            r=i+arr[i];
        }
    }

    int mx=0;
    int ti;

    for(int i=1;i<lenn-1;++i)
    {
        if(arr[i]>mx)
        {
            mx=arr[i];
            v.clear();
            ti=i-2;
            ti/=2;
            v.PB(ti);
        }
        else if(arr[i]==mx)
        {
            ti=i-2;
            ti/=2;
            v.PB(ti);
        }
    }
    lenn=strlen(b);
    int leftt,rightt;

    if(mx%2)
    {
        rightt=v[0]+mx/2;
    }
    else
    {
        rightt=v[0]+mx/2;
    }

    alenn=mx+2*(lenn-1-rightt);
    cost=lenn-mx;


    if(mx%2)
    {
        leftt=v[v.size()-1]-mx/2;
    }
    else
    {
        leftt=v[v.size()-1]-mx/2+1;
    }

    alenn=max(alenn,mx+2*(leftt));
}

void MAIN()
{
    int cases=0;
    while(scanf("%s",b)!=EOF)
    {
        ++cases;
        cost=alenn=0;
        lenn=strlen(b);
        solve();

        printf("Case %d, sequence = %s, cost = %d, length = %d\n",cases,b,cost,alenn);
    }
}

int main()
{
	freopen("Text/MKPALS.txt","r",stdin);

    MAIN();

	return 0;
}

