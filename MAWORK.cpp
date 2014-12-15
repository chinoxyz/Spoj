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


#define MAXN 29
#define INF 0x3f3f3f3f
#define MAXT 999

int grid[MAXN][MAXN];
char tarr[MAXN][MAXN];
int timee[MAXN][MAXN];
int n;
int vis[MAXN][MAXN][MAXT];
bool poss;
int ans;

int dx[]={0,-1,0,1,0};
int dy[]={0,0,1,0,-1};

bool is_valid(int x,int y,int d)
{
    if(x<0 || x>=n || y<0 || y>=n)
    {
        return 0;
    }

    if(timee[x][y]==0)
    {
        if(grid[x][y]==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }

    int ti=d/timee[x][y];

    ti=ti&1;

    ti=grid[x][y]^ti;

    if(!ti)
    {
        return 0;
    }


    return 1;
}
void solve()
{
    MSET(vis,0x3f);

    if(grid[0][0]==0)
    {
        return;
    }

    queue<PIPII > q;
    q.push(MP(0,MP(0,0)));
    int x,y,d;
    int nx,ny;
    int i;

    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second.first;
        d=q.front().second.second;
        q.pop();
        //printf("%d\t%d\t%d\n",x,y,d);

        if(x==(n-1) && y==(n-1))
        {
            poss=1;
            ans=d;
            return;
        }

        if(timee[x][y]==0)
        {
            if(vis[x][y][d]<=d)
            {
                continue;
            }
            else
            {
                vis[x][y][d]=d;
                for(i=0;i<5;++i)
                {
                    nx=x+dx[i];
                    ny=y+dy[i];

                    if(is_valid(nx,ny,d+1))
                    {
                        q.push(MP(nx,MP(ny,d+1)));
                    }
                }
            }
        }
        else
        {

            if(vis[x][y][d]<=d)
            {
                continue;
            }
            else
            {
                vis[x][y][d]=d;
                for(i=0;i<5;++i)
                {
                    nx=x+dx[i];
                    ny=y+dy[i];

                    if(is_valid(nx,ny,d+1))
                    {
                        q.push(MP(nx,MP(ny,d+1)));
                    }
                }
            }
        }
    }

}


int main()
{
    freopen("Text/MAWORK.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int i,j;

    while(cases--)
    {
        poss=0;
        ans=INF;
        scanf("%d",&n);

        for(i=0;i<n;++i)
        {
            scanf("%s",&tarr[i]);

            for(j=0;j<n;++j)
            {
                if(tarr[i][j]=='*')
                {
                    grid[i][j]=0;
                }
                else
                {
                    grid[i][j]=1;
                }
                //printf("%d",grid[i][j]);
            }
            //printf("\n");
        }

        for(i=0;i<n;++i)
        {
            scanf("%s",&tarr[i]);
            for(j=0;j<n;++j)
            {
                timee[i][j]=tarr[i][j]-'0';
                //printf("%d",timee[i][j]);
            }
            //printf("\n");
        }

        solve();

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




