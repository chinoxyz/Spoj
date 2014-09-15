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

#define MAXX 410
#define NIL 0
#define INF (1<<28)

VI adjacency[MAXX];
PII passengers[MAXX];
PII taxis[MAXX];
int taxi_match_to[MAXX];
int passenger_match_to[MAXX];
int num_passengers;
int num_taxis;
int max_dist,speed,timee;
int dist[MAXX];



bool bfs()
{
    int i,u,v,len;
    queue<int> Q;

    for(int i=1;i<=num_passengers;++i)
    {
        if(passenger_match_to[i]==NIL)
        {
            dist[i]=0;
            Q.push(i);
        }
        else
        {
            dist[i]=INF;
        }
    }

    dist[NIL]=INF;

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();

        if(u!=NIL)
        {
            len=adjacency[u].size();

            for(int i=0;i<len;++i)
            {
                v=adjacency[u][i];

                if(dist[taxi_match_to[v]]==INF)
                {
                    dist[taxi_match_to[v]]=dist[u]+1;
                    Q.push(taxi_match_to[v]);
                }
            }
        }
    }

    return (dist[NIL]!=INF);
}


bool dfs(int u)
{
    //printf("DD\n");
    int i,v,len;

    if(u!=NIL)
    {
        len=adjacency[u].size();

        for(i=0;i<len;++i)
        {
            v=adjacency[u][i];

            if(dist[taxi_match_to[v]]==(dist[u]+1))
            {
                if(dfs(taxi_match_to[v]))
                {
                    taxi_match_to[v]=u;
                    passenger_match_to[u]=v;
                    return true;
                }
            }
        }

        dist[u]=INF;
        return false;
    }

    return true;
}


int hopcroft_karp()
{
    MSET(passenger_match_to,0);
    MSET(taxi_match_to,0);

    int matching=0;
    int i;

    while(bfs())
    {

        for(i=1;i<=num_passengers;++i)
        {
            if(passenger_match_to[i]==NIL && dfs(i))
            {
                ++matching;
            }
        }
    }

    return matching;
}


int dist_bw(PII x,PII y)
{
    return abs(x.first-y.first)+abs(x.second-y.second);
}

int main()
{
    freopen("Text/TAXI.txt","r",stdin);

    int cases,i,x,y,j;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d %d",&num_passengers,&num_taxis,&speed,&timee);
        max_dist=(speed*timee)/200;

        for(i=1;i<=num_passengers;++i)
        {
            adjacency[i].clear();
            scanf("%d %d",&x,&y);
            passengers[i]=MP(x,y);
        }

        for(i=1;i<=num_taxis;++i)
        {
            scanf("%d %d",&x,&y);
            taxis[i]=MP(x,y);
        }

        for(i=1;i<=num_passengers;++i)
        {
            for(j=1;j<=num_taxis;++j)
            {
                if(dist_bw(passengers[i],taxis[j])<=max_dist)
                {
                    //printf("%d\t%d\n",i,j);
                    adjacency[i].PB(j);
                }
            }
        }

        printf("%d\n",hopcroft_karp());
    }


    return 0;
}


