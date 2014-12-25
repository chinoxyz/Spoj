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

#define INF 9999999
#define MAXN 1111
#define MAXM 26

char a[MAXN],b[MAXN];
int alenn,blenn;
int dp[MAXN][MAXN];
int arr1[MAXN][MAXM],arr2[MAXN][MAXM];

int solve(int x,int y)
{
    if(x<0 || y<0)
    {
        return x+y+2;
    }

    int &ret=dp[x][y];
    if(ret!=-1)
    {
        return ret;
    }
    int cost=(a[x]==b[y])?0:1;

    ret=min(1+min(solve(x,y-1),solve(x-1,y)),cost+solve(x-1,y-1));

    int ti1=arr1[x][b[y]-'a'];
    int ti2=arr2[y][a[x]-'a'];

    if(ti1!=-1 && ti2!=-1 && (x==ti1+1 || y==ti2+1))
    {
        ret=min(ret,solve(ti1-1,ti2-1)+x-ti1-1+y-ti2-1 +1);
    }



    return ret;
}

void MAIN()
{
    while(true)
    {
        scanf("%s %s",a,b);
        if(strcmp(a,"*")==0)
        {
            break;
        }

        alenn=strlen(a);
        blenn=strlen(b);

        for(int i=0;i<MAXM;++i)
        {
            arr1[0][i]=arr2[0][i]=-1;
        }

        for(int i=1;i<alenn;++i)
        {
            for(int j=0;j<MAXM;++j)
            {
                arr1[i][j]=arr1[i-1][j];
            }

            arr1[i][a[i-1]-'a']=i-1;
        }

        for(int i=1;i<blenn;++i)
        {
            for(int j=0;j<MAXM;++j)
            {
                arr2[i][j]=arr1[i-1][j];
            }

            arr2[i][b[i-1]-'a']=i-1;
        }



        MSET(dp,-1);

        printf("%d\n",solve(alenn-1,blenn-1));
    }
}

int main()
{
	freopen("Text/ADVEDIST.txt","r",stdin);

    MAIN();

	return 0;
}

