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



inline i64 readPosLLD()
{
    i64 ret=0;
    char c;
    c=gc();

    while(c!=EOF && (c<'0' || c>'9'))
    {
        //scanf("%c",&c);
        c=gc();
        //printf("DD\n");
    }

    while((c>='0' && c<='9'))
    {
        ret=ret*10+(c-'0');
        c=gc();
        //printf("MM\n");
    }

    return ret;
}

#define MAXN 105
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int r,c;
bool found;

char target[]="ALLIZZWELL\0";
int tlen;

void dfs(int x,int y,int pos)
{
    if(found)
    {
        return;
    }

    if(pos==tlen)
    {
        found=true;
        return;
    }

    if(vis[x][y])
    {
        return;
    }

    if(a[x][y]!=target[pos])
    {
        return;
    }

    if(pos==(tlen-1))
    {
        found=true;
        return;
    }

    vis[x][y]=true;

    if(x-1>=0)
    {
        if(y-1>=0)
        {
            dfs(x-1,y-1,pos+1);
        }

        dfs(x-1,y,pos+1);

        if(y+1<c)
        {
            dfs(x-1,y+1,pos+1);
        }
    }

    if(y+1<c)
    {
        dfs(x,y+1,pos+1);

        if(x+1<r)
        {
            dfs(x+1,y+1,pos+1);
        }
    }

    if(x+1<r)
    {
        dfs(x+1,y,pos+1);

        if(y-1>=0)
        {
            dfs(x+1,y-1,pos+1);
        }
    }

    if(y-1>=0)
    {
        dfs(x,y-1,pos+1);
    }


    //if(a[x][y]!='I' && a[x][y]!='W' && a[x][y]!='E')
    {
        vis[x][y]=false;
    }
}

int main()
{

    freopen("Text/ALLIZWEL.txt","r",stdin);
    int cases,i,j;

    scanf("%d",&cases);
    tlen=strlen(target);
    //printf("%d\n",tlen);
    while(cases--)
    {
        MSET(vis,0);
        found=false;

        scanf("%d %d",&r,&c);

        REP(i,r)
        {
            scanf("%s",&a[i]);
            //printf("%s\n",a[i]);
        }
        //scanf("\n");

        REP(i,r)
        {
            REP(j,c)
            {
                if(a[i][j]=='A')
                {
                    dfs(i,j,0);

                    if(found)
                    {
                        break;
                    }
                }
            }
        }

        if(found)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

	return 0;
}
