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

char arr[MAXX][MAXX];

VI co;
int stx,sty,enx,eny;
int h,w;

int vis[MAXX][MAXX][4];


bool is_valid(int x,int y)
{
    if(x<0 || x>=h || y<0 || y>=w || arr[x][y]=='*')
    {
        return false;
    }

    return true;
}


int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


void solve()
{
    int ret=0;

    stx=co[0];
    sty=co[1];
    enx=co[2];
    eny=co[3];

    priority_queue< PIPIPII > q;
    q.push(MP(0,MP(stx,MP(sty,0))));
    q.push(MP(0,MP(stx,MP(sty,1))));
    q.push(MP(0,MP(stx,MP(sty,2))));
    q.push(MP(0,MP(stx,MP(sty,3))));

    int dist,x,y,dir;


    while(!q.empty())
    {

        dist=-q.top().first;
        x=q.top().second.first;
        y=q.top().second.second.first;
        dir=q.top().second.second.second;
        q.pop();

        if(vis[x][y][dir])
        {
            continue;
        }

        vis[x][y][dir]=true;

        if(x==enx && y==eny)
        {
            ret=dist;
            break;
        }


        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(!is_valid(nx,ny))
            {
                continue;
            }

            if(i==0)
            {
                if(dir==2)
                {
                    continue;
                }

                if(dir==0)
                {
                    q.push(MP(-dist,MP(nx,MP(ny,i))));
                    continue;
                }

                q.push(MP(-(dist+1),MP(nx,MP(ny,i))));
                continue;

            }
            else if(i==1)
            {
                if(dir==3)
                {
                    continue;
                }


                if(dir==1)
                {
                    q.push(MP(-dist,MP(nx,MP(ny,i))));
                    continue;
                }

                q.push(MP(-(dist+1),MP(nx,MP(ny,i))));
                continue;

            }
            else if(i==2)
            {
                if(dir==0)
                {
                    continue;
                }


                if(dir==2)
                {
                    q.push(MP(-dist,MP(nx,MP(ny,i))));
                    continue;
                }

                q.push(MP(-(dist+1),MP(nx,MP(ny,i))));
                continue;
            }
            else if(i==3)
            {
                if(dir==1)
                {
                    continue;
                }

                if(dir==3)
                {
                    q.push(MP(-dist,MP(nx,MP(ny,i))));
                    continue;
                }

                q.push(MP(-(dist+1),MP(nx,MP(ny,i))));
                continue;
            }


        }


    }


    printf("%d\n",ret);
}


int main(){

    freopen("Text/MLASERP.txt","r",stdin);

    scanf("%d %d",&w,&h);

    for(int i=0;i<h;++i)
    {
        scanf("%s",&arr[i]);

        for(int j=0;j<w;++j)
        {
            if(arr[i][j]=='C')
            {
                co.PB(i);
                co.PB(j);
            }
        }
    }

    solve();

    return 0;
}
