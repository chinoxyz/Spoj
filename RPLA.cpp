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

#define MAXN 1000
#define MAXR 10000

int indeg[MAXN];
PII ans[MAXN];
int n,r;
set<int> s[2];
set<int>::iterator sit;
int firstt[MAXN],nxt[MAXR],to[MAXR];
int e;

void add_edge(int x,int y)
{
    to[e]=y;
    nxt[e]=firstt[x];
    firstt[x]=e++;
}

void solve()
{
    s[0].clear();
    s[1].clear();

    int i;
    int x,y;
    int rnk=0;

    for(i=0;i<n;++i)
    {
        if(indeg[i]==0)
        {
            s[0].insert(i);
        }
    }
    int src=0,dest=1;

    while(true)
    {
        if(s[src].size()==0)
        {
            break;
        }
        ++rnk;
        s[dest].clear();

        for(sit=s[src].begin();sit!=s[src].end();++sit)
        {
            ans[*sit].first=rnk;
            for(i=firstt[*sit];i!=-1;i=nxt[i])
            {
                --indeg[to[i]];
                if(indeg[to[i]]==0)
                {
                    s[dest].insert(to[i]);
                }
            }
        }

        swap(src,dest);
    }

    sort(ans,ans+n);
}


int main()
{

	freopen("Text/RPLA.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    int x,y,i,j;

    for(int t=1;t<=cases;++t)
    {
        scanf("%d %d",&n,&r);
        MSET(firstt,-1);
        e=0;


        for(i=0;i<n;++i)
        {
            ans[i].second=i;
            indeg[i]=0;
        }

        for(i=0;i<r;++i)
        {
            scanf("%d %d",&x,&y);
            ++indeg[x];
            add_edge(y,x);
        }

        solve();

        printf("Scenario #%d:\n",t);

        for(i=0;i<n;++i)
        {
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }




	return 0;
}
