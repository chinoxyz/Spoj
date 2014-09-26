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


#define MAX_NODES 510
#define MAX_EDGES 20001
#define INF 2147483647
#define MAX_SET_BITS 31

int num_nodes,num_edges,edge_count,start_node,target_node,num_marked;

int edge_destination[MAX_EDGES],next_edge[MAX_EDGES],first_edge_from_node[MAX_NODES],flow[MAX_EDGES];
int distancee[MAX_NODES],bfs_que[MAX_EDGES];
int ans[MAX_NODES],x[MAX_EDGES],y[MAX_EDGES],p[MAX_NODES],a[MAX_NODES];


void add_edge(int source,int destination,int weight)
{
    edge_destination[edge_count]=destination;
    next_edge[edge_count]=first_edge_from_node[source];
    first_edge_from_node[source]=edge_count;
    flow[edge_count]=weight;
    ++edge_count;
}


bool bfs()
{
    MSET(distancee,-1);
    bfs_que[1]=start_node;
    distancee[start_node]=0;

    for(int leftt=1,rightt=1;leftt<=rightt;++leftt)
    {
        int curr_node=bfs_que[leftt];
        for(int curr_edge=first_edge_from_node[curr_node];curr_edge!=-1;curr_edge=next_edge[curr_edge])
        {
            int curr_destination=edge_destination[curr_edge];

            if(flow[curr_edge] && distancee[curr_destination]==-1)
            {
                distancee[curr_destination]=distancee[curr_node]+1;
                bfs_que[++rightt]=curr_destination;
            }
        }
    }

    return distancee[target_node]!=-1;
}


int dfs(int curr_node,int curr_possible_flow)
{
    if(!curr_possible_flow)
    {
        return 0;
    }

    if(curr_node==target_node)
    {
        return curr_possible_flow;
    }

    int actual_possible_flow=0;

    for(int curr_edge=first_edge_from_node[curr_node];curr_edge!=-1 && actual_possible_flow<curr_possible_flow;curr_edge=next_edge[curr_edge])
    {
        int curr_destination=edge_destination[curr_edge];
        int flow_forwarded=min(curr_possible_flow-actual_possible_flow,flow[curr_edge]);
        int ret=0;

        if(distancee[curr_destination]==distancee[curr_node]+1)
        {
            ret=dfs(curr_destination,flow_forwarded);

            if(ret>0)
            {
                flow[curr_edge]-=ret;
                flow[curr_edge^1]+=ret;
                actual_possible_flow+=ret;
            }
        }
    }

    if(!actual_possible_flow)
    {
        distancee[curr_node]=-1;
    }

    return actual_possible_flow;
}


int main()
{
    freopen("Text/OPTM.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&num_nodes,&num_edges);

        for(int i=1;i<=num_edges;++i)
        {
            scanf("%d %d",x+i,y+i);
        }

        start_node=num_nodes+1;
        target_node=num_nodes+2;

        scanf("%d",&num_marked);

        for(int i=1;i<=num_marked;++i)
        {
            scanf("%d %d",p+i,a+i);
        }


        MSET(ans,0);

        for(int bit_num=0;bit_num<MAX_SET_BITS;++bit_num)
        {
            int maskk=(1<<bit_num);

            edge_count=0;

            MSET(first_edge_from_node,-1);

            for(int i=1;i<=num_edges;++i)
            {
                add_edge(x[i],y[i],1);
                add_edge(y[i],x[i],1);
            }

            for(int i=1;i<=num_marked;++i)
            {
                if(a[i]&maskk)
                {
                    add_edge(start_node,p[i],INF);
                    add_edge(p[i],start_node,0);
                }
                else
                {
                    add_edge(p[i],target_node,INF);
                    add_edge(target_node,p[i],0);
                }
            }

                int ret=0;

                while(bfs())
                {
                    ret+=dfs(start_node,INF);
                }

                for(int i=1;i<=num_nodes;++i)
                {
                    if(distancee[i]!=-1)
                    {
                        ans[i]|=(1<<bit_num);
                    }
                }
        }

        for(int i=1;i<=num_nodes;++i)
        {
            printf("%d\n",ans[i]);
        }
    }


    return 0;
}
