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



#define MAX_FLOOR 1000005

int start_floor,end_floor,num_floors,up_dist,down_dist;
int elevator[MAX_FLOOR];


int go_up(int curr_floor)
{
    if(num_floors<curr_floor+up_dist)
    {
        return curr_floor;
    }

    return curr_floor+up_dist;

}

int go_down(int curr_floor)
{
    if(1>curr_floor-down_dist)
    {
        return curr_floor;
    }

    return curr_floor-down_dist;
}


void solve()
{
    queue< PII > returns_nearest;

    returns_nearest.push(MP(start_floor,0));
    int curr_floor;
    int curr_dist;

    int next_floor;

    while(!returns_nearest.empty() && elevator[end_floor]==-1)
    {
        curr_floor=returns_nearest.front().first;
        curr_dist=returns_nearest.front().second;
        returns_nearest.pop();

        if(elevator[curr_floor]!=-1)
        {
            continue;
        }

        elevator[curr_floor]=curr_dist;

        next_floor=go_down(curr_floor);

        if(elevator[next_floor]==-1)
        {
            returns_nearest.push(MP(next_floor,curr_dist+1));
        }

        next_floor=go_up(curr_floor);

        if(elevator[next_floor]==-1)
        {
            returns_nearest.push(MP(next_floor,curr_dist+1));
        }

    }
}

int main()
{
    freopen("Text/ELEVTRBL.txt","r",stdin);

    MSET(elevator,-1);
    scanf("%d %d %d %d %d",&num_floors,&start_floor,&end_floor,&up_dist,&down_dist);

    solve();

    if(elevator[end_floor]==-1)
    {
        printf("use the stairs\n");
    }
    else
    {
        printf("%d\n",elevator[end_floor]);
    }

    return 0;
}


