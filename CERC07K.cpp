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

#define MAXX 105

char grid[MAXX][MAXX];

bool vis[MAXX][MAXX][16];
int stx,sty;

int r,c;
bool poss;


bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=r || y>=c || grid[x][y]=='#')
    {
        return false;
    }

    return true;
}

int door(int x,int y)
{
    switch(grid[x][y])
    {
        case 'G' :
            return 0;

        case 'R' :
            return 1;

        case 'Y' :
            return 2;

        case 'B' :
            return 3;

        default :
            return -1;
    }
}


int keyy(int x,int y)
{
    switch(grid[x][y])
    {
        case 'g' :
            return 0;

        case 'r' :
            return 1;

        case 'y' :
            return 2;

        case 'b' :
            return 3;

        default :
            return -1;
    }
}


bool is_emp_end(int x,int y)
{
    return (grid[x][y]=='.' || grid[x][y]=='X' || grid[x][y]=='*');
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


int solve()
{
    int ret=-1;

    queue<PIPIPII > que;

    que.push(MP(0,MP(stx,MP(sty,0))));

    int dist,x,y,keys;

    while(!que.empty())
    {
        dist=que.front().first;
        x=que.front().second.first;
        y=que.front().second.second.first;
        keys=que.front().second.second.second;
        que.pop();

        //printf("%d\t%d\t%d\t%d\n",dist,x,y,keys);


        if(vis[x][y][keys])
        {
            continue;
        }

        if(grid[x][y]=='X')
        {
            ret=dist;
            break;
        }





        vis[x][y][keys]=true;


        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(!is_valid(nx,ny))
            {
                continue;
            }

            if(is_emp_end(nx,ny))
            {
                que.push(MP(dist+1,MP(nx,MP(ny,keys))));
                continue;
            }

            int k=keyy(nx,ny);
            if(k!=-1)
            {
                int tkeys=keys;
                tkeys|=(1<<k);
                que.push(MP(dist+1,MP(nx,MP(ny,tkeys))));
                continue;
            }


            k=door(nx,ny);

            if(k!=-1)
            {
                if((keys&(1<<k)))
                {
                    que.push(MP(dist+1,MP(nx,MP(ny,keys))));
                    continue;
                }
            }

        }
    }



    return ret;
}

int main() {

    freopen("Text/CERC07K.txt","r",stdin);
    int i,j;

    while(true)
    {
        scanf("%d %d",&r,&c);
        //printf("\n\n\n\n");

        if(r==0 || c==0)
        {
            break;
        }

        MSET(vis,0);
        poss=false;

        REP(i,r)
        {
            scanf("%s",&grid[i]);
            REP(j,c)
            {
                if(grid[i][j]=='*')
                {
                    stx=i;
                    sty=j;
                }
                else if(grid[i][j]=='X')
                {
                    poss=true;
                }
            }
        }

        if(!poss)
        {
            //printf("DD\n");
            printf("The poor student is trapped!\n");
        }
        else
        {
            int ret=solve();
            if(ret==-1)
            {
                printf("The poor student is trapped!\n");
            }
            else
            {
                printf("Escape possible in %d steps.\n",ret);
            }
        }

    }


    return 0;
}
