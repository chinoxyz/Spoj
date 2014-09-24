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

#define MAXN 10001
#define MAXM 100001
#define MAXK 301

const int INF = 0x3f3f3f3f;

VPII graph[MAXN],graph_reverse[MAXN];
int min_dist[MAXN],min_dist_reverse[MAXN];
int st,en,n,m,k;



//#define gc getchar_unlocked
#define gc getchar



inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}


void djikstra(VPII gr[MAXN],int md[MAXN],int orig)
{
    priority_queue<PII > pq;
    pq.push(MP(0,orig));

    int dt,x;

    while(!pq.empty())
    {
        dt=-pq.top().first;
        x=pq.top().second;
        pq.pop();

        if(md[x]!=-1)
        {
            continue;
        }

        md[x]=dt;

        for(int i=0;i<gr[x].size();++i)
        {
            if(md[gr[x][i].first]==-1)
            {
                pq.push(MP(-(dt+gr[x][i].second),gr[x][i].first));
            }

        }
    }
}

int main(){

    freopen("Text/TRAFFICN.txt","r",stdin);

    int cases,ans,x,y,co,a1,a2;

    //scanf("%d",&cases);
    cases=readPosInt();

    while(cases--)
    {
        MSET(min_dist,-1);
        MSET(min_dist_reverse,-1);

        //scanf("%d %d %d %d %d",&n,&m,&k,&st,&en);
        n=readPosInt();
        m=readPosInt();
        k=readPosInt();
        st=readPosInt();
        en=readPosInt();

        --st;
        --en;

        for(int i=0;i<n;++i)
        {
            graph[i].clear();
            graph_reverse[i].clear();
        }

        for(int i=0;i<m;++i)
        {
            //scanf("%d %d %d",&x,&y,&co);
            x=readPosInt();
            y=readPosInt();
            co=readPosInt();

            --x;
            --y;
            graph[x].PB(MP(y,co));
            graph_reverse[y].PB(MP(x,co));
        }

        djikstra(graph,min_dist,st);
        djikstra(graph_reverse,min_dist_reverse,en);

        ans=min(min_dist[en],min_dist_reverse[st]);

        if(ans==-1)
        {
            ans=INF;
        }

        for(int i=0;i<k;++i)
        {
            //scanf("%d %d %d",&x,&y,&co);
            x=readPosInt();
            y=readPosInt();
            co=readPosInt();
            --x;
            --y;

            a1=a2=INF;

            if(min_dist[x]!=-1 && min_dist_reverse[y]!=-1)
            {
                a1=min_dist[x]+co+min_dist_reverse[y];
            }

            if(min_dist[y]!=-1 && min_dist_reverse[x]!=-1)
            {
                a2=min_dist[y]+co+min_dist_reverse[x];
            }


            ans=min(ans,min(a1,a2));
        }


        if ( ans == INF ) {
            printf( "-1\n" );
        }
        else {
            printf( "%d\n", ans );
        }
    }


    return 0;
}
