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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 100005
int n,k;
int to[MAXN<<4],nxt[MAXN<<4],firstt[MAXN];
int indeg[MAXN];
int e;
int arr[MAXN];

void add_edge(int x,int y)
{
    ++indeg[y];
    to[e]=y;
    nxt[e]=firstt[x];
    firstt[x]=e++;
}


void solve()
{
    set<int> s[2];
    set<int>::iterator sit;
    int src=0;
    int destt=1;
    int u;
    int i;
    int j,v;

    for(i=1;i<=n;++i)
    {
        if(indeg[i]==0)
        {
            u=i;
            break;
        }
    }

    for(++i;i<=n;++i)
    {
        if(indeg[i]==0)
        {
            s[src].insert(i);
        }
    }

    for(i=firstt[u];i!=-1;i=nxt[i])
    {
        v=to[i];
        --indeg[v];
        if(indeg[v]==0)
        {
            s[src].insert(v);
        }
    }

    while(true)
    {
        if(s[src].size()==0)
        {
            break;
        }

        s[destt].clear();
        sit=s[src].begin();

        for(;sit!=s[src].end();++sit)
        {
            arr[*sit]=u;
            u=*sit;
            for(i=firstt[*sit];i!=-1;i=nxt[i])
            {
                v=to[i];
                --indeg[v];
                if(indeg[v]==0)
                {
                    s[destt].insert(v);
                }
            }
        }

        swap(src,destt);
    }

    for(i=1;i<=n;++i)
    {
        printf("%d\n",arr[i]);
    }
}

void MAIN()
{
    int v,ti;
    int i,j;
    MSET(firstt,-1);
    scanf("%d %d",&n,&k);

    for(i=1;i<=k;++i)
    {
        scanf("%d",&ti);
        for(j=1;j<=ti;++j)
        {
            scanf("%d",&v);
            add_edge(i,v);
        }
    }

    solve();
}


int main()
{
	freopen("Text/MAKETREE.txt","r",stdin);

	MAIN();

	return 0;
}
