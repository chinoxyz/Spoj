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


#define INF 999999999

const int MAXX=1<<14;

struct Node
{
    int all_sum,left_sum,right_sum,max_sum;
};

int storage[MAXX];
Node segment_tree[MAXX<<1];

Node *dummy_node;


void build_tree(int node_num,int leftt,int rightt)
{
    if(leftt>rightt)
    {
        return;
    }

    if(leftt==rightt)
    {
        segment_tree[node_num].all_sum=segment_tree[node_num].left_sum=segment_tree[node_num].right_sum=segment_tree[node_num].max_sum=storage[leftt];
        return;
    }

    int midd=(leftt+rightt)>>1;
    int left_child= (node_num<<1) + 1;
    int right_child=left_child+1;

    build_tree(left_child,leftt,midd);
    build_tree(right_child,midd+1,rightt);

    segment_tree[node_num].all_sum=segment_tree[left_child].all_sum+segment_tree[right_child].all_sum;
    segment_tree[node_num].left_sum=max(segment_tree[left_child].left_sum,segment_tree[left_child].all_sum+segment_tree[right_child].left_sum);
    segment_tree[node_num].right_sum=max(segment_tree[right_child].right_sum,segment_tree[left_child].right_sum+segment_tree[right_child].all_sum);
    segment_tree[node_num].max_sum=max(max(segment_tree[left_child].max_sum,segment_tree[right_child].max_sum),segment_tree[left_child].right_sum+segment_tree[right_child].left_sum);

}


Node *query(int node_num,int nodel,int noder,int findl,int findr)
{
    if(findl>findr)
    {
        return dummy_node;
    }

    if(nodel==findl && noder==findr)
    {
        return &segment_tree[node_num];
    }

    int midd=(nodel+noder)>>1;
    int left_child= (node_num<<1) + 1;
    int right_child=left_child+1;

    if(findr<=midd)
    {
        return query(left_child,nodel,midd,findl,findr);
    }

    if(findl>midd)
    {
        return query(right_child,midd+1,noder,findl,findr);
    }

    Node *ret,*return_left,*return_right;
    ret=new Node();

    return_left=query(left_child, nodel, midd, findl, midd);
    return_right=query(right_child, midd+1, noder, midd+1, findr);

    ret->all_sum=return_left->all_sum+return_right->all_sum;
    ret->left_sum=max(return_left->left_sum,return_left->all_sum+return_right->left_sum);
    ret->right_sum=max(return_right->right_sum,return_left->right_sum+return_right->all_sum);
    ret->max_sum=max(max(return_left->max_sum,return_right->max_sum),return_left->right_sum+return_right->left_sum);

    return ret;


}




int main()
{
    dummy_node=new Node();
    dummy_node->all_sum=0;
    dummy_node->left_sum=0;
    dummy_node->right_sum=0;
    dummy_node->max_sum=0;


    freopen("Text/GSS5.txt","r",stdin);

    int cases,i,x1,x2,y1,y2,ret,n,num_queries;
    scanf("%d",&cases);

    while(cases--)
    {
        MSET(segment_tree,0);
        MSET(storage,0);
        ret=0;

        scanf("%d",&n);

        REP(i,n)
        {
            scanf("%d",storage+i);
        }

        build_tree(0,0,n-1);
        scanf("%d",&num_queries);

        while(num_queries--)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            --x1;
            --x2;
            --y1;
            --y2;

            if(y1<x2)
            {
                ret=query(0,0,n-1,x1,y1)->right_sum;
                ret+=query(0,0,n-1,y1+1,x2-1)->all_sum;
                ret+=query(0,0,n-1,x2,y2)->left_sum;
            }
            else
            {
                ret=query(0,0,n-1,x2,y1)->max_sum;

                ret=max(ret,max(query(0,0,n-1,x1,x2-1)->right_sum+query(0,0,n-1,x2,y2)->left_sum,query(0,0,n-1,x1,y1)->right_sum+query(0,0,n-1,y1+1,y2)->left_sum));
            }

            printf("%d\n",ret);
        }

    }
    return 0;
}


