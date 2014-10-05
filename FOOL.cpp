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

/*
    Chomsky Normal Form

    1.  Start rule
        S -> OB

        Empty set rule
        S -> OP

    2.  Opening bracket of set
        O -> {

    3.  Closing bracket of set
        P -> }

    4.  Separator of elements
        K -> ,

    5.  Closes a set
        B -> CP

        Rule for only one element in list
        B -> DP

    6.  Rules for list
        C -> DE

    7.  Continue list
        E -> KC

        End of list
        E -> KD

    8.  Rules for element

        Open new set
        D -> OB

        Empty set rule
        D -> OP

        Atom
        D -> {
        D -> }
        D -> ,

*/

#define MAXL 256
#define NRULES 9

int dp[MAXL][MAXL];


int producedBy(int from, int to, char *s, int rules[NRULES][3])
{
    if(dp[from][to]>=0)
    {
        return dp[from][to];
    }

    if(from==to)
    {
        if(s[from]=='{')
        {
            return dp[from][to]=(1<<1) | (1<<7);
        }

        if(s[from]=='}')
        {
            return dp[from][to]=(1<<2) | (1<<7);
        }

        if(s[from]==',')
        {
            return dp[from][to]=(1<<3) | (1<<7);
        }
    }

    int maskk=0;

    for(int midd=from;midd<to;++midd)
    {
        int leftt=producedBy(from,midd,s,rules);
        int rightt=producedBy(midd+1,to,s,rules);


        for(int i=0;i<NRULES;++i)
        {
            if((rules[i][1]&leftt)!=0  && (rules[i][2]&rightt)!=0)
            {
                maskk|=rules[i][0];
            }
        }
    }

    return dp[from][to]=maskk;
}

void initRules(int rules[9][3])
{
    rules[0][0]=1<<0;
    rules[0][1]=1<<1;
    rules[0][2]=1<<4;

    rules[1][0]=1<<0;
    rules[1][1]=1<<1;
    rules[1][2]=1<<2;

    rules[2][0]=1<<4;
    rules[2][1]=1<<5;
    rules[2][2]=1<<2;

    rules[3][0]=1<<4;
    rules[3][1]=1<<7;
    rules[3][2]=1<<2;

    rules[4][0]=(1<<5);
    rules[4][1]=1<<7;
    rules[4][2]=1<<6;

    rules[5][0]=1<<6;
    rules[5][1]=1<<3;
    rules[5][2]=1<<5;

    rules[6][0]=1<<6;
    rules[6][1]=1<<3;
    rules[6][2]=1<<7;

    rules[7][0]=1<<7;
    rules[7][1]=1<<1;
    rules[7][2]=1<<4;

    rules[8][0]=1<<7;
    rules[8][1]=1<<1;
    rules[8][2]=1<<2;
}



int main()
{
    freopen("Text/FOOL.txt","r",stdin);

    int rules[NRULES][3];
    initRules(rules);

    char s[MAXL+1];
    int cases;
    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        scanf("%s",&s);
        int len=strlen(s);

        MSET(dp,-1);

        int ans=producedBy(0,len-1,s,rules);

        if(ans&1)
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
