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

#define MAXN 500003

int arr[MAXN];
int n,m,ans;

void update(int node,int l,int r,int x,int val)
{
    //printf("%d\t%d\t%d\t%d\t%d\n",node,l,r,x,val);
    if(l>r)
    {
        return;
    }

    if(l>x || r<x)
    {
        return;
    }

    arr[node]=min(arr[node],val);
    int midd=(l+r)>>1;

    if(l==r)
    {
        return;
    }

    update(2*node+1,l,midd,x,val);
    update(2*node+2,midd+1,r,x,val);
}


int query(int node,int l,int r,int ql,int qr)
{
    if(l>r)
    {
        return MAXN;
    }

    if(l>qr || r<ql)
    {
        return MAXN;
    }

    if(l>=ql && r<=qr)
    {
        return arr[node];
    }

    int midd=(l+r)>>1;
    int lc=2*node+1;
    int rc=2*node+2;

    return min(query(lc,l,midd,ql,qr),query(rc,midd+1,r,ql,qr));
}


int main()
{
    freopen("Text/MINIMAX.txt","r",stdin);

    int cases;
    int x,y;
    int ret;

    scanf("%d",&cases);

    while(cases--)
    {

        scanf("%d %d",&n,&m);
        MSET(arr,0x3f);
        //for(int i = 4*n;i >= 0;--i) arr[i] = MAXN;
        update(0,0,n-1,0,0);
        //printf("DD\n");

        for(int i=0;i<m;++i)
        {

            scanf("%d %d",&x,&y);
            //printf("%d\t%d\n",x,y);
            --x;
            --y;

            ret=query(0,0,n-1,x,y-1);
            if(ret!=MAXN)
            {
                //printf("RET\t%d\n",ret);
                update(0,0,n-1,y,ret+1);
            }
        }
        ans=query(0,0,n-1,n-1,n-1);

        printf("%d\n",ans);
        //printf("\n");

    }



    return 0;
}
