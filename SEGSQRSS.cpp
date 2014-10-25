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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64



#define MAXN 100002

i64 summ_tree[MAXN<<2];
i64 tree[MAXN<<2];

i64 arr[MAXN];


void buildd(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=arr[l];
        summ_tree[node]=arr[l]*arr[l];
        return;
    }

    int midd=(l+r)>>1;
    int lc=2*node+1;
    int rc=lc+1;

    buildd(lc,l,midd);
    buildd(rc,midd+1,r);

    summ_tree[node]=summ_tree[lc]+summ_tree[rc];
}


i64 query(int node,int nl,int nr,int l,int r)
{
    if(nl>r || nr<l)
    {
        return 0LL;
    }

    if(nl>=l && nr<=r)
    {
        return summ_tree[node];
    }

    int midd=(nl+nr)>>1;
    int lc=2*node+1;
    int rc=lc+1;

    i64 ret=query(lc,nl,midd,l,r);
    ret+=query(rc,midd+1,nr,l,r);

    return ret;
}

void update1(int node,int nl,int nr,int l,int r,int x)
{
    if(nl>r || nr<l)
    {
        return;
    }

    if(nl==nr)
    {
        tree[node]+=x;
        summ_tree[node]=tree[node]*tree[node];
        return;
    }

    int midd=(nl+nr)>>1;
    int lc=2*node+1;
    int rc=lc+1;

    update1(lc,nl,midd,l,r,x);
    update1(rc,midd+1,nr,l,r,x);

    summ_tree[node]=summ_tree[lc]+summ_tree[rc];
}


void update0(int node,int nl,int nr,int l,int r,int x)
{
    if(nl>r || nr<l)
    {
        return;
    }

    if(nl==nr)
    {
        tree[node]=x;
        summ_tree[node]=tree[node]*tree[node];
        return;
    }

    int midd=(nl+nr)>>1;
    int lc=2*node+1;
    int rc=lc+1;

    update0(lc,nl,midd,l,r,x);
    update0(rc,midd+1,nr,l,r,x);

    summ_tree[node]=summ_tree[lc]+summ_tree[rc];
}



int main()
{
    freopen("Text/SEGSQRSS.txt","r",stdin);

    int cases;
    int x,ll,rr,fl;
    int n,q;

    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
        }

        buildd(0,1,n);

        printf("Case %d:\n",t);

        for(int i=0;i<q;++i)
        {
            scanf("%d",&fl);

            if(fl==0)
            {
                scanf("%d %d %d",&ll,&rr,&x);
                update0(0,1,n,ll,rr,x);
            }
            else if(fl==1)
            {
                scanf("%d %d %d",&ll,&rr,&x);
                update1(0,1,n,ll,rr,x);
            }
            else
            {
                scanf("%d %d",&ll,&rr);
                printf("%lld\n",query(0,1,n,ll,rr));
            }
        }

    }


    return 0;
}
