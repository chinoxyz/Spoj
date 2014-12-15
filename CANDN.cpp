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

#define INF 0x7f7f7f7f
#define i64 long long

#define MAXN 50005
#define MAXM 150003

int n,m,b,c,d;
int to[MAXM<<1],nxt[MAXM<<1],weightt[MAXM<<1],firstt[MAXN];
int e=0;
int distt[3][MAXN];

void add_edge(int x,int y,int z)
{
    to[e]=y;
    nxt[e]=firstt[x];
    firstt[x]=e;
    weightt[e]=z;
    ++e;
}


void djikstra(int fl,int src)
{
    priority_queue<PII > pq;

    pq.push(MP(0,src));

    int x,td;
    int y,i;

    while(!pq.empty())
    {
        x=pq.top().second;
        td=-pq.top().first;
        pq.pop();

        if(td>=distt[fl][x])
        {
            continue;
        }

        distt[fl][x]=td;

        for(i=firstt[x];i>-1;i=nxt[i])
        {
            y=to[i];

            pq.push(MP(-(td+weightt[i]),y));
        }
    }
}

int main()
{
    freopen("Text/CANDN.txt","r",stdin);

    int x,y,z,ret;

    while(true)
    {
        scanf("%d %d %d %d %d",&n,&b,&c,&d,&m);
        if(n==-1)
        {
            break;
        }
        e=0;
        MSET(firstt,-1);
        MSET(distt,0x7f);


        for(int i=0;i<m;++i)
        {
            scanf("%d %d %d",&x,&y,&z);
            add_edge(x,y,z);
            add_edge(y,x,z);
        }

        djikstra(0,b);
        djikstra(1,c);
        djikstra(2,d);

        ret=0;

        for(int i=1;i<=n;++i)
        {
            if((distt[0][i]+distt[1][i])==distt[0][c] && (distt[0][i]+distt[2][i])==distt[0][d])
            {
                ret=max(ret,distt[0][i]);
            }
        }

        printf("%d %d %d\n",ret,distt[0][c]-ret,distt[0][d]-ret);
    }



    return 0;
}
