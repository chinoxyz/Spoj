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

#define MAXN 30013

VI adj[MAXN];
bool poss;
bool vis[MAXN];
int ct;
int n,m;


//#define gc getchar_unlocked
#define gc getchar

inline int readInt()
{
    int ret=0;
    bool negg=false;
    char c;
    c=gc();

    while((c<'0' || c>'9') && c!='-')
    {
        //scanf("%c",&c);
        c=gc();
    }

    if(c=='-')
    {
        negg=true;
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    if(negg)
    {
        ret=-ret;
    }

    return ret;
}



inline void dfs(int node)
{
        if(poss)
        {
            return;
        }

    vis[node]=true;
    if(node<=3)
    {
        if(ct==1 && node!=2)
        {
            vis[node]=false;
            return;
        }
        ++ct;
        if(ct==2)
        {
            poss=true;
            return;
        }
    }

    int sz=adj[node].size();

    for(int i=0;i<sz;++i)
    {
        if(poss)
        {
            return;
        }
        if(!vis[adj[node][i]])
        {
            dfs(adj[node][i]);
        }
    }

    vis[node]=false;
    if(node<=3)
    {
        --ct;
    }
}


int main()
{
    freopen("Text/IM.txt","r",stdin);
    int cases,x,y;
    poss=false;

    //scanf("%d",&cases);
    cases=readInt();

    while(cases--)
    {
        ct=0;
        poss=false;
        //scanf("%d %d",&n,&m);
        n=readInt();
        m=readInt();

        for(int i=1;i<=n;++i)
        {
            adj[i].clear();
        }

        for(int i=0;i<m;++i)
        {
            //scanf("%d %d",&x,&y);
            x=readInt();
            y=readInt();

            if(x<=0 || y<=0 ||x>n || y>n)
            {
                continue;
            }
            adj[x].PB(y);
            adj[y].PB(x);

        }

        dfs(1);

        if(poss)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }


    return 0;
}
