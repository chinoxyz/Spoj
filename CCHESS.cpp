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
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>


int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1,1,2,2,1,-1,-2};

int vis[8][8];
int stx,sty,enx,eny;


inline bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>7 || y>7 || vis[x][y]!=-1)
    {
        return false;
    }

    return true;
}

inline void solve()
{
    MSET(vis,-1);

    priority_queue<PIPII > pq;
    int ct,x,y,nx,ny,nct;
    pq.push(MP(0,MP(stx,sty)));

    while(!pq.empty() && vis[enx][eny]==-1)
    {
        ct=-pq.top().first;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();

        if(vis[x][y]>0)
        {
            continue;
        }

        vis[x][y]=ct;

        for(int i=0;i<8;++i)
        {
            nx=x+dx[i];
            ny=y+dy[i];
            nct=ct+x*nx+y*ny;

            if(is_valid(nx,ny))
            {
                pq.push(MP(-nct,MP(nx,ny)));
            }
        }
    }




    printf("%d\n",vis[enx][eny]);

}


int main()
{
    freopen("Text/CCHESS.txt","r",stdin);

    while(scanf("%d",&stx)!=EOF)
    {
        scanf("%d %d %d",&sty,&enx,&eny);
        solve();
    }



    return 0;
}
