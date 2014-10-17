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
#define PIPIPIPII pair< int, PIPIPII >
#define PCPIPIPIPII pair< char, PIPIPIPII >

#define u64 unsigned i64


#define MAXN 505

char arr[MAXN][MAXN];
bool pree[MAXN][MAXN];
int vis[MAXN][MAXN];
int r,c;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=r || y>=c || arr[x][y]=='#')
    {
        return false;
    }

    return true;
}

void solve()
{

    queue<PCPIPIPIPII > q;

    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            if(arr[i][j]>='a' && arr[i][j]<='z')
            {
                q.push(MP(arr[i][j],MP(0,MP(i,MP(j,MP(i,j))))));
            }
        }
    }

    char curr;
    int lenn,x,y,prex,prey,nx,ny;

    while(!q.empty())
    {
        curr=q.front().first;
        lenn=q.front().second.first;
        x=q.front().second.second.first;
        y=q.front().second.second.second.first;

        prex=q.front().second.second.second.second.first;
        prey=q.front().second.second.second.second.second;

        q.pop();



        if(pree[prex][prey])
        {
            continue;
        }

        if(lenn>vis[x][y])
        {
            continue;
        }

        if(lenn==vis[x][y])
        {
            if(arr[x][y]==curr)
            {
                continue;
            }
            else
            {
                arr[x][y]='*';
                pree[x][y]=1;
                continue;
            }
        }

        vis[x][y]=lenn;
        arr[x][y]=curr;

        for(int i=0;i<4;++i)
        {
            nx=x+dx[i];
            ny=y+dy[i];

            if(!is_valid(nx,ny))
            {
                continue;
            }

            q.push(MP(curr,MP(lenn+1,MP(nx,MP(ny,MP(x,y))))));
        }
    }
}


int main()
{
    freopen("Text/AMR11J.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&r,&c);
        MSET(vis,0x7f);
        MSET(pree,0);

        for(int i=0;i<r;++i)
        {
            scanf("%s",&arr[i]);
        }

        solve();

        for(int i=0;i<r;++i)
        {
            printf("%s\n",arr[i]);
        }
        printf("\n");
    }


    return 0;
}
