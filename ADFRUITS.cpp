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

#define MAXN 105

int prex[MAXN][MAXN];
int prey[MAXN][MAXN];
int dp[MAXN][MAXN];
//bool included[MAXN][MAXN];
char as[MAXN];
char bs[MAXN];
int la,lb;
VI xs,ys;
int x,y,tx,ty,len,stx,sty;

void lcs()
{
    xs.clear();
    ys.clear();
    MSET(prex,0);
    MSET(prey,0);
    MSET(dp,0);
    //MSET(included,0);
    la=strlen(as);
    lb=strlen(bs);


    for(int i=1;i<=la;++i)
    {
        for(int j=1;j<=lb;++j)
        {
            if(as[i-1]==bs[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                prex[i][j]=i-1;
                prey[i][j]=j-1;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    prex[i][j]=i-1;
                    prey[i][j]=j;
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    prex[i][j]=i;
                    prey[i][j]=j-1;
                }
            }
        }
    }

    x=la;
    y=lb;

    while(x && y)
    {
        if(as[x-1]==bs[y-1])
        {
            xs.PB(x-1);
            ys.PB(y-1);
        }

        tx=prex[x][y];
        ty=prey[x][y];
        x=tx;
        y=ty;
    }

    len=xs.size();

    stx=-1;
    sty=-1;
    //printf("%d\n",len);


    for(int i=len-1;i>=0;--i)
    {
        ++stx;
        while(stx!=xs[i])
        {
            printf("%c",as[stx]);
            ++stx;
        }

        ++sty;
        while(sty!=ys[i])
        {
            printf("%c",bs[sty]);
            ++sty;
        }


        printf("%c",as[stx]);
    }

        ++stx;
        while(stx!=la)
        {
            printf("%c",as[stx]);
            ++stx;
        }

        ++sty;
        while(sty!=lb)
        {
            printf("%c",bs[sty]);
            ++sty;
        }
        printf("\n");

}


int main()
{
    freopen("Text/ADFRUITS.txt","r",stdin);

    while(scanf("%s",as)!=EOF)
    {
        scanf("%s",bs);
        //printf("%s\t%s\n",as,bs);
        lcs();
    }



    return 0;
}
