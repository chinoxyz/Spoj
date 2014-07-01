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

i64 n;

vector<vector<i64> > gr;
bool *vis;
i64 ret=0;

void dfs(int node)
{
    if(vis[node])
    {
        return;
    }
    vis[node]=true;
    i64 i,sz;
    sz=gr[node].size();

    REP(i,sz)
    {
        dfs(gr[node][i]);
    }
}

int main()
{

    freopen("Text/CAM5.txt","r",stdin);
    i64 cases,i,j,fr,x,y;
    scanf("%lld",&cases);

    while(cases--)
    {
        gr.clear();
        scanf("%lld",&n);
        REP(i,n)
        {
            gr.PB(vector<i64>());
        }

        vis=new bool[n];
        memset(vis,0,n*sizeof(bool));

        scanf("%lld",&fr);

        REP(i,fr)
        {
            scanf("%lld %lld",&x,&y);
            gr[x].PB(y);
            gr[y].PB(x);
        }

        ret=0;
        REP(i,n)
        {
            if(!vis[i])
            {
                ++ret;
                dfs(i);
            }
        }

        delete vis;

        printf("%lld\n",ret);
    }

	return 0;
}
