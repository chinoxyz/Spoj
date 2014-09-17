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
#define IPII pair< int,PII >

#define MAXN 502
#define MAXM 10005

int graph[MAXN][MAXN];
int st,en;
VI pre[MAXN];
int min_dist[MAXN];
int n,m;

void djikstra()
{
    //printf("Djikstra\n");
    MSET(min_dist,-1);
    priority_queue< IPII > pq;
    int i;
    IPII tp;
    int u,v;
    int dt;

    pq.push(MP(0,MP(-1,st)));

    while(!pq.empty())
    {

        tp=pq.top();
        pq.pop();
        dt=-tp.first;
        u=tp.second.first;
        v=tp.second.second;
        //printf("%d\t%d\t%d\n",u,v,dt);


        if(min_dist[v]!=-1)
        {
            if(dt==min_dist[v])
            {
                pre[v].PB(u);
            }

            continue;
        }

        min_dist[v]=dt;
        pre[v].PB(u);

        REP(i,n)
        {
            if(graph[v][i]!=0 && min_dist[i]==-1)
            {
                pq.push(MP(-(dt+graph[v][i]),MP(v,i)));
            }
        }
    }
}


void delete_edges()
{
    //printf("Delete Edges\n");
    queue<int> que;
    que.push(en);

    while(!que.empty())
    {
        int pr=que.front();
        que.pop();

        if(pr==st)
        {
            continue;
        }

        for(int i=0;i<pre[pr].size();++i)
        {
            que.push(pre[pr][i]);
            graph[pre[pr][i]][pr]=0;
        }
        pre[pr].clear();
    }
}

int main()
{
    freopen("Text/SAMER08A.txt","r",stdin);
    int i,x,y,ct;

    while(true)
    {
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)
        {
            break;
        }

        MSET(graph,0);
        scanf("%d %d",&st,&en);

        REP(i,m)
        {
            scanf("%d %d %d",&x,&y,&ct);
            graph[x][y]=ct;
        }


        REP(i,n)
        {
            pre[i].clear();
        }
        djikstra();
/*
        printf("PREEEEEEEEEE\n");
        REP(i,n)
        {
            for(int j=0;j<pre[i].size();++j)
            {
                printf("%d\t",pre[i][j]);
            }

            printf("\n");
        }

*/

        if(min_dist[en]>0)
        {

            delete_edges();
            djikstra();
        }




        printf("%d\n",min_dist[en]);
    }


    return 0;
}



