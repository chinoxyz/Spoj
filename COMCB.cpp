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


#define MAXN 27

bool vis[MAXN][MAXN];
char ans[MAXN*MAXN];
int n,m,p;
bool poss;

int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};

bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n || vis[x][y])
    {
        return false;
    }

    return true;
}

void dfs(int x,int y)
{
    vis[x][y]=1;
    ans[p++]='A'+x;
    ans[p++]='0'+y+1;

    if(p==2*n*m)
    {
        poss=true;
        return;
    }

    int nx;
    int ny;

    for(int i=0;i<8;++i)
    {
        if(poss)
        {
            return;
        }

        nx=x+dx[i];
        ny=y+dy[i];

        if(is_valid(nx,ny))
        {
            dfs(nx,ny);
        }
    }

    vis[x][y]=0;
    p-=2;
}

int main() {

	freopen("Text/COMCB.txt","r",stdin);

	int cases;

	scanf("%d",&cases);

	while(cases--)
    {
        scanf("%d %d",&n,&m);
        poss=false;
        MSET(vis,0);
        p=0;

        dfs(0,0);

        if(poss)
        {
            ans[2*n*m]='\0';
            printf("%s\n",ans);
        }
        else
        {
            printf("-1\n");
        }
    }


    return 0;
}
