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

#define MAXN 12

bool vis[MAXN][MAXN];

int stx,sty,n,st,len;


bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=MAXN || y>=MAXN || vis[x][y])
    {
        return false;
    }

    return true;
}

int ct=999999;

int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1,1,2,2,1,-1,-2};

int dfs(int x,int y,int summ)
{
    vis[x][y]=true;

    int ret=-999999;
    int a=0;

    for(int i=0;i<8;++i)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(is_valid(nx,ny))
        {
            ++a;
            ret=max(ret,dfs(nx,ny,summ+1));
        }
    }

    vis[x][y]=false;

    if(a)
    {
        return ret;
    }

    return summ;


}

int solve()
{
    int ret=dfs(stx,sty,1);

    return (ct-ret);
}


int main(){

    freopen("Text/MKJUMPS.txt","r",stdin);

    int cases=0,ti;

    while(true)
    {
        ct=0;
        ++cases;
        scanf("%d",&n);
        MSET(vis,true);

        if(n==0)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d %d",&st,&len);
            if(i==0)
            {
                stx=i;
                sty=st;
            }

            for(int j=0;j<len;++j)
            {
                vis[i][j+st]=false;
            }
            ct+=len;
        }

        ct=solve();

        if(ct!=1)
        {
            printf("Case %d, %d squares can not be reached.\n",cases,ct);
        }
        else
        {
            printf("Case %d, %d square can not be reached.\n",cases,ct);
        }
    }

    return 0;
}




