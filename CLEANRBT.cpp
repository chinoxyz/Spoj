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


#define MAXX 25
#define MAXR 1<<12
#define INF 999999999

int num_rows,num_cols;
char grid[MAXX][MAXX];

map< PII , int> dirty_map;
int robot_x,robot_y,num_dirty;
int dist[MAXX][MAXX];
int min_dist[MAXX][MAXX];
VI dirty_xs;
VI dirty_ys;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int subsets[MAXR][MAXX];

bool something_unreachable;


bool is_valid(int x,int y)
{
    if(x<0 || x>=num_rows || y<0 || y>=num_cols)
    {
        return false;
    }

    if(grid[x][y]=='x')
    {
        return false;
    }

    return true;
}

void bfs(int stx,int sty,int pos)
{
    MSET(min_dist,-1);
    queue< PIPII > que;
    que.push(MP(0,MP(stx,sty)));
    int curr_dist,curr_x,curr_y,nx,ny,i;

    while(!que.empty())
    {

        curr_dist=que.front().first;
        curr_x=que.front().second.first;
        curr_y=que.front().second.second;
        que.pop();
/*        if(stx==7 && sty==7)
        {
            printf("Q\t%d\t%d\t%d\n",curr_dist,curr_x,curr_y);
        }
*/
        if(min_dist[curr_x][curr_y]!=-1)
        {
            continue;
        }

        min_dist[curr_x][curr_y]=curr_dist;

        REP(i,4)
        {
            nx=curr_x+dx[i];
            ny=curr_y+dy[i];

            if(is_valid(nx,ny) && min_dist[nx][ny]==-1)
            {
                que.push(MP(curr_dist+1,MP(nx,ny)));
            }
        }
    }

    dist[pos][0]=min_dist[robot_x][robot_y];
    REP(i,num_dirty)
    {
        dist[pos][i+1]=min_dist[dirty_xs[i]][dirty_ys[i]];
        if(dist[pos][i+1]==-1)
        {
            something_unreachable=true;
            break;
        }
    }
}


int solve()
{
    MSET(subsets,-1);
    int ret=INF;

    int all_set=(1<<num_dirty)-1;
    int leftt,j,k,i;


    for(i=1;i<=all_set;++i)
    {
        for(j=0;j<num_dirty;++j)
        {
            if(i & (1<<j))
            {
                leftt=i^(1<<j);
                if(leftt==0)
                {
                    subsets[i][j]=dist[0][j+1];
                }
                else
                {
                    for(k=0;k<num_dirty;++k)
                    {
                        if(leftt & (1<<k))
                        {
                            if(subsets[leftt][k]!=-1 && dist[k+1][j+1]!=-1)
                            {
                                if(subsets[i][j]!=-1)
                                {
                                    subsets[i][j]=min(subsets[i][j],subsets[leftt][k]+dist[k+1][j+1]);
                                }
                                else
                                {
                                    subsets[i][j]=subsets[leftt][k]+dist[k+1][j+1];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //printf("SOLVE\n");
    REP(i,num_dirty)
    {
        //printf("%d\n",subsets[all_set][i]);
        if(subsets[all_set][i]!=-1)
        {
           ret=min(ret,subsets[all_set][i]);
        }
    }

    return ret;

}

int main()
{
    freopen("Text/CLEANRBT.txt","r",stdin);

    int i,j,ret;

    while(true)
    {
        ret=0;
        something_unreachable=false;
        num_dirty=0;
        dirty_xs.clear();
        dirty_ys.clear();
        //dirty_xs.PB(-1);
        //dirty_ys.PB(-1);
        dirty_map.clear();

        scanf("%d %d",&num_cols,&num_rows);
        //printf("R\t%d\tC\t%d\n",num_rows,num_cols);

        if(num_rows==0 && num_cols==0)
        {
            break;
        }

        REP(i,num_rows)
        {
            scanf("%s",grid[i]);
            //printf("Grid\t%s\n",grid[i]);
            REP(j,num_cols)
            {
                if(grid[i][j]=='o')
                {
                    robot_x=i;
                    robot_y=j;
                }
                else if(grid[i][j]=='*')
                {
                    dirty_map[MP(i,j)]=num_dirty;
                    dirty_xs.PB(i);
                    dirty_ys.PB(j);
                    ++num_dirty;
                }
            }
        }
        //printf("RobX\t%d\tRobY\t%d\n",robot_x,robot_y);

        bfs(robot_x,robot_y,0);
        if(!something_unreachable)
        {
            REP(i,num_dirty)
            {
                bfs(dirty_xs[i],dirty_ys[i],i+1);
            }

            if(num_dirty>0)
            {
                ret=solve();
            }

            if(ret==INF)
            {
                ret=-1;
            }
        }
        else
        {
            ret=-1;
        }
/*
        printf("Num_Dirty\t%d\n",num_dirty);
        REP(i,num_dirty)
        {
            printf("%d\t%d\t%d\n",i+1,dirty_xs[i],dirty_ys[i]);
        }
        printf("\n");

        printf("DIST\n");
        for(i=0;i<=num_dirty;++i)
        {
            for(j=0;j<=num_dirty;++j)
            {
                printf("%d\t",dist[i][j]);
            }
            printf("\n");
        }

        printf("ANS\t%d\n",ret);
        printf("\n\n\n\n");
*/

        printf("%d\n",ret);
    }


    return 0;
}



