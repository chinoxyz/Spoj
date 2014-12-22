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

#define MAXN 1003
#define MAXL 33


int n,d;
map<string,int> mp;
pair<string,int> names[MAXN];
int rankk[MAXN];
int e;
int to[MAXN<<1];
int nxt[MAXN<<1];
int firstt[MAXN];
int indeg[MAXN];
int root;
int lca[MAXN][MAXN];
int maxLevel;
pair<int,int> ans[MAXN];



void add_edge(int x,int y)
{
    //printf("EEEEE\t%d\t%d\n",x,y);
    lca[y][0]=x;
    ++indeg[y];
    to[e]=y;
    nxt[e]=firstt[x];
    firstt[x]=e++;
}



void solve()
{
    int i,j;
    int curr;
    maxLevel=log2(d)+1;

    for(j=1;j<=maxLevel;++j)
    {
        for(i=1;i<=n;++i)
        {
            lca[i][j]=lca[lca[i][j-1]][j-1];
        }
    }

    for(i=1;i<=n;++i)
    {
        ans[i].second=rankk[i];
        curr=i;
        for(j=0;j<=maxLevel;++j)
        {
            if(d&(1<<j))
            {
                curr=lca[curr][j];
            }
        }
        --ans[curr].first;
        //printf("C\t%d\t%d\n",curr,d);
    }

    sort(ans+1,ans+n+1);

}

void MAIN()
{
    string ts;
    int cases;
    //scanf("%d",&cases);
    cin>>cases;
    int ti;
    int m;
    int node,childd;
    int i,j;

    for(int t=1;t<=cases;++t)
    {
        MSET(ans,0);
        MSET(lca,0);
        MSET(indeg,0);
        e=0;
        MSET(firstt,-1);
        cin>>n>>d;
        mp.clear();
        m=0;

        for(i=1;i<=n;++i)
        {
            cin>>ts;
            if(mp.find(ts)==mp.end())
            {
                ++m;
                node=m;
                names[m].first=ts;
                names[m].second=m;
                mp[ts]=m;
            }
            else
            {
                //printf("DDDDDDDDDDDDDDDDDDDDD\n");
                node=mp[ts];
            }

            cin>>ti;

            while(ti--)
            {
                cin>>ts;
                //cout<<node<<ts<<endl;

                if(mp.find(ts)==mp.end())
                {
                    ++m;
                    childd=m;
                    names[m].first=ts;
                    names[m].second=m;
                    mp[ts]=m;
                }
                else
                {
                    //printf("DDDDDDDDDDDDDDDDDDDDD\n");
                    childd=mp[ts];
                }

                add_edge(node,childd);
            }
        }
        n=m;

        sort(names+1,names+n+1);

        for(i=1;i<=n;++i)
        {
            rankk[names[i].second]=i;
        }

        solve();

        printf("Tree %d:\n",t);
        ti=min(n,3);

        for(i=1;i<=ti;++i)
        {
            if(ans[i].first==0)
            {
                break;
            }

            printf("%s %d\n",names[ans[i].second].first.c_str(),-ans[i].first);
        }

        if(i>ti)
        {
            if(n>=i)
            {
                for(;i<=n;++i)
                {
                    if(ans[i].first!=ans[i-1].first)
                    {
                        break;
                    }
                    printf("%s %d\n",names[ans[i].second].first.c_str(),-ans[i].first);
                }
            }
        }

        printf("\n");

    }
}

int main ()
{
	freopen("Text/CDOWN.txt","r",stdin);

    MAIN();

	return 0;
}
