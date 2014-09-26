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


#define MAXN 102

int arr[MAXN][MAXN];
char buff[MAXN*MAXN];
bool marked[MAXN][MAXN];
int n;

bool vis[MAXN];
bool poss;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool is_valid(int x,int y,int gp)
{
    if(x<0 || y<0 || x>=n || y>=n || marked[x][y] || arr[x][y]!=gp)
    {
        return false;
    }

    return true;
}

void dfs(int x,int y,int gp)
{
    marked[x][y]=true;

    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(is_valid(nx,ny,gp))
        {
            dfs(nx,ny,gp);
        }

    }


}

int main(){

    freopen("Text/EQDIV.txt","r",stdin);

    while(true)
    {
        scanf("%d",&n);

        if(n==0)
        {
            break;
        }

        getchar();

        MSET(arr,0);
        MSET(vis,0);
        MSET(marked,0);
        int ct=1;
        poss=true;
        int x,y;

        for(int i=1;i<n;++i)
        {
            gets(buff);

            stringstream ss(buff);

            for(int j=0;j<n;++j)
            {
                ss>>x>>y;
                --x;
                --y;
                arr[x][y]=ct;
            }
            ++ct;
        }

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(!marked[i][j])
                {
                    if(vis[arr[i][j]])
                    {
                        poss=false;
                        break;
                    }
                    else
                    {
                        vis[arr[i][j]]=true;
                        dfs(i,j,arr[i][j]);
                    }
                }
            }

            if(!poss)
            {
                break;
            }
        }

        if(poss)
        {
            printf("good\n");
        }
        else
        {
            printf("wrong\n");
        }
    }

    return 0;
}
