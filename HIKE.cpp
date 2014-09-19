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


#define MAXN 55

char grid[MAXN][MAXN];
bool mp[MAXN][MAXN][MAXN];
int st1,st2,st3,n;


int solve()
{
    int ret=-1;

    queue< PIPIPII > que;

    que.push(MP(0,MP(st1,MP(st2,st3))));
    int curr_dist;
    int pos1,pos2,pos3;

    while(!que.empty())
    {
        curr_dist=que.front().first;
        pos1=que.front().second.first;
        pos2=que.front().second.second.first;
        pos3=que.front().second.second.second;
        que.pop();
        //printf("%d\t%d\t%d\t%d\n",curr_dist,pos1,pos2,pos3);

        if(mp[pos1][pos2][pos3])
        {
            continue;
        }

        if(pos1==pos2 && pos2==pos3 && pos3==pos1)
        {
            ret=curr_dist;
            break;
        }



        mp[pos1][pos2][pos3]=true;

        for(int i=0;i<n;++i)
        {
            if(grid[pos1][i]==grid[pos2][pos3])
            {
                que.push(MP(curr_dist+1,MP(i,MP(pos2,pos3))));
            }

            if(grid[pos2][i]==grid[pos1][pos3])
            {
                que.push(MP(curr_dist+1,MP(pos1,MP(i,pos3))));
            }

            if(grid[pos3][i]==grid[pos1][pos2])
            {
                que.push(MP(curr_dist+1,MP(pos1,MP(pos2,i))));
            }
        }
    }

    return ret;
}

int main() {

    freopen("Text/HIKE.txt","r",stdin);

    int i,j;
    char ch;
    char buff[10];

    while(true)
    {
        scanf("%d",&n);
        //cin>>n;
        if(n==0)
        {
            break;
        }


        MSET(mp,0);

        scanf("%d %d %d",&st1,&st2,&st3);
        //cin>>st1>>st2>>st3;
        --st1;
        --st2;
        --st3;
        //printf("%d %d %d\n",st1,st2,st3);

        REP(i,n)
        {
            REP(j,n)
            {
                //scanf("%c",&grid[i][j]);
                //cin>>grid[i][j];
                scanf("%s",buff);
                grid[i][j]=buff[0];
                //cout<<grid[i][j]<<endl;
                //cout<<edge_via_color[i][grid[i][j]-'a']<<endl;
            }
        }

        //printf("%d\n",solve());
        int ret=solve();

        if(ret==-1)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n",ret);
        }
    }

    return 0;
}
