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

#define MAXN 101

char arr[MAXN][MAXN];
int widthh, heightt;

int dp[2*MAXN][MAXN][MAXN],fl[2*MAXN][MAXN][MAXN];
int tsteps,tcs;

int solve(int st,int w1,int w2)
{
    int h1=st-w1;
    int h2=st-w2;

    //printf("%d\t%d\t%d\t%d\t%d\n",h1,w1,h2,w2,ct);

    if(h1>=heightt || h2>=heightt
       || w1>=widthh || w2>=widthh || arr[h1][w1]=='#' || arr[h2][w2]=='#'
       )
    {
        return -1;
    }

    if(fl[st][w1][w2]==tcs)
    {
        return dp[st][w1][w2];
    }

    fl[st][w1][w2]=tcs;

    int ct=0;

    if(arr[h1][w1]=='*')
    {
            ++ct;
    }

    if(w1!=w2)
    {
        if(arr[h2][w2]=='*')
        {
            ++ct;
        }
    }

    int &ret=dp[st][w1][w2];
    ret=-1;

    if(st==tsteps)
    {
        if(h1==heightt-1 && h2==heightt-1 && w1==widthh-1 && w2==widthh-1)
        {
            return (ret=ct);
        }
        else
        {
            return -1;
        }
    }





    int ans=-1;

    ans=max(ans,solve(st+1,w1+1,w2+1));
    ans=max(ans,solve(st+1,w1+1,w2));
    ans=max(ans,solve(st+1,w1,w2+1));
    ans=max(ans,solve(st+1,w1,w2));

    if(ans==-1)
    {
        ret=-1;
    }
    else
    {
        ret=ct+ans;
    }

    return dp[st][w1][w2];

}



int main()
{
    freopen("Text/TOURIST.txt","r",stdin);

    int cases,n;
    scanf("%d",&cases);

    for(tcs=1;tcs<=cases;++tcs)
    {
        scanf("%d %d",&widthh,&heightt);

        for(int i=0;i<heightt;++i)
        {
            scanf("%s",&arr[i]);
        }
        tsteps=widthh+heightt-2;

        printf("%d\n",solve(0,0,0));

    }



    return 0;
}
