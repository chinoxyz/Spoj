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

#define MAXN 100002
#define MAXV 2000002
#define SHF 4

int tree[MAXN<<SHF];
int lazy[MAXN<<SHF];
int n;
int arr[MAXN];

bitset<MAXV> primes;

void pree()
{
    int i,j;
    primes.reset();

    for(i=3;i*i<MAXV;i+=2)
    {
        if(primes.test(i))
        {
            continue;
        }

        for(j=i*i;j<MAXV;j+=i)
        {
            primes.set(j);
        }
    }

    for(i=4;i<MAXV;i+=2)
    {
        primes.set(i);
    }

}



void build(int node,int nl,int nr)
{
    if(nl==nr)
    {
        tree[node]=arr[nl];
        return;
    }

    int midd=(nl+nr)>>1;
    int lc=2*node+1;
    int rc=lc+1;

    build(lc,nl,midd);
    build(rc,midd+1,nr);
    tree[node]=tree[lc]+tree[rc];
}


void update(int node,int nl,int nr,int l,int r,int v)
{
    int midd=(nl+nr)>>1;
    int lc=2*node+1;
    int rc=lc+1;

    if(lazy[node])
    {
        if(lazy[node]==-1)
        {
            tree[node]=0;
            lazy[lc]=-1;
            lazy[rc]=-1;
        }
        else
        {
            tree[node]=nr-nl+1;
            lazy[lc]=lazy[rc]=1;
        }
        lazy[node]=0;
    }

    if(nl>r || nr<l)
    {
        return;
    }

    if(nl==nr)
    {
        if(v==-1)
        {
            tree[node]=0;
        }
        else
        {
            tree[node]=1;
        }

        return;
    }

    if(nl>=l && nr<=r)
    {
        if(v==-1)
        {
            tree[node]=0;
            lazy[lc]=-1;
            lazy[rc]=-1;
        }
        else
        {
            tree[node]=nr-nl+1;
            lazy[lc]=lazy[rc]=1;
        }

        return;
    }

    update(lc,nl,midd,l,r,v);
    update(rc,midd+1,nr,l,r,v);

    tree[node]=tree[lc]+tree[rc];
}

int query(int node,int nl,int nr,int l,int r)
{
    int midd=(nl+nr)>>1;
    int lc=2*node+1;
    int rc=lc+1;

    if(lazy[node])
    {
        if(lazy[node]==-1)
        {
            tree[node]=0;
            lazy[lc]=-1;
            lazy[rc]=-1;
        }
        else
        {
            tree[node]=nr-nl+1;
            lazy[lc]=lazy[rc]=1;
        }
        lazy[node]=0;
    }

    if(nl>r || nr<l)
    {
        return 0;
    }

    if(nl>=l && nr<=r)
    {
        return tree[node];
    }

    return query(lc,nl,midd,l,r)+query(rc,midd+1,nr,l,r);

}

int main()
{
    freopen("Text/CNTPRIME.txt","r",stdin);

    pree();
    int cases;
    int q,x,y,v,ti;
    scanf("%d",&cases);


    for(int t=1;t<=cases;++t)
    {

        MSET(tree,0);
        MSET(lazy,0);
        MSET(arr,0);

        scanf("%d %d",&n,&q);

        for(int i=0;i<n;++i)
        {
            scanf("%d",&ti);
            if(!primes.test(ti))
            {
                arr[i]=1;
            }
        }



        build(0,0,n-1);


        printf("Case %d:\n",t);
        while(q--)
        {
            scanf("%d",&ti);
            if(ti==0)
            {
                scanf("%d %d %d",&x,&y,&v);
                --x;
                --y;
                if(!primes.test(v))
                {
                    v=1;
                }
                else
                {
                    v=-1;
                }

                update(0,0,n-1,x,y,v);
            }
            else
            {
                scanf("%d %d",&x,&y);
                --x;
                --y;
                printf("%d\n",query(0,0,n-1,x,y));
            }
        }
    }

    return 0;
}
