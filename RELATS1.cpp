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


#define MAXN 1005
#define MAXM 10002

int indeg[MAXN],firstt[MAXN],nxt[MAXM],to[MAXM];
int parr[MAXN];
int edges[MAXM][3];
int ect;
bool poss;
int ans;
bool vis[MAXN];
int n,m;
set<int>::iterator sit;
set<int> s[2];

int findd(int x)
{
    if(x!=parr[x])
    {
        parr[x]=findd(parr[x]);
    }

    return parr[x];
}

void unionn(int x,int y)
{
    x=findd(x);
    y=findd(y);
    parr[x]=y;
}

int e;

void add_edge(int x,int y)
{
    if(x==y)
    {
        poss=0;
        return;
    }
    ++indeg[y];
    to[e]=y;
    nxt[e]=firstt[x];
    firstt[x]=e++;
}



void solve()
{
    s[0].clear();
    s[1].clear();

    for(int i=1;i<=n;++i)
    {
        if(vis[findd(i)])
        {
            continue;
        }

        if(indeg[findd(i)]==0)
        {
            vis[findd(i)]=1;
            s[0].insert(findd(i));
        }
    }

    int src=0;
    int tar=1;
    while(true)
    {
        if(s[src].size()==0)
        {
            break;
        }

        ++ans;
        s[tar].clear();

        for(sit=s[src].begin();sit!=s[src].end();++sit)
        {
            for(int i=firstt[(*sit)];i!=-1;i=nxt[i])
            {
                --indeg[findd(to[i])];
                if(indeg[findd(to[i])]==0)
                {
                    if(vis[findd(to[i])])
                    {
                        continue;
                    }

                    vis[findd(to[i])]=1;
                    s[tar].insert(findd(to[i]));
                }
            }
        }

        swap(src,tar);
    }

    for(int i=1;i<=n;++i)
    {
        if(!vis[findd(i)])
        {
            poss=0;
            return;
        }
    }

}

int main()
{
    freopen("Text/RELATS1.txt","r",stdin);

    int cases;

    //scanf("%d",&cases);
    cin>>cases;

    while(cases--)
    {
        poss=1;
        ans=-1;
        e=0;
        ect=0;
        MSET(firstt,-1);
        MSET(indeg,0);
        MSET(vis,0);
        MSET(parr,0);

        //scanf("%d %d",&n,&m);
        cin>>n>>m;

        for(int i=1;i<=n;++i)
        {
            parr[i]=i;
        }

        for(int i=0;i<m;++i)
        {
            //scanf("%d %d %d",&edges[ect][0],&edges[ect][1],&edges[ect][2]);
            cin>>edges[ect][0]>>edges[ect][1]>>edges[ect][2];

            if(edges[ect][2]==0)
            {
                unionn(edges[ect][0],edges[ect][1]);
            }
            else
            {
                if(edges[ect][2]==1)
                {
                    int ti=edges[ect][0];
                    edges[ect][0]=edges[ect][1];
                    edges[ect][1]=ti;
                }
                edges[ect][2]=-1;
                ++ect;
            }
        }

        for(int i=0;i<ect;++i)
        {
            add_edge(findd(edges[i][0]),findd(edges[i][1]));
        }

        solve();

        //ans=max(ans,0);
        if(poss)
        {
            printf("%d\n",ans);
        }
        else
        {
            printf("NO\n");
        }

    }


    return 0;
}
