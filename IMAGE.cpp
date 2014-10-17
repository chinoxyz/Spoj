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


#define MAXN 24

char arr[MAXN][MAXN];
int dx[]={-1,0,1,0,-1,-1,1,1};
int dy[]={0,1,0,-1,-1,1,1,-1};
int r,c,stx,sty;

bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=r || y>=c)
    {
        return false;
    }

    return true;
}

bool vis[MAXN][MAXN];
int ans;

void dfs(int x,int y)
{
    //printf("DD\n");
    vis[x][y]=1;
    int nx,ny;

    for(int i=0;i<4;++i)
    {
        nx=x+dx[i];
        ny=y+dy[i];

        if(!is_valid(nx,ny))
        {
            ++ans;
            continue;
        }

        if(arr[nx][ny]=='.')
        {
            ++ans;
            continue;
        }

        if(!vis[nx][ny])
        {
            dfs(nx,ny);
        }
    }


    for(int i=4;i<8;++i)
    {
        nx=x+dx[i];
        ny=y+dy[i];

        if(!is_valid(nx,ny))
        {
            continue;
        }

        if(arr[nx][ny]=='.')
        {
            continue;
        }

        if(!vis[nx][ny])
        {
            dfs(nx,ny);
        }
    }
}


void solve()
{

    ans=0;
    MSET(vis,0);

    if(!(arr[stx][sty]=='.'))
    {
        dfs(stx,sty);
    }



    printf("%d\n",ans);
}


int main()
{
    freopen("Text/IMAGE.txt","r",stdin);

    while(true)
    {
        scanf("%d %d %d %d",&r,&c,&stx,&sty);
        if(r==0 && c==0)
        {
            break;
        }

        --stx;
        --sty;

        for(int i=0;i<r;++i)
        {
            scanf("%s",&arr[i]);
        }
        solve();
    }


    return 0;
}
