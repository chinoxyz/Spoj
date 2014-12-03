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

#define MAXN 100003
#define INF 999999999
#define MAXL 18

int parr[MAXN][MAXL];
int minn[MAXN][MAXL];
int maxx[MAXN][MAXL];
int n;
int tot;
int depth[MAXN];
int to[MAXN<<1];
int nxt[MAXN<<1];
int firstt[MAXN];
int vall[MAXN<<1];
int mn,mx;
int lgn;

inline void add_edge(int x,int y,int v)
{
    ++tot;
    to[tot]=y;
    nxt[tot]=firstt[x];
    firstt[x]=tot;
    vall[tot]=v;
}




inline void dfs(int node,int p)
{
    depth[node]=depth[p]+1;
    parr[node][0]=p;

    for(int i=firstt[node];i;i=nxt[i])
    {
        if(to[i]==p)
        {
            continue;
        }

        minn[to[i]][0]=maxx[to[i]][0]=vall[i];
        dfs(to[i],node);
    }
}


inline void pree()
{
    depth[0]=-1;
    dfs(1,0);
    int i,j,ti;
    int ti2;

    for(i=0;i<lgn;++i)
    {
        for(j=2;j<=n;++j)
        {
            ti=parr[j][i];
            if(ti && parr[ti][i])
            {
                ti2=i+1;
                minn[j][ti2]=min(minn[j][i],minn[ti][i]);
                maxx[j][ti2]=max(maxx[j][i],maxx[ti][i]);
                parr[j][ti2]=parr[ti][i];
            }
        }
    }
}


inline void solve(int x,int y)
{
    if(depth[x]<depth[y])
    {
        swap(x,y);
    }

    int diff=depth[x]-depth[y];
    int ti;
    int i;

    for(i=lgn;i>=0;--i)
    {
        if((1<<i)&diff)
        {
            mn=min(mn,minn[x][i]);
            mx=max(mx,maxx[x][i]);
            x=parr[x][i];
        }
    }

    if(x==y)
    {
        return;
    }

    for(i=lgn;i>=0;--i)
    {
        if(parr[x][i]!=parr[y][i])
        {
            mn=min(mn,minn[x][i]);
            mx=max(mx,maxx[x][i]);


            mn=min(mn,minn[y][i]);
            mx=max(mx,maxx[y][i]);

            x=parr[x][i];
            y=parr[y][i];
        }
    }

    //if(x!=y)
    {
        mn=min(mn,minn[x][0]);
        mx=max(mx,maxx[x][0]);


        mn=min(mn,minn[y][0]);
        mx=max(mx,maxx[y][0]);
    }
}




int main()
{
    freopen("Text/DISQUERY.txt","r",stdin);

    //scanf("%d",&n);
    n=readPosInt();

    int x,y,v;
    lgn=ceil(log2(n));
    int i;

    for(i=1;i<n;++i)
    {
        //scanf("%d %d %d",&x,&y,&v);
        x=readPosInt();
        y=readPosInt();
        v=readPosInt();

        add_edge(x,y,v);
        add_edge(y,x,v);
    }

    pree();
    int m;
    //scanf("%d",&m);
    m=readPosInt();

    for(i=0;i<m;++i)
    {
        //scanf("%d %d",&x,&y);
        x=readPosInt();
        y=readPosInt();

        mn=INF;
        mx=-INF;

        solve(x,y);

        printf("%d %d\n",mn,mx);
    }


    return 0;
}

