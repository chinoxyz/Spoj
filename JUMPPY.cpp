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

static char arr[MAXN][MAXN];
static int n;
static int mxx,mxy,mnx,mny;
static int ct;
static bool vis[MAXN][MAXN];

const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};


inline bool is_valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n || arr[x][y]=='0' || vis[x][y])
    {
        return false;
    }

    return true;
}

inline void dfs(int x,int y)
{
    ++ct;
    vis[x][y]=1;
    mxx=max(mxx,x);
    mxy=max(mxy,y);
    mnx=min(mnx,x);
    mny=min(mny,y);
    int nx,ny;

    for(int i=0;i<4;++i)
    {
        nx=x+dx[i];
        ny=y+dy[i];

        if(is_valid(nx,ny))
        {
            dfs(nx,ny);
        }
    }
}


inline void solve()
{
    //MSET(vis,0);
    int ans=0;
    int ti;
    int i,j;

    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(arr[i][j]=='X' && !vis[i][j])
            {
                mnx=i;
                mny=j;
                mxx=i;
                mxy=j;
                ct=0;
                dfs(i,j);
                ti=(mxx-mnx+1)*(mxy-mny+1);
                if(ti==ct)
                {
                    ++ans;
                }
            }
        }
    }

    printf("%d\n",ans);
}



int main()
{
    freopen("Text/JUMPPY.txt","r",stdin);

    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%s",&arr[i]);
    }

    solve();




    return 0;
}

