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


#define MAXN 100002

i64 tree[4*MAXN];
i64 arr[MAXN];

void build_tree(int nodenum,int node_left,int node_right)
{
    if(node_right<node_left)
    {
        return;
    }

    if(node_left==node_right)
    {
        tree[nodenum]=arr[node_left];
        return;
    }

    int left_child=(nodenum<<1) +1;
    int right_child=left_child+1;

    int midd=(node_left+node_right)>>1;

    build_tree(left_child,node_left,midd);
    build_tree(right_child,midd+1,node_right);

    tree[nodenum]=tree[left_child]+tree[right_child];
}

void update_tree(int nodenum,int node_left,int node_right,int req_left,int req_right)
{
    if(node_left>node_right)
    {
        return;
    }

    if(node_left>req_right || node_right<req_left)
    {
        return;
    }

    if(node_left==node_right)
    {
        tree[nodenum]=sqrt(tree[nodenum]);
        return;
    }

    if(tree[nodenum]==node_right-node_left+1)
    {
        return;
    }

    int left_child=(nodenum<<1) +1;
    int right_child=left_child+1;

    int midd=(node_left+node_right)>>1;

    update_tree(left_child,node_left,midd,req_left,req_right);
    update_tree(right_child,midd+1,node_right,req_left,req_right);

    tree[nodenum]=tree[left_child]+tree[right_child];
}

i64 query_tree(int nodenum,int node_left,int node_right,int req_left,int req_right)
{
    if(node_left>node_right)
    {
        return 0;
    }

    if(node_left>req_right || node_right<req_left)
    {
        return 0;
    }

    if(node_left>=req_left && node_right<=req_right)
    {
        return tree[nodenum];
    }

    int left_child=(nodenum<<1) +1;
    int right_child=left_child+1;

    int midd=(node_left+node_right)>>1;

    return (query_tree(left_child,node_left,midd,req_left,req_right)+query_tree(right_child,midd+1,node_right,req_left,req_right));


}




int main()
{
    freopen("Text/GSS4.txt","r",stdin);

    int cases=0,n,fl,x,y,m;

    while(scanf("%d",&n)!=EOF)
    {
        ++cases;
        MSET(tree,0);
        for(int i=0;i<n;++i)
        {
            scanf("%lld",arr+i);
        }

        build_tree(0,0,n-1);

        scanf("%d",&m);
        printf("Case #%d:\n",cases);

        while(m--)
        {
            scanf("%d %d %d",&fl,&x,&y);
            --x;
            --y;

            if(x>y)
            {
                swap(x,y);
            }

            if(fl)
            {
                printf("%lld\n",query_tree(0,0,n-1,x,y));
            }
            else
            {
                update_tree(0,0,n-1,x,y);
            }
        }

        printf("\n");
    }


    return 0;
}
