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

//#define gc getchar_unlocked
#define gc getchar

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}


#define MAXN 100002

int gp[MAXN];
int vis[MAXN];
set<int> ss[MAXN];
set<int>::iterator sit;
int p,r;
int ret;
int tx,ty;
int vp[MAXN];


inline int findd(int x)
{
    if(x!=gp[x])
    {
        gp[x]=findd(gp[x]);
    }
    return gp[x];
}

inline void insertt(int ti1,int ti2)
{
    gp[ti1]=gp[ti2];

    if(vp[ti1])
    {
        vp[ti2]=1;
    }

}


inline void incc()
{
    ++ret;
    //printf("INCCCCCC\t%d\t%d\n",tx,ty);
}

inline void upp(int y)
{
    int ti1,ti2;
    ti2=findd(y);

    vp[ti2]=1;
}


inline void solve(int x,int y)
{
    tx=x;
    ty=y;
    int ti1,ti2;

    if(x<=1 && y<=1)
    {
        //incc();
        return;
    }

    if(x==y)
    {
        incc();
        return;
    }

    ti1=findd(x);
    ti2=findd(y);

    if(x==1)
    {
        if(vis[y] || vp[ti2])
        {
            incc();
        }
        else
        {
            upp(y);
        }

        return;
    }
    else if(y==1)
    {
        if(vis[x] || vp[ti1])
        {
            incc();
        }
        else
        {
            upp(x);
        }
        return;
    }



    if(ti1==ti2)
    {
        incc();
        return;
    }
    else
    {
        if( (vis[x] || vp[ti1]) && (vis[y] || vp[ti2]))
        {
            incc();
            return;
        }

        if(vis[x] || vp[ti1])
        {
            vis[y]=1;

            upp(y);

        }
        else if(vis[y] || vp[ti2])
        {
            vis[x]=1;

            upp(x);
        }
    }

    insertt(ti1,ti2);
}

int main()
{
    freopen("Text/SQDANCE.txt","r",stdin);
    int cases;

    //scanf("%d",&cases);
    cases=readPosInt();

    int x,y;
    int i;

    while(cases--)
    {
        //MSET(vis,0);


        ret=0;
        //scanf("%d %d",&p,&r);
        p=readPosInt();
        r=readPosInt();

        for(i=1;i<=p;++i)
        {
            gp[i]=i;
            vis[i]=0;
            //ss[i].clear();
            //ss[i].insert(i);
            vp[i]=0;
        }

        for(i=0;i<r;++i)
        {
            //printf("DD\n");
            //scanf("%d %d",&x,&y);
            x=readPosInt();
            y=readPosInt();

            solve(x,y);
        }

        printf("%d\n",ret);
    }


    return 0;
}
