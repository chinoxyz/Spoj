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

#define MAXN 255

int arr[MAXN][MAXN];
int vis[MAXN][MAXN];
int ct[MAXN*MAXN];
int ans;
int n,m;
int numm;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m || vis[x][y] || !arr[x][y])
    {
        return false;
    }

    return true;
}

void dfs(int x,int y)
{
    ++numm;
    vis[x][y]=1;

    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(!is_valid(nx,ny))
        {
            continue;
        }

        dfs(nx,ny);
    }
}

void solve()
{
    MSET(vis,0);
    MSET(ct,0);
    ans=0;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(vis[i][j] || !arr[i][j])
            {
                continue;
            }

            numm=0;
            dfs(i,j);
            ++ct[numm];
            ++ans;
        }
    }


    printf("%d\n",ans);

    for(int i=1;i<=n*m;++i)
    {
        if(ct[i])
        {
            printf("%d %d\n",i,ct[i]);
        }
    }
}

int main()
{
    freopen("Text/UCV2013H.txt","r",stdin);

    while(true)
    {
        scanf("%d %d",&n,&m);
        if(n+m==0)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        solve();
    }



    return 0;
}
