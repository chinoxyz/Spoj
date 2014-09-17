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



#define MAXN 1000000
const i64 INF=99999999999999999LL;

vector<i64> graph[MAXN];
vector<i64> reverse_graph[MAXN];
vector<i64> graph_cost[MAXN];
vector<i64> reverse_graph_cost[MAXN];
int num_stops,num_edges;
i64 min_dist[MAXN];

i64 djikstra(const vector<i64> gr[MAXN],const vector<i64> gr_cost[MAXN])
{
    i64 ret=0;
    fill(min_dist,min_dist+num_stops,INF);

    priority_queue< pair<i64, PII > > pq;
    i64 curr_dist;

    int prevv, noww,i;

    pq.push(MP(0,MP(-1,0)));

    while(!pq.empty())
    {
        curr_dist=-(pq.top().first);
        prevv=pq.top().second.first;
        noww=pq.top().second.second;
        pq.pop();

        if(min_dist[noww]!=INF)
        {
            continue;
        }

        min_dist[noww]=curr_dist;

        REP(i,gr[noww].size())
        {
            if(min_dist[gr[noww][i]]==INF)
            {
                pq.push(MP(-(curr_dist+gr_cost[noww][i]),MP(noww,gr[noww][i])));
            }
        }
    }



    for(i=1;i<num_stops;++i)
    {
        ret+=min_dist[i];
    }
    return ret;

}


int main() {

    freopen("Text/INCARDS.txt","r",stdin);
    int cases,i,x,y,ct;
    i64 ret;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&num_stops,&num_edges);

        for(i=0;i<num_stops;++i)
        {
            graph[i].clear();
            reverse_graph[i].clear();
            graph_cost[i].clear();
            reverse_graph_cost[i].clear();
        }

        REP(i,num_edges)
        {
            scanf("%d %d %d",&x,&y,&ct);
            --x;
            --y;
            graph[x].PB(y);
            graph_cost[x].PB(ct);
            reverse_graph[y].PB(x);
            reverse_graph_cost[y].PB(ct);
        }

        ret=djikstra(graph,graph_cost);
        ret+=djikstra(reverse_graph,reverse_graph_cost);
        printf("%lld\n",ret);
    }


    return 0;
}
