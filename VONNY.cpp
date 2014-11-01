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

bool stones[7][7];
bool grid_vis[7][8];
int gridd[7][8];

void initt()
{
    MSET(stones,0);
    MSET(grid_vis,0);
}

int ans;


void solve(int r,int c)
{
    //printf("%d\t%d\n",r,c);
    if(c==8)
    {
        ++r;
        c=0;
    }

    if(r==7)
    {
        ++ans;
        return;
    }

    if(grid_vis[r][c])
    {
        solve(r,c+1);
    }
    else
    {
        if(r+1<7 && !stones[gridd[r][c]][gridd[r+1][c]] && !grid_vis[r+1][c] && !grid_vis[r][c])
        {
            stones[gridd[r][c]][gridd[r+1][c]]=1;
            stones[gridd[r+1][c]][gridd[r][c]]=1;
            grid_vis[r][c]=1;
            grid_vis[r+1][c]=1;

            solve(r,c+1);

            stones[gridd[r][c]][gridd[r+1][c]]=0;
            stones[gridd[r+1][c]][gridd[r][c]]=0;
            grid_vis[r][c]=0;
            grid_vis[r+1][c]=0;
        }

        if(c+1<8 && !stones[gridd[r][c]][gridd[r][c+1]] && !grid_vis[r][c+1] && !grid_vis[r][c])
        {
            stones[gridd[r][c]][gridd[r][c+1]]=1;
            stones[gridd[r][c+1]][gridd[r][c]]=1;
            grid_vis[r][c]=1;
            grid_vis[r][c+1]=1;

            solve(r,c+2);

            stones[gridd[r][c]][gridd[r][c+1]]=0;
            stones[gridd[r][c+1]][gridd[r][c]]=0;
            grid_vis[r][c]=0;
            grid_vis[r][c+1]=0;
        }

    }

}


int main()
{
    freopen("Text/VONNY.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        initt();

        for(int i=0;i<7;++i)
        {
            for(int j=0;j<8;++j)
            {
                scanf("%d",&gridd[i][j]);
                //printf("%d\t",gridd[i][j]);
            }
            //printf("\n");
        }

        ans=0;

        solve(0,0);

        printf("%d\n",ans);
    }





    return 0;
}

