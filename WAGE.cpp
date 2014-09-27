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



#define MAXN 102

char src[MAXN][MAXN],dest[MAXN][MAXN];


int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int r,c,n;

bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=r || y>=c)
    {
        return false;
    }

    return true;
}


void solve()
{
    int nx,ny;
    for(int k=0;k<n;++k)
    {
        memcpy(dest,src,sizeof(dest));
        for(int x=0;x<r;++x)
        {
            for(int y=0;y<c;++y)
            {
                for(int l=0;l<4;++l)
                {
                    nx=x+dx[l];
                    ny=y+dy[l];

                    if(!is_valid(nx,ny))
                    {
                        continue;
                    }

                    if(src[x][y]=='W')
                    {
                        if(src[nx][ny]=='A')
                        {
                            dest[nx][ny]='W';
                        }
                    }
                    else if(src[x][y]=='A')
                    {
                        if(src[nx][ny]=='G')
                        {
                            dest[nx][ny]='A';
                        }
                    }
                    else
                    {
                        if(src[nx][ny]=='W')
                        {
                            dest[nx][ny]='G';
                        }
                    }
                }
            }
        }

        memcpy(src,dest,sizeof(src));
    }

}


int main()
{
    freopen("Text/WAGE.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&r,&c,&n);

        for(int i=0;i<r;++i)
        {
            scanf("%s",&src[i]);
        }

        solve();

        for(int i=0;i<r;++i)
        {
            printf("%s\n",src[i]);
        }
        //printf("\n");
    }

    return 0;
}
