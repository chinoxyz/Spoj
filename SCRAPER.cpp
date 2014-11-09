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


#define MAXF 50000000
int par[MAXF];
int e,a,b,f;

inline int findd(int x)
{
    if(par[x]!=x)
    {
        par[x]=findd(par[x]);
    }

    return par[x];
}

int main()
{
    freopen("Text/SCRAPER.txt","r",stdin);
    int x,y;
    int cases;
    int px,py;

    //scanf("%d",&cases);
    cases=readPosInt();
    int i,j;
    bool poss;

    while(cases--)
    {
        //scanf("%d %d %d %d",&f,&e,&a,&b);
        f=readPosInt();
        e=readPosInt();
        a=readPosInt();
        b=readPosInt();
        poss=false;

        for(i=0;i<f;++i)
        {
            par[i]=i;
        }

        for(i=0;i<e;++i)
        {
            //scanf("%d %d",&x,&y);
            x=readPosInt();
            y=readPosInt();

            py=findd(y);

            for(j=x+y;j<f;j+=x)
            {
                px=findd(j);
                par[px]=py;
            }

            px=findd(a);
            py=findd(b);
            if(px==py)
            {
                poss=true;
                break;
            }
        }

        if(poss)
        {
            printf("It is possible to move the furniture.\n");
        }
        else
        {
            printf("The furniture cannot be moved.\n");
        }
    }



    return 0;
}
