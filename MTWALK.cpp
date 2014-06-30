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

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}



//#define gc getchar_unlocked
#define gc getchar



inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}


#define MAXN 120


int a[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool mark[MAXN][MAXN][MAXN][MAXN];
int n,nm1;
int ans;

inline void dfs(int x,int y,int mn,int mx)
{

    if(mark[x][y][mn][mx])
    {
        return;
    }

    mark[x][y][mn][mx]=true;

    int tmn,tmx,tx,ty;
    int diff=mx-mn;
    if(diff>=ans)
    {
        return;
    }

    if(x==nm1 && y==nm1)
    {
        //printf("DD\t%d\t%d\n",x,y);
        if(diff<ans)
        {
            ans=diff;
        }

        return;
    }

    vis[x][y]=true;

    tx=x-1;
    if(tx>=0 && !vis[tx][y])
    {
        tmn=mn;
        tmx=mx;

        if(a[tx][y]<mn)
        {
            tmn=a[tx][y];
        }
        else if(a[tx][y]>mx)
        {
            tmx=a[tx][y];
        }
        dfs(tx,y,tmn,tmx);
    }


    tx=x+1;
    if(tx<n && !vis[tx][y])
    {
        tmn=mn;
        tmx=mx;

        if(a[tx][y]<mn)
        {
            tmn=a[tx][y];
        }
        else if(a[tx][y]>mx)
        {
            tmx=a[tx][y];
        }
        dfs(tx,y,tmn,tmx);
    }

    ty=y-1;
    if(ty>=0 && !vis[x][ty])
    {
        tmn=mn;
        tmx=mx;

        if(a[x][ty]<mn)
        {
            tmn=a[x][ty];
        }
        else if(a[x][ty]>mx)
        {
            tmx=a[x][ty];
        }
        dfs(x,ty,tmn,tmx);
    }


    ty=y+1;
    if(ty<n && !vis[x][ty])
    {
        tmn=mn;
        tmx=mx;

        if(a[x][ty]<mn)
        {
            tmn=a[x][ty];
        }
        else if(a[x][ty]>mx)
        {
            tmx=a[x][ty];
        }
        dfs(x,ty,tmn,tmx);
    }


    vis[x][y]=false;;
}

int main()
{
    //MSET(a,0);
    //MSET(vis,0);

    freopen("Text/MTWALK.txt","r",stdin);
    int i,j;
    //scanf("%d",&n);
    n=readPosInt();

    REP(i,n)
    {
        REP(j,n)
        {
            //scanf("%d",&a[i][j]);
            a[i][j]=readPosInt();
        }
    }
    nm1=n-1;
    ans=MAXN;

    vis[0][0]=true;
    //mark[0][0][a[0][0]][a[0][0]]=true;
    dfs(0,0,a[0][0],a[0][0]);

    printf("%d\n",ans);

	return 0;
}
