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

#define MAXL 1001
#define MAXV 5001
#define INF 99999999

int dp[MAXL][MAXV];
int buff[MAXL+10];
char buff2[MAXL+10];
bool vis[MAXL][MAXV];

int lenn;


inline int solve(int pos,int numm)
{
    if(vis[pos][numm])
    {
        return dp[pos][numm];
    }

    int &ret=dp[pos][numm];
    vis[pos][numm]=1;
    ret=INF;

    int i=pos;

    while(i<lenn && buff[i]==0)
    {
        ++i;
    }



    int u=0;

    if(i<lenn)
    {
        u=buff[i];

        for(i=i+1;i<lenn && u<=numm;++i)
        {
            ret=min(ret,1+solve(i,numm-u));
            u=u*10+buff[i];
        }
    }

    if(i==lenn && u==numm)
    {
        ret=0;
    }

    return ret;
}


int main()
{
    freopen("Text/JEDNAKOS.txt","r",stdin);

    scanf("%s",buff2);
    int num;

    int i=0;

    while(buff2[i]!='=')
    {
        buff[i]=buff2[i]-'0';
        ++i;
    }

    sscanf(buff2+i+1,"%d",&num);

    lenn=i;

    int ans=solve(0,num);

    printf("%d\n",ans);



    return 0;
}

