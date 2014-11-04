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

#define MAXN 500
#define MAXM 120000
#define INF 0x7f7f7f7f

int first_edge[MAXN],to[MAXM],nxt[MAXM],cap[MAXM],costt[MAXM];
int e;
int n,m;
int src,snk;
bool inq[MAXN];
int distt[MAXN];
int fl[MAXN];
int prevv[MAXN];
int q[MAXN<<3];

void add_edge(int u,int v,int f,int c)
{
    to[e]=v;
    nxt[e]=first_edge[u];
    costt[e]=c;
    cap[e]=f;
    first_edge[u]=e++;

    to[e]=u;
    nxt[e]=first_edge[v];
    costt[e]=-c;
    cap[e]=0;
    first_edge[v]=e++;

}

bool djikstra()
{
    MSET(distt,0x7f);
    MSET(inq,0);

    prevv[src]=-2;
    distt[src]=0;
    fl[src]=INF;
    int headd=0,taill=0;

    q[taill++]=src;
    inq[src]=1;
    int u;
    int c;
    int v;

    for(;headd<taill;++headd)
    {
        //printf("DD\n");
        u=q[headd];
        c=distt[u];

        for(int i=first_edge[u];i!=-1;i=nxt[i])
        {
            v=to[i];
            if(cap[i] && c+costt[i]<distt[v])
            {
                distt[v]=c+costt[i];
                prevv[v]=i;
                fl[v]=min(fl[u],cap[i]);
                if(!inq[v])
                {
                    inq[v]=1;
                    q[taill++]=v;
                }
            }
        }

        inq[u]=0;
    }

    return distt[snk]!=INF;
}


int mcmf()
{
    int mc=0;
    int ti;

    while(djikstra())
    {
        //printf("DD\n");
        ti=fl[snk];
        mc+=distt[snk]*ti;

        for(int e=prevv[snk];e>-1;e=prevv[to[e^1]])
        {
            cap[e]-=ti;
            cap[e^1]+=ti;
        }
    }

    return mc;
}



int main()
{
    freopen("Text/TOURS.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int x,y,z;

    while(cases--)
    {
        e=0;
        MSET(first_edge,-1);

        scanf("%d %d",&n,&m);
        src=0;
        snk=2*n+1;

        for(int i=0;i<m;++i)
        {
            scanf("%d %d %d",&x,&y,&z);
            add_edge(2*x-1,2*y,1,z);
        }

        for(int i=1;i<=n;++i)
        {
            add_edge(src,2*i-1,1,0);
            add_edge(2*i,snk,1,0);
        }



        printf("%d\n",mcmf());
    }


    return 0;
}

