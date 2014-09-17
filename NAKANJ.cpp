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



#define INF 999999999

int min_dist[8][8][8][8];

int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1,1,2,2,1,-1,-2};

bool is_valid(int x,int y)
{
    if(x<0 || x>=8 || y<0 ||y>=8)
    {
        return false;
    }

    return true;
}

int main() {

    freopen("Text/NAKANJ.txt","r",stdin);

    //MSET(min_dist,INF);
    int nx,ny,i,j,k,l,m,n;
    int cases;

    for(k=0;k<8;++k)
    {
        for(l=0;l<8;++l)
        {
            for(i=0;i<8;++i)
            {
                for(j=0;j<8;++j)
                {
                    if(k==i && l==j)
                    {
                        min_dist[k][l][i][j]=0;
                    }
                    else
                    {
                        min_dist[k][l][i][j]=INF;
                    }
                }
            }
        }
    }

    for(i=0;i<8;++i)
    {
        for(j=0;j<8;++j)
        {
            for(k=0;k<8;++k)
            {
                nx=i+dx[k];
                ny=j+dy[k];
                if(is_valid(nx,ny))
                {
                    min_dist[i][j][nx][ny]=1;
                }
            }
        }
    }


    for(k=0;k<8;++k)
    {
        for(l=0;l<8;++l)
        {
            for(i=0;i<8;++i)
            {
                for(j=0;j<8;++j)
                {
                    for(m=0;m<8;++m)
                    {
                        for(n=0;n<8;++n)
                        {
                            min_dist[i][j][m][n]=min(min_dist[i][j][m][n],min_dist[i][j][k][l]+min_dist[k][l][m][n]);
                        }
                    }
                }
            }
        }
    }

    scanf("%d",&cases);
    char pos1[10],pos2[10];

    while(cases--)
    {
        scanf("%s %s",pos1,pos2);
        printf("%d\n",min_dist[pos1[1]-'1'][pos1[0]-'a'][pos2[1]-'1'][pos2[0]-'a']);
    }



    return 0;
}
