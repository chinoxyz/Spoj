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


#define MAXN 1003
char arr[MAXN][MAXN];
i64 dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

const i64 MODD=(1LL<<31)-1LL;
int n;
bool poss1=false,poss2=false;
i64 ans=0;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool is_valid(int x,int y)
{
    if(x<0 || y<0 ||  x>=n || y>=n || arr[x][y]=='#')
    {
        return false;
    }

    return true;
}

bool is_valid2(int x,int y)
{
    if(x<0 || y<0 ||  x>=n || y>=n || arr[x][y]=='#' || vis[x][y])
    {
        return false;
    }

    return true;
}

void bfs()
{
    queue<int> q;

    q.push(0);
    q.push(0);
    int nx,ny,x,y;

    while(!q.empty())
    {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();

        if(vis[x][y])
        {
            continue;
        }

        vis[x][y]=true;


                for(int k=0;k<4;++k)
                {
                    nx=x+dx[k];
                    ny=y+dy[k];

                    if(is_valid2(nx,ny))
                    {
                        q.push(nx);
                        q.push(ny);
                    }
                }
    }
}



void solve()
{
    MSET(dp,0);
    vis[0][0]=1;
    dp[0][0]=1;
    int nx,ny;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(vis[i][j])
            {
                for(int k=0;k<2;++k)
                {
                    nx=i+dx[k];
                    ny=j+dy[k];

                    if(is_valid(nx,ny))
                    {
                        vis[nx][ny]=true;
                        dp[nx][ny]+=dp[i][j];
                        dp[nx][ny]%=MODD;
                    }
                }
            }
        }
    }

    if(vis[n-1][n-1])
    {
        poss1=true;
        ans=dp[n-1][n-1];
    }
    else
    {
        MSET(vis,0);
        bfs();

        poss2=vis[n-1][n-1];
    }


}

int main()
{
    freopen("Text/ROBOTGRI.txt","r",stdin);

    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%s",&arr[i]);
    }

    solve();

    if(poss1)
    {
        printf("%lld\n",ans);
    }
    else if(poss2)
    {
        printf("THE GAME IS A LIE\n");
    }
    else
    {
        printf("INCONCEIVABLE\n");
    }



    return 0;
}
