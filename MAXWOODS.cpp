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


#define MAXN 203

char arr[MAXN][MAXN];
int vis[MAXN][MAXN][2];
int n,m;


inline int dfs(int x,int y,int dir)
{
    if(arr[x][y]=='#')
    {
        return 0;
    }

    int dr=(dir+1)/2;

    if(vis[x][y][dr]!=-1)
    {
        return vis[x][y][dr];
    }

    int &ret=vis[x][y][dr];
    ret=0;

    if(arr[x][y]=='T')
    {
        ++ret;
    }

    int ans=0;
    int nx,ny;


    ny=y+dir;

    if(ny>=0 && ny<n)
    {
        nx=x;
        dr=dir;
        ans=max(ans,dfs(nx,ny,dr));
    }


    nx=x+1;
    if(nx<m)
    {
        ny=y;
        dr=-dir;
        ans=max(ans,dfs(nx,ny,dr));
    }

    ret+=ans;

    return ret;
}

int main()
{
    freopen("Text/MAXWOODS.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    int ret,i;

    while(cases--)
    {

        scanf("%d %d",&m,&n);

        for(i=0;i<m;++i)
        {
            scanf("%s",&arr[i]);
        }

        MSET(vis,-1);
        if(arr[0][0]=='#')
        {
           ret=0;
        }
        else
        {
            ret=dfs(0,0,1);
        }

        printf("%d\n",ret);
    }

	return 0;
}
