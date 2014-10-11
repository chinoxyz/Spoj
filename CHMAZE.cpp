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

#define MAXN 22
#define MAXP 11
int r,c,patt;
int cases=0;

char arr[MAXP][MAXN][MAXN];

int dx[]={0,1,0,-1,0};
int dy[]={1,0,0,0,-1};

bool vis[MAXP][MAXN][MAXN];


bool is_valid(int pos,int x,int y)
{
    if(x<0 || y<0 || x>=r || y>=c || vis[pos%patt][x][y] || arr[pos%patt][x][y]=='1')
    {
        return false;
    }

    return true;
}

void solve()
{
    int ret=-1;

    queue<PIPII > q;
    q.push(MP(0,MP(0,0)));
    int dist;
    int x,y,nx,ny;

    while(!q.empty())
    {
        dist=q.front().first;
        x=q.front().second.first;
        y=q.front().second.second;
        q.pop();
        //printf("%d\t%d\t%d\n",dist,x,y);

        if(vis[dist%patt][x][y])
        {
            continue;
        }

        vis[dist%patt][x][y]=true;

        if(x==(r-1) && y==(c-1))
        {
            ret=dist;
            break;
        }

        for(int i=0;i<5;++i)
        {
            nx=x+dx[i];
            ny=y+dy[i];

            if(is_valid(dist+1,nx,ny))
            {
                q.push(MP(dist+1,MP(nx,ny)));
            }
        }
    }



    if(ret==-1)
    {
        printf("Case %d: Luke and Leia cannot escape.\n",cases);
    }
    else
    {
        printf("Case %d: Luke and Leia can escape in %d steps.\n",cases,ret);
    }
}


int main()
{
    freopen("Text/CHMAZE.txt","r",stdin);


    while(true)
    {
        ++cases;

        scanf("%d %d %d",&r,&c,&patt);

        if(r==0 && c==0 && patt==0)
        {
            break;
        }

        MSET(vis,0);


        for(int i=0;i<patt;++i)
        {
            for(int j=0;j<r;++j)
            {
                scanf("%s",&arr[i][j]);
            }
        }

        solve();
    }


    return 0;
}
