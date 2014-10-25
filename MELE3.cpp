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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXK 1006
#define MAXN 50006

VPII arr[MAXN];
int k,n;

bool vis[MAXN];


int calc2(int x,int y,int ti)
{
    int ret=0;

    if(x<y)
    {
        int midd=ti%((y-x)*2);
        if(midd)
        {
            if(midd<y-x)
            {
                ret=y-x+y-midd-x;
            }
            else
            {
                ret=midd;
            }
        }
    }
    else
    {
        int midd=ti%((x-y)*2);
        if(midd)
        {
            if(midd<x-y)
            {
                ret=x-y+x-y-midd;
            }
            else
            {
                ret=midd;
            }

        }
    }

    return ret;
}


int calc(int x, int y, int ti)
{
    int dis = abs(x-y)*2, rem;

    if (x<y)
    {
        rem = ti%dis;
        return (dis-rem)%dis;
    }
    else
    {
        return ti%dis;
    }
}


void solve()
{
    MSET(vis,0);

    int ret=0;

    priority_queue<PII > pq;

    pq.push(MP(0,1));

    int di,u,v,ti,ti2;

    while(!pq.empty())
    {
        di=-pq.top().first;
        u=pq.top().second;
        pq.pop();
        //printf("%d\t%d\n",di,u);

        if(u==k)
        {
            ret=di;
            break;
        }

        if(vis[u])
        {
            continue;
        }

        vis[u]=true;

        for(int i=0;i<arr[u].size();++i)
        {
            v=arr[u][i].second;
            ti=arr[u][i].first;

            ti2=calc(u,v,di);

            pq.push(MP(-(di+ti+ti2),v));
        }
    }

    printf("%d\n",5*ret);
}

int main()
{
    freopen("Text/MELE3.txt","r",stdin);

    scanf("%d %d",&k,&n);
    int x,y;

    for(int i=0;i<n;++i)
    {
        scanf("%d %d",&x,&y);

        arr[x].PB(MP(y-x,y));
        arr[y].PB(MP(y-x,x));

    }

    solve();

    return 0;
}
