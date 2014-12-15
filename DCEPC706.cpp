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

#define MAXN 205
#define INF 0x7f7f7f7f
int arr[MAXN][MAXN];
char buff[MAXN];
int x11,y11,x22,y22,x33,y33;
int n,m;
int ans;
int distt[3][MAXN][MAXN];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


inline bool isValid(int x,int y)
{
    if(x<0 || y<0 || x>m || y>n || arr[x][y]==1)
    {
        return 0;
    }

    return 1;
}

void djikstra(int pos,int stx,int sty)
{
    priority_queue<PIPII > pq;
    pq.push(MP(0,MP(stx,sty)));
    int nx,ny,x,y;
    int d;
    int i;

    while(!pq.empty())
    {
        d=-pq.top().first;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();
        //printf("%d\t%d\t%d\t%d\n",pos,d,x,y);

        if(distt[pos][x][y]<=d)
        {
            continue;
        }

        distt[pos][x][y]=d;

        for(i=0;i<4;++i)
        {
            nx=x+dx[i];
            ny=y+dy[i];

            if(!isValid(nx,ny))
            {
                continue;
            }

            pq.push(MP(-(d+1),MP(nx,ny)));
        }
    }
}

int main()
{
    freopen("Text/DCEPC706.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    int i,j;

    while(cases--)
    {
        MSET(distt,0x7f);
        ans=INF;
        MSET(arr,0);
        scanf("%d %d",&m,&n);

        for(i=1;i<=m;++i)
        {
            scanf("%s",buff+1);
            for(j=1;j<=n;++j)
            {
                if(buff[j]=='1')
                {
                    x11=i;
                    y11=j;
                }
                else if(buff[j]=='2')
                {
                    x22=i;
                    y22=j;
                }
                else if(buff[j]=='3')
                {
                    x33=i;
                    y33=j;
                }
                else if(buff[j]=='#')
                {
                    arr[i][j]=1;
                }
            }
        }
        ++n;
        ++m;

        djikstra(0,x11,y11);
        djikstra(1,x22,y22);
        djikstra(2,x33,y33);

        for(i=0;i<=m;++i)
        {
            for(j=0;j<=n;++j)
            {
                ans=min(ans,max(distt[0][i][j],max(distt[1][i][j],distt[2][i][j])));
            }
        }

        printf("%d\n",ans);
    }


    return 0;
}
