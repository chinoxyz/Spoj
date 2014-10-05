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


#define MAXL 256

char dp[MAXL][MAXL];
char dp2[MAXL][MAXL];


bool isList(int, int, char*);


bool isSet(int from,int to,char *s)
{
    if(dp[from][to]>=0)
    {
        return dp[from][to];
    }

    if(from>=to)
    {
        return dp[from][to]=0;
    }

    if(s[from]!='{' || s[to]!='}')
    {
        return dp[from][to]=0;
    }

    if(from+1==to)
    {
        return dp[from][to]=1;
    }

    return dp[from][to]=isList(from+1,to-1,s);
}


bool isElement(int from,int to, char *s)
{
    if(from==to)
    {
        //assert(s[from] == '{' || s[from] == '}' || s[from] == ',');
        return 1;
    }

    return isSet(from,to,s);
}

bool isList(int from, int to, char *s)
{
    if(dp2[from][to]>=0)
    {
        return dp2[from][to];
    }

    if(isElement(from,to,s))
    {
        return dp2[from][to]=1;
    }

    for(int k=from+1;k<to;++k)
    {
        if(s[k]==',')
        {
            if(isElement(from,k-1,s) && isList(k+1,to,s))
            {
                return dp2[from][to]=1;
            }
        }
    }

    return dp2[from][to]=0;
}


int main()
{
    freopen("Text/FOOL.txt","r",stdin);


    char s[MAXL+1];
    int cases;
    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        scanf("%s",&s);
        int len=strlen(s);

        MSET(dp,-1);
        MSET(dp2,-1);

        bool ans=isSet(0,len-1,s);

        if(ans)
        {
            printf("Word #%d: Set\n",t);
        }
        else
        {
            printf("Word #%d: No Set\n",t);
        }
    }


    return 0;
}
