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


#define MAXN 100010

i64 tree[MAXN<<4LL];
i64 arr[MAXN<<2LL];
i64 st,en,ct;
i64 n;

void buildd(i64 node,i64 nl,i64 nr)
{
    if(nl>nr)
    {
        return;
    }

    if(nl==nr)
    {
        tree[node]=arr[nl];
        return;
    }

    i64 midd=(nl+nr)>>1LL;
    i64 lc=(node<<1LL) +1;
    i64 rc=lc+1;

    buildd(lc,nl,midd);
    buildd(rc,midd+1,nr);
    tree[node]=tree[lc]+tree[rc];
}

void update(i64 node,i64 nl,i64 nr,i64 pos)
{
    if(nl>nr)
    {
        return;
    }

    if(pos<nl || pos>nr)
    {
        return;
    }

    if(nl==nr)
    {
        tree[node]=arr[pos];
        return;
    }

    i64 midd=(nl+nr)>>1LL;
    i64 lc=(node<<1LL) +1;
    i64 rc=lc+1;

    update(lc,nl,midd,pos);
    update(rc,midd+1,nr,pos);
    tree[node]=tree[lc]+tree[rc];
}

i64 query(i64 node,i64 nl,i64 nr,i64 l,i64 r)
{
    if(nl>nr)
    {
        return 0;
    }

    if(nl>r || nr<l)
    {
        return 0;
    }

    if(nl>=l && nr<=r)
    {
        return tree[node];
    }

    i64 midd=(nl+nr)>>1LL;
    i64 lc=(node<<1LL) +1;
    i64 rc=lc+1;

    return query(lc,nl,midd,l,r)+query(rc,midd+1,nr,l,r);
}

int main()
{
    freopen("Text/RANGESUM.txt","r",stdin);
    ct=0;
    MSET(arr,0);
    MSET(tree,0);

    st=MAXN;
    scanf("%lld",&n);
    en=st+n;
    i64 x,y,z;

    for(i64 i=st;i<en;++i)
    {
        scanf("%lld",arr+i);
    }

    buildd(0,0,en-1);

    i64 q;

    scanf("%lld",&q);

    while(q--)
    {
        scanf("%lld %lld",&x,&y);

        if(x==1)
        {
            scanf("%lld",&z);
            printf("%lld\n",query(0,0,en-1,st+y-1-ct,st+z-1-ct));
        }
        else
        {
            arr[st-ct-1]=y;
            update(0,0,en-1,st-ct-1);
            ++ct;
        }

    }



    return 0;
}

