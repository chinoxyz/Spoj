#include <bits/stdc++.h>

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

#define MAXN 510
#define MAXM 501010

#define INF 0x3f3f3f3f

int n,m,k,first_edge[MAXN],num_edges,to[MAXM],nxt[MAXM],cap[MAXM],arr[MAXN];
int src,dest,distt[MAXN],q[MAXN],tf[MAXN];
int x[MAXM],y[MAXM];

void add_edge(int u,int v,int c)
{
    to[num_edges]=v;
    nxt[num_edges]=first_edge[u];
    cap[num_edges]=c;
    first_edge[u]=num_edges++;
}

void initt(int c)
{
    MSET(first_edge,-1);
    //memset(first_edge,-1,sizeof(int)*(n+2));
    num_edges=0;
    int i;
    add_edge(src,1,k);
    add_edge(1,src,0);

    for(i=0;i<k;++i)
    {
        add_edge(arr[i],dest,1);
        add_edge(dest,arr[i],0);
    }

    for(i=0;i<m;++i)
    {
        add_edge(x[i],y[i],c);
        add_edge(y[i],x[i],c);
    }
}

bool bfs()
{
    int i,j,rear=0;

    MSET(distt,-1);
    //memset(distt,-1,sizeof(int)*(n+2));
    distt[src]=0;
    q[rear++]=src;

    for(i=0;i<rear;++i)
    {
        for(j=first_edge[q[i]];j!=-1;j=nxt[j])
        {
            if(cap[j]>0 && distt[to[j]]==-1)
            {
                distt[to[j]]=distt[q[i]]+1;
                q[rear++]=to[j];
                if(to[j]==dest)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}


int dfs(int u,int fl)
{
    if(u==dest)
    {
        return fl;
    }

    int ti;

    for(int &i=tf[u];i!=-1;i=nxt[i])
    {
        if(cap[i]>0 && distt[to[i]]==distt[u]+1)
        {
            ti=dfs(to[i],min(fl,cap[i]));
            if(ti)
            {
                cap[i]-=ti;
                cap[i^1]+=ti;
                return ti;
            }
        }
    }

    return 0;
}


int dinic()
{
    int ret=0;
    int ti;

    while(bfs())
    {
        memcpy(tf,first_edge,sizeof(first_edge));
        //memcpy(tf,first_edge,sizeof(int)*(n+2));

        while(ti=dfs(src,INF))
        {
            ret+=ti;
        }
    }

    return ret;
}

void solve()
{
    src=0;
    dest=n+1;
    int mn,mx,midd;
    mn=-1;
    mx=k;

    while(true)
    {
        midd=(mn+mx+1)>>1;
        if(mx==midd)
        {
            break;
        }

        initt(midd);

        if(dinic()==k)
        {
            mx=midd;
        }
        else
        {
            mn=midd;
        }
    }

    printf("%d\n",midd);
}




int main()
{
    freopen("Text/NETADMIN.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int i;

    while(cases--)
    {
        scanf("%d %d %d",&n,&m,&k);

        for(i=0;i<k;++i)
        {
            scanf("%d",arr+i);
        }

        for(i=0;i<m;++i)
        {
            scanf("%d %d",x+i,y+i);
        }

        solve();
    }





    return 0;
}

