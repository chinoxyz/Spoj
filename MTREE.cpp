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

const i64 MODD=1000000007LL;
#define MAXN 100001

VI adj[MAXN];
Vi64 weights[MAXN];
bool vis[MAXN];
i64 ans=0;

i64 dfs(int node)
{
    vis[node]=true;
    i64 summ=0,ti;
    i64 psum=0;
    bool poss=false;

    for(int i=0;i<adj[node].size();++i)
    {
        if(!vis[adj[node][i]])
        {
            poss=true;
            ti=(weights[node][i]*dfs(adj[node][i]))%MODD;
            ti+=weights[node][i];
            psum+=(summ*ti)%MODD;
            psum%=MODD;
            //summ+=weights[node][i];
            //psum%=MODD;
            summ+=ti;
            summ%=MODD;
        }
    }

    //summ+=psum;
    ans+=psum;
    ans+=summ;
    ans%=MODD;

    if(!poss)
    {
        summ=0;
    }

    //printf("%d\t%lld\n",node,summ);

    return summ;


}

int n,x,y,z;

int main()
{
    freopen("Text/MTREE.txt","r",stdin);

    scanf("%d",&n);

    for(int i=1;i<n;++i)
    {
        scanf("%d %d %d",&x,&y,&z);
        --x;
        --y;
        adj[x].PB(y);
        adj[y].PB(x);
        weights[x].PB(z);
        weights[y].PB(z);
    }

    dfs(0);
    printf("%lld\n",ans);



    return 0;
}
