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
#define Vi64 veszor<i64>
#define Vu64 veszor<u64>

#define MAXN 100008
#define MAXD 100
#define INF 99999999

char a[MAXN],b[MAXN];
int dp[3][MAXN];
int mod[MAXN];
int k,l;


void MAIN()
{
    int i,j,st,en,ti;
    int ti2;

    int x,y,z;

    for(i=0;i<MAXN;++i)
    {
        mod[i]=i%3;
    }

    scanf("%d %d",&k,&l);

    scanf("%s %s",a,b);

    for(i=0;i<=l;++i)
    {
        dp[0][i]=i;
    }

    x=1;
    y=2;
    z=0;


    for(i=1;i<=k;++i)
    {
        ti2=x;
        x=y;
        y=z;
        z=ti2;

        en=min(l,i+MAXD);
        st=max(0,i-MAXD);

        for(j=st;j<=en;++j)
        {
            ti=INF;

            if(i>0)
            {
                ti=min(ti,dp[y][j]+1);
            }

            if(j>0)
            {
                ti=min(ti,dp[z][j-1]+1);
            }

            if(i>0 && j>0)
            {
                if(a[i-1]==b[j-1])
                {
                    ti=min(ti,dp[y][j-1]);
                }
                else
                {
                    ti=min(ti,dp[y][j-1]+1);
                }
            }

            if(i>1 && j>1)
            {
                if(a[i-1]==b[j-2] && a[i-2]==b[j-1])
                {
                    ti=min(ti,dp[x][j-2]+1);
                }
            }
            dp[z][j]=ti;
        }


    }

    printf("%d\n",dp[mod[k]][l]);

}

int main()
{
	freopen("Text/STRDIST.txt","r",stdin);

    MAIN();

	return 0;
}
