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



char maze[22][22];
int n,m;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n || maze[x][y]=='#')
    {
        return false;
    }

    return true;
}


void dfs(int x,int y)
{
    maze[x][y]='#';

    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(is_valid(nx,ny))
        {
            dfs(nx,ny);
        }
    }
}


bool solve()
{
    VI ends;
    int stx,sty,enx,eny;

    for(int i=0;i<n;++i)
    {
        if(maze[0][i]=='.')
        {
            ends.PB(0);
            ends.PB(i);
        }
    }

    if(m>1)
    {
        for(int i=0;i<n;++i)
        {
            if(maze[m-1][i]=='.')
            {
                ends.PB(m-1);
                ends.PB(i);
            }
        }
    }

    if(m>2)
    {
        for(int i=1;i<m-1;++i)
        {
            if(maze[i][0]=='.')
            {
                ends.PB(i);
                ends.PB(0);
            }
        }
    }


    if(n>1 && m>2)
    {
        for(int i=1;i<m-1;++i)
        {
            if(maze[i][n-1]=='.')
            {
                ends.PB(i);
                ends.PB(n-1);
            }
        }
    }

    if(ends.size()!=4)
    {
        return false;
    }

    stx=ends[0];
    sty=ends[1];
    enx=ends[2];
    eny=ends[3];

    dfs(stx,sty);

    if(maze[enx][eny]=='#')
    {
        return true;
    }

    return false;


}

int main() {

	freopen("Text/MAKEMAZE.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&m,&n);

        for(int i=0;i<m;++i)
        {
            scanf("%s",&maze[i]);
        }

        if(solve())
        {
            printf("valid\n");
        }
        else
        {
            printf("invalid\n");
        }
    }


    return 0;
}


