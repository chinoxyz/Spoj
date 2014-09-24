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

#define MAXX 100001


struct node
{
    i64 maxx,best_maxx_ever,change,best_change_ever;

    void push_down(node &left_child,node &right_child)
    {
        left_child.best_change_ever=max(left_child.best_change_ever,left_child.change+best_change_ever);
        left_child.change+=change;

        right_child.best_change_ever=max(right_child.best_change_ever,right_child.change+best_change_ever);
        right_child.change+=change;
    }

    void set_node(int val)
    {
        change+=val;
        best_change_ever=max(best_change_ever,change);
    }

    void clear_node()
    {
        change=0;
        best_change_ever=0;
    }


    void pull_up(node left_child,node right_child)
    {
        best_maxx_ever=max(max(left_child.best_maxx_ever,left_child.maxx+left_child.best_change_ever),
                           max(right_child.best_maxx_ever,right_child.maxx+right_child.best_change_ever));
        maxx=max(left_child.maxx+left_child.change,right_child.maxx+right_child.change);
    }
};


struct query
{
    int l,r,prevv;
};


int arr[MAXX],lastp[MAXX<<1],lastq[MAXX];
i64 ans[MAXX];
node tree[1<<18];
query q[MAXX];


void update(int node_num,int node_left,int node_right,int req_left,int req_right,int val)
{
    if(req_left<=node_left && node_right<=req_right)
    {
        tree[node_num].set_node(val);

    }
    else
    {
        int midd=(node_left+node_right)>>1;
        tree[node_num].push_down(tree[node_num<<1],tree[(node_num<<1)+1]);
        tree[node_num].clear_node();

        if(req_left<=midd)
        {
            update(node_num<<1,node_left,midd,req_left,req_right,val);
        }

        if(midd<req_right)
        {
            update((node_num<<1) +1,midd+1,node_right,req_left,req_right,val);
        }

        tree[node_num].pull_up(tree[node_num<<1],tree[(node_num<<1) +1]);
    }

}


i64 ask(int node_num,int node_left,int node_right,int req_left,int req_right)
{
    if(req_left<=node_left && node_right<=req_right)
    {
        return max(tree[node_num].best_maxx_ever,tree[node_num].maxx+tree[node_num].best_change_ever);
    }
    else
    {
        int midd=(node_left+node_right)>>1;

        tree[node_num].push_down(tree[node_num<<1],tree[(node_num<<1)+1]);
        tree[node_num].clear_node();
        tree[node_num].pull_up(tree[node_num<<1],tree[(node_num<<1) +1]);

        return max((req_left<=midd ? ask(node_num<<1,node_left,midd,req_left,req_right) : 0),
                    midd<req_right ? ask((node_num<<1) +1,midd+1,node_right,req_left,req_right) :0);

    }
}



int main()
{
    freopen("Text/GSS2.txt","r",stdin);

    int n,m;

    scanf("%d",&n);

    for(int i=1;i<=n;++i)
    {
        scanf("%d",arr+i);
    }


    scanf("%d",&m);

    for(int i=1;i<=m;++i)
    {
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].prevv=lastq[q[i].r];
        lastq[q[i].r]=i;
    }


    for(int i=1;i<=n;++i)
    {
        update(1,1,n,lastp[arr[i]+100000]+1,i,arr[i]);
        lastp[arr[i]+100000]=i;

        for(int j=lastq[i];j;j=q[j].prevv)
        {
            ans[j]=ask(1,1,n,q[j].l,q[j].r);
        }
    }


    for(int i=1;i<=m;++i)
    {
        printf("%lld\n",ans[i]);
    }




    return 0;
}
