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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
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


#define MAXN 101
#define MAXM 100002
#define INF 99999999
#define MAXR m
int n;
int arr[MAXN][6];
int ans=0;
int m;



inline int calc(int pos,int ct)
{
    int req=ct*arr[pos][0];
    int av=arr[pos][1];
    if(req<=av)
    {
        return 0;
    }

    int diff=req-av;
    int ret=INF;
    int i,sz,mon;
    int j;

    for(i=0;;++i)
    {
        //printf("DD\t%d\t%d\n",i,pos);
        sz=i*arr[pos][2];
        mon=i*arr[pos][3];
        if(sz>=diff)
        {
            ret=min(ret,mon);
            break;
        }

        j=ceil((diff-sz)/(double)arr[pos][4]);
        mon+=j*arr[pos][5];
        ret=min(ret,mon);
    }

    return ret;
}

inline bool tryy(int numm)
{
    //printf("%d\n",numm);
    int ret=0;
    int i;
    for(i=0;i<n;++i)
    {
        ret+=calc(i,numm);
    }

    return (ret<=m);
}

void solve()
{
    int l=0;
    int r=MAXR;
    int midd;

    while(l<r)
    {
        midd=(l+r+1)>>1;
        if(tryy(midd))
        {
            l=midd;
        }
        else
        {
            r=midd-1;
        }
    }

    ans=l;
}


void MAIN()
{
    //scanf("%d %d",&n,&m);
    n=readPosInt();
    m=readPosInt();
    int i,j;

    for(i=0;i<n;++i)
    {
        for(j=0;j<6;++j)
        {
            //scanf("%d",&arr[i][j]);
            arr[i][j]=readPosInt();
        }
    }

    solve();

    printf("%d\n",ans);
}

int main()
{
	freopen("Text/MKUHAR.txt","r",stdin);

    MAIN();

	return 0;
}

