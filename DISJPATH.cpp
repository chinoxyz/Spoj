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

#define MAXN 999999
#define MAXK 6005
#define MAXM 9999999
#define INF 99999999

char buff[MAXM];

int firstt[MAXN<<1];
int tmp[MAXN<<1];
int q[MAXN<<1];
int distt[MAXN<<1];
int nxt[MAXM],to[MAXM],cap[MAXM],flow[MAXM];
int prevv[MAXN<<1];
int src=0,snk=(MAXN<<1)-1;
int e;
int ct;
int n,k;
int tst=3;
VI ans;

void add_edge(int x,int y,int z)
{
    //assert(e<MAXM);
    to[e]=y;
    cap[e]=z;
    flow[e]=0;
    nxt[e]=firstt[x];
    firstt[x]=e++;

    to[e]=x;
    cap[e]=0;
    flow[e]=0;
    nxt[e]=firstt[y];
    firstt[y]=e++;
}

bool bfs()
{
    int st,en,i,u,v;

    MSET(distt,-1);

    distt[src]=st=en=0;

    q[en++]=src;

    while(st<en)
    {
        u=q[st++];
        for(i=firstt[u];i>=0;i=nxt[i])
        {
            v=to[i];

            if(flow[i]<cap[i] && distt[v]==-1)
            {
                distt[v]=distt[u]+1;
                q[en++]=v;
            }
        }
    }

    return distt[snk]!=-1;
}


int dfs(int u,int fl)
{
    if(u==snk)
    {
        return fl;
    }

    for(int &i=tmp[u],v,ret;i>=0;i=nxt[i])
    {
        v=to[i];

        if(flow[i]<cap[i] && distt[v]==distt[u]+1)
        {
            ret=dfs(v,min(fl,cap[i]-flow[i]));

            if(ret>0)
            {
                flow[i]+=ret;
                flow[i^1]-=ret;

                if(cap[i])
                {
                    prevv[v]=u;
                }

                return ret;
            }
        }
    }

    return 0;
}


int max_flow()
{
    int ret=0;
    int ti=0;

    while(bfs())
    {
        memcpy(tmp,firstt,sizeof(tmp));

            while(true)
            {
                ti=dfs(src,MAXK);
                if(ti)
                {
                    ret+=ti;
                }
                else
                {
                    break;
                }
            }

    }

    return ret;
}

void solve()
{
    prevv[0]=0;
    if(max_flow()<k)
    {
        printf("Impossible\n");
        return;
    }

    //assert(e>=MAXM);


    int ti;
    int f=0;
    for(int i=tst;i<tst+ct;++i)
    {
        ans.clear();
        ti=prevv[i];

        while(ti!=-1)
        {
            ans.PB(ti);

            if(ti==prevv[ti] || !ti)
            {
                break;
            }

            ti=prevv[ti];
        }

        if(ans.size()==0)
        {
            continue;
        }
        reverse(ans.begin(),ans.end());
        if(ans[0]==0)
        {
            ++f;
            printf("1 ");
            for(int j=2;j<ans.size();j+=2)
            {
                printf("%d ",(ans[j]-MAXK)/2);
            }

            printf("2\n");

            if(f==k)
            {
                break;
            }
        }
    }
}

int main()
{
    freopen("Text/DISJPATH.txt","r",stdin);

    int cases=0;
    int x,y;
    int i,j;

    while(true)
    {
        ++cases;

        //scanf("%d %d",&k,&n);
        cin>>k>>n;
        gets(buff);

        //printf("%d\t%d\n",k,n);

        if(n==0 && k==0)
        {
            break;
        }

        if(cases>1)
        {
            printf("\n");
        }

        MSET(firstt,-1);
        MSET(prevv,-1);
        e=ct=0;


        add_edge(src,1,k);

        for(i=3;i<=n;++i)
        {
            add_edge(MAXK+i*2,MAXK+i*2+1,1);
        }

        for(i=1;i<=n;++i)
        {
            gets(buff);
            //gets(buff);
            //cout<<buff<<"\t"<<k<<"\t"<<n<<endl;
            stringstream ss(buff);

            while(ss>>x)
            {
                if(x<=i)
                {
                    continue;
                }

                if(i==1 && x==2)
                {
                    add_edge(i,tst+ct,1);
                    add_edge(tst+ct,i,1);
                    add_edge(tst+ct,snk,1);
                    ++ct;
                }
                else if(i==1)
                {
                    add_edge(i,MAXK+x*2,1);
                    add_edge(MAXK+x*2+1,i,1);
                }
                else if(i==2)
                {
                    add_edge(tst+ct,MAXK+x*2,1);
                    add_edge(MAXK+x*2+1,tst+ct,1);
                    add_edge(tst+ct,snk,1);
                    ++ct;
                }
                else
                {
                    add_edge(MAXK+i*2+1,MAXK+x*2,1);
                    add_edge(MAXK+x*2+1,MAXK+2*i,1);
                }
            }
        }

        printf("Case %d:\n",cases);
        solve();
        //printf("\n");


    }

    return 0;
}
