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

#define MAXN 266

char arr[MAXN][MAXN];
int n,m;
int sc,wc;
bool all_survive;
bool vis[MAXN][MAXN];

int anss,answ;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m || arr[x][y]=='#' || vis[x][y])
    {
        return false;
    }

    return true;
}

bool is_boundary(int x,int y)
{
    if(x==0 || y==0 || x==n-1 || y==m-1)
    {
        return true;
    }

    return false;
}


bool dfs(int x,int y)
{
    //printf("%d %d\n",x,y);
    if(is_boundary(x,y))
    {
        all_survive=true;
    }

    vis[x][y]=true;

    if(arr[x][y]=='v')
    {
        ++wc;
    }
    else if(arr[x][y]=='k')
    {
        ++sc;
    }

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

int main()
{
    freopen("Text/KOZE.txt","r",stdin);

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;++i)
    {
        scanf("%s",&arr[i]);
    }

    anss=answ=0;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(is_valid(i,j))
            {
                sc=wc=0;
                all_survive=false;
                dfs(i,j);

                if(all_survive)
                {
                    anss+=sc;
                    answ+=wc;
                }
                else if(sc>wc)
                {
                    anss+=sc;
                }
                else
                {
                    answ+=wc;
                }

            }
        }
    }

    printf("%d %d\n",anss,answ);

    return 0;
}
