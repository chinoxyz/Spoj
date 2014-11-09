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
#include<cmath>


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


//#define gc getchar_unlocked
#define gc getchar

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}


#define MAXN 99999
#define MAXM 999999
#define INF 9999999

int to[MAXM];
int cap[MAXM];
int first_edge[MAXN];
int nxt[MAXM];
int arr[MAXN];
int costt[MAXN];

int e;
int src,snk;
int n,m;
int ans=0;
int distt[MAXN];
int que_next[MAXN];
bool in_que[MAXN];
int prevv[MAXN];


inline void add_edge(int x,int y,int w,int c)
{
    to[e]=y;
    cap[e]=w;
    nxt[e]=first_edge[x];
    costt[e]=c;
    first_edge[x]=e++;

    to[e]=x;
    cap[e]=0;
    nxt[e]=first_edge[y];
    costt[e]=-c;
    first_edge[y]=e++;
}


inline bool spfa()
{
    MSET(distt,0x3f);
    int mx=distt[0];

    priority_queue<PII > pq;
    pq.push(MP(-0,src));
    int u,ti;
    int dt;
    int i;

    while(!pq.empty())
    {
        u=pq.top().second;
        ti=-pq.top().first;
        pq.pop();

        if(ti>distt[u])
        {
            continue;
        }

        distt[u]=ti;

        for(i=first_edge[u];i>=0;i=nxt[i])
        {

            if(cap[i]<=0)
            {
                continue;
            }
            dt=distt[u]+costt[i];

            if(dt<distt[to[i]])
            {
                distt[to[i]]=dt;
                pq.push(MP(-dt,to[i]));
                prevv[to[i]]=i;
            }

        }
    }


    //printf("DD\t%d\t%d\n",distt[snk],mx);


    return distt[snk]!=mx;

}


inline void augment()
{
    int flow=INF;

    for(int i=snk;i!=src;i=to[prevv[i]^1])
    {
        flow=min(flow,cap[prevv[i]]);
    }

    for(int i=snk;i!=src;i=to[prevv[i]^1])
    {
        cap[prevv[i]]-=flow;
        cap[prevv[i]^1]+=flow;
        ans+=costt[prevv[i]]*flow;
    }
}





inline void mcmf()
{
    while(spfa())
    {

        augment();
    }

    printf("%d\n",ans);
}


int main()
{
    freopen("Text/GREED.txt","r",stdin);

    int cases;
    int ti;
    int x,y;
    //scanf("%d",&cases);
    cases=readPosInt();
    int i;

    while(cases--)
    {
        ans=0;
        MSET(first_edge,-1);
        MSET(arr,0);
        e=0;
        //scanf("%d",&n);
        n=readPosInt();
        src=0;
        snk=n+1;

        for(i=0;i<n;++i)
        {
            //scanf("%d",&ti);
            ti=readPosInt();
            ++arr[ti];

        }


        //scanf("%d",&m);
        m=readPosInt();

        for(i=0;i<m;++i)
        {
            //scanf("%d %d",&x,&y);
            x=readPosInt();
            y=readPosInt();
            //if(arr[x]>1)
            {
                //add_edge(x,y,arr[x]-1,1);
                add_edge(x,y,INF,1);
            }

            //if(arr[y]>1)
            {
                //add_edge(y,x,arr[y]-1,1);
                add_edge(y,x,INF,1);
            }

        }

        for(i=1;i<=n;++i)
        {
            if(!arr[i])
            {
                add_edge(i,snk,1,0);
                //add_edge(src,i,1,0);
            }
            else if(arr[i]>1)
            {
                add_edge(src,i,arr[i]-1,0);
            }
        }

        mcmf();
    }



    return 0;
}








