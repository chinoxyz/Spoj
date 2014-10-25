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

bool presentt[MAXN];
int arr[MAXN][MAXN];
int validd[MAXN];

int dx[]={-1,0,1,1,-1,-1,0,1};
int dy[]={1,1,1,0,0,-1,-1,-1};

int n,m;

bool is_valid(int x,int y)
{
    if(x<0 || y<0 ||x>=n || y>=m || arr[x][y]==-1)
    {
        return false;
    }
    return true;
}



int main()
{
    freopen("Text/CONHONPR.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&m);
        MSET(presentt,0);
        MSET(validd,0);
        MSET(arr,0);

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                scanf("%d",&arr[i][j]);
                if(arr[i][j]>=0)
                {
                    presentt[arr[i][j]]=1;
                }
            }
        }

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(!is_valid(i,j))
                {
                    continue;
                }

                for(int k=0;k<8;++k)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];

                    if(!is_valid(nx,ny))
                    {
                        continue;
                    }

                    if(arr[i][j]==arr[nx][ny])
                    {
                        validd[arr[i][j]]=1;
                    }
                }
            }
        }

        int ans=0;

        for(int i=0;i<MAXN;++i)
        {
            if(presentt[i] && validd[i])
            {
                ++ans;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
