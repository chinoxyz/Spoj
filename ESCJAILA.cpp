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


#define MAXN 105

char arr[MAXN][MAXN];
int n,m;
int stx, sty;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int dp[MAXN][MAXN][2];
int ans;


bool onEdge(int x,int y)
{
    if(x==0 || y==0 || x==n-1 || y==m-1)
    {
        return 1;
    }
    return 0;
}

bool isValid(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    {
        return 0;
    }

    return 1;
}

void solve()
{
    queue<PIPIPII > q;

    q.push(MP(stx,MP(sty,MP(1,0))));
    int x,y,d,nx,ny;
    int fl;
    int ti;

    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second.first;
        d=q.front().second.second.first;
        fl=q.front().second.second.second;
        q.pop();



        if(dp[x][y][fl])
        {
            continue;
        }

        dp[x][y][fl]=d;

        //printf("%d\t%d\t%d\t%d\n",x,y,fl,d);

        if(onEdge(x,y))
        {

            ans=d;
            return;
        }

        for(int i=0;i<4;++i)
        {
            ti=fl;
            nx=x+dx[i];
            ny=y+dy[i];

            if(!isValid(nx,ny))
            {
                continue;
            }

            if(arr[nx][ny]=='W')
            {
                continue;
            }

            if(arr[nx][ny]=='O')
            {
                ti=1;
            }
            else if(arr[nx][ny]=='C')
            {
                ti=0;
            }
            else if(arr[nx][ny]=='D')
            {
                if(ti==0)
                {
                    continue;
                }
            }

            q.push(MP(nx,MP(ny,MP(d+1,ti))));
        }
    }
}

int main()
{
    freopen("Text/ESCJAILA.txt","r",stdin);

    while(true)
    {
        scanf("%d %d",&n,&m);
        if(n==-1)
        {
            break;
        }
        ans=0;
        MSET(dp,0);

        for(int i=0;i<n;++i)
        {
            scanf("%s",&arr[i]);
            for(int j=0;j<m;++j)
            {
                if(arr[i][j]=='H')
                {
                    stx=i;
                    sty=j;
                    arr[i][j]='.';
                    break;
                }
            }
        }

        solve();

        if(!ans)
        {
            --ans;
        }

        printf("%d\n",ans);
    }

    return 0;
}
