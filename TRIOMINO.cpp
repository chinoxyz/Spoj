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

#define MAXN 801

int ans[MAXN][4];
int mex[MAXN][4];

void pree()
{
    //  Flat
    //  1
    //  2 Same
    //  2 Opp

    ans[0][0]=ans[0][1]=ans[1][0]=ans[1][1]=0;
    ans[0][2]=ans[0][3]=ans[1][2]=ans[1][3]=0;
    ans[2][0]=ans[2][1]=1;
    ans[2][2]=ans[2][3]=0;

    int i,j;
    int x,y;

    for(i=3;i<MAXN;++i)
    {
        for(j=1;j<=i;++j)
        {
            if(j<i)
            {
                x=ans[j-1][0];
                y=ans[i-j][1];
                mex[x^y][0]=i;

                x=ans[j-1][0];
                y=ans[i-j][1];
                mex[x^y][0]=i;
            }

            if(j>1)
            {
                x=ans[j-1][1];
                y=ans[i-j][0];
                mex[x^y][0]=i;

                x=ans[j-1][1];
                y=ans[i-j][0];
                mex[x^y][0]=i;
            }










            if(j<i)
            {
                x=ans[j-1][0];
                y=ans[i-j][2];
                mex[x^y][1]=i;
            }

            if(j<i-1)
            {
                x=ans[j-1][0];
                y=ans[i-j][2];
                mex[x^y][1]=i;
            }



            if(j>1 && j<i)
            {
                x=ans[j-1][1];
                y=ans[i-j][1];
                mex[x^y][1]=i;

                x=ans[j-1][1];
                y=ans[i-j][1];
                mex[x^y][1]=i;
            }










            if(j>1 && j<i)
            {
                x=ans[j-1][1];
                y=ans[i-j][3];
                mex[x^y][2]=i;
            }

            if(j>1 && j<i-1)
            {
                x=ans[j-1][1];
                y=ans[i-j][2];
                mex[x^y][2]=i;
            }

            if(j>1 && j<i)
            {
                x=ans[j-1][3];
                y=ans[i-j][1];
                mex[x^y][2]=i;
            }

            if(j>2 && j<i)
            {
                x=ans[j-1][2];
                y=ans[i-j][1];
                mex[x^y][2]=i;
            }









            if(j>1 && j<i)
            {
                x=ans[j-1][1];
                y=ans[i-j][3];
                mex[x^y][3]=i;
            }

            if(j>1 && j<i-1)
            {
                x=ans[j-1][1];
                y=ans[i-j][2];
                mex[x^y][3]=i;
            }

            if(j>2 && j<i)
            {
                x=ans[j-1][2];
                y=ans[i-j][1];
                mex[x^y][3]=i;
            }

            if(j>1 && j<i)
            {
                x=ans[j-1][3];
                y=ans[i-j][1];
                mex[x^y][3]=i;
            }
        }

        for(j=0;j<MAXN;++j)
        {
            if(mex[j][0]!=i)
            {
                ans[i][0]=j;
                break;
            }
        }

        for(j=0;j<MAXN;++j)
        {
            if(mex[j][1]!=i)
            {
                ans[i][1]=j;
                break;
            }
        }

        for(j=0;j<MAXN;++j)
        {
            if(mex[j][2]!=i)
            {
                ans[i][2]=j;
                break;
            }
        }

        for(j=0;j<MAXN;++j)
        {
            if(mex[j][3]!=i)
            {
                ans[i][3]=j;
                break;
            }
        }
    }
}


void MAIN()
{
    pree();
    int cases;

    scanf("%d",&cases);
    int n;

    while(cases--)
    {
        scanf("%d",&n);
        if(ans[n][0]==0)
        {
            printf("Y\n");
        }
        else
        {
            printf("X\n");
        }
    }
}

int main()
{

	freopen("Text/TRIOMINO.txt","r",stdin);

    MAIN();

	return 0;
}
