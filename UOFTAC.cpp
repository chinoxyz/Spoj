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
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
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

#define MAXH 105
char arr[MAXH][MAXH];
int h,w;
int n;
char buff[55];
int ans=0;

int DX(char c)
{
    if(c=='L')
    {
        return 0;
    }

    if(c=='R')
    {
        return 0;
    }

    if(c=='D')
    {
        return 1;
    }
}


int DY(char c)
{
    if(c=='L')
    {
        return -1;
    }

    if(c=='R')
    {
        return 1;
    }

    if(c=='D')
    {
        return 0;
    }
}

bool isValid(int x,int y)
{
    if(x<0 || y<1 || x>h || y>w)
    {
        return 0;
    }

    return 1;
}

bool isBelowEmpty(int x,int y)
{
    if(x>=h)
    {
        return 0;
    }

    if(arr[x+1][y]=='E')
    {
        return 1;
    }

    return 0;
}

void solve()
{
    ans=0;
    int x=0,y=1;
    int nx,ny;

    for(int i=0;i<n;++i)
    {
        scanf("%s",buff);
        nx=x;
        ny=y;
        nx+=DX(buff[0]);
        ny+=DY(buff[0]);

        if(!isValid(nx,ny))
        {
            continue;
        }

        if(nx>0)
        {
            if(arr[nx][ny]=='S')
            {
                continue;
            }
            else if(arr[nx][ny]=='T')
            {
                ++ans;
                arr[nx][ny]='D';
            }
        }

        while(isBelowEmpty(nx,ny))
        {
            ++nx;
        }

        x=nx;
        y=ny;
    }
}


void MAIN()
{
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&h,&w,&n);
        for(int i=1;i<=h;++i)
        {
            scanf("%s",&arr[i][1]);
        }

        solve();
        printf("%d\n",ans);
    }
}

int main()
{
	freopen("Text/UOFTAC.txt","r",stdin);

    MAIN();

	return 0;
}

