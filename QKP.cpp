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


#define MAXN 1001
#define MAXP 101

int board[MAXN][MAXN];
int queens[MAXP][2],knights[MAXP][2],pawns[MAXP][2];
int n,m,q,k,p,ct=0;


int qdx[]={-1,-1,-1,0,1,1,1,0};
int qdy[]={-1,0,1,1,1,0,-1,-1};

int kdx[]={-1,-2,-2,-1,1,2,2,1};
int kdy[]={-2,-1,1,2,2,1,-1,-2};

bool is_valid(int x, int y)
{
    if(x<0  || y<0  || x>=n  || y>=m  || board[x][y]==-1)
    {
        return false;
    }

    return true;
}

void  move_queen()
{
    int x,y;

    for(int i=0;i<q;++i)
    {
        for(int j=0;j<8;++j)
        {
            x=queens[i][0]+qdx[j];
            y=queens[i][1]+qdy[j];

            while(is_valid(x,y))
            {
                board[x][y]=1;
                x+=qdx[j];
                y+=qdy[j];
            }
        }
    }
}


void move_knight()
{
    int x,y;

    for(int i=0;i<k;++i)
    {
        for(int j=0;j<8;++j)
        {
            x=knights[i][0]+kdx[j];
            y=knights[i][1]+kdy[j];

            if(is_valid(x,y))
            {
                board[x][y]=1;
            }
        }
    }
}


void cntt()
{
    ct=0;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(board[i][j]==0)
            {
                ++ct;
            }
        }
    }
}


int main()
{
    freopen("Text/QKP.txt","r",stdin);

    int cases,x,y;
    int t=0;

    while(true)
    {
        ++t;
        scanf("%d %d",&n,&m);

        if(n==0  && m==0)
        {
            break;
        }

        MSET(board,0);
        ct=0;

        scanf("%d",&q);

        for(int i=0;i<q;++i)
        {
            scanf("%d %d",&x,&y);
            --x;
            --y;
            board[x][y]=-1;
            queens[i][0]=x;
            queens[i][1]=y;
        }


        scanf("%d",&k);

        for(int i=0;i<k;++i)
        {
            scanf("%d %d",&x,&y);
            --x;
            --y;
            board[x][y]=-1;
            knights[i][0]=x;
            knights[i][1]=y;
        }


        scanf("%d",&p);

        for(int i=0;i<p;++i)
        {
            scanf("%d %d",&x,&y);
            --x;
            --y;
            board[x][y]=-1;
            pawns[i][0]=x;
            pawns[i][1]=y;
        }

        move_queen();
        move_knight();
        cntt();

        printf("Board %d has %d safe squares.\n",t,ct);
    }



    return 0;
}
