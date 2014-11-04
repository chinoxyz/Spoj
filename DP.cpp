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


#define MAXN 55
#define INF 0x7f7f7f7f

char arr[MAXN][MAXN];

VI xx;
VI yy;
int tot;
int n,m;

int distt[MAXN][MAXN];

bool poss;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
VI tarr;
int ans;
int stx,sty;


int distancee(int x1,int y1,int x2,int y2)
{

    if(x2<0 || y2<0 || x2>=n || y2>=m || distt[x2][y2]<INF)
    {
        return 0;
    }

    if(arr[x1][y1]!='$')
    {
        if(arr[x2][y2]!='$')
        {
            int diff=abs(arr[x1][y1]-arr[x2][y2]);
            if(diff>1)
            {
                return 0;
            }

            if(diff==0)
            {
                return 1;
            }

            return 3;
        }
    }

    return 2;

}


void solve()
{
    tarr.clear();
    poss=true;
    MSET(distt,0x7f);

    priority_queue<PIPII > pq;
    int td;
    int x,y;
    pq.push(MP(-0,MP(stx,sty)));
    int ti;

    while(!pq.empty())
    {
        td=-pq.top().first;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();

        if(distt[x][y]<INF)
        {
            continue;
        }

        distt[x][y]=td;

        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            ti=distancee(x,y,nx,ny);

            if(!ti)
            {
                continue;
            }

            pq.push(MP(-(ti+td),MP(nx,ny)));
        }
    }

    for(int i=0;i<tot;++i)
    {
        if(distt[xx[i]][yy[i]]==INF)
        {
            poss=false;
            break;
        }
        tarr.PB(distt[xx[i]][yy[i]]<<1);
    }

    ans=INF;

    if(poss)
    {
        int s1,s2;
        int l1,l2;

        for(int i=0;i<(1<<tot);++i)
        {
            s1=s2=0;
            l1=l2=-1;
            for(int j=0;j<tot;++j)
            {
                if(i&(1<<j))
                {
                    s1+=tarr[j];
                    l1=max(l1,tarr[j]/2);
                }
                else
                {
                    s2+=tarr[j];
                    l2=max(l2,tarr[j]/2);
                }
            }

            if(l1!=-1)
            {
                s1-=l1;
            }

            if(l2!=-1)
            {
                s2-=l2;
            }


            ans=min(ans,max(s1,s2));
        }
    }
    else
    {
        ans=-1;
    }

    printf("%d\n",ans);
}


int main()
{
    freopen("Text/DP.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        xx.clear();
        yy.clear();
        tot=0;
        scanf("%d %d",&n,&m);

        for(int i=0;i<n;++i)
        {
            scanf("%s",&arr[i]);
            for(int j=0;j<m;++j)
            {
                if(arr[i][j]=='X')
                {
                    arr[i][j]='$';
                    stx=i;
                    sty=j;
                }
                else if(arr[i][j]=='$')
                {
                    xx.PB(i);
                    yy.PB(j);
                    ++tot;
                }
            }
        }

        solve();
    }





    return 0;
}

