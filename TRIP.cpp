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


#define MAXL 83

int dp[MAXL][MAXL];
int len1,len2;
set<string> resultt;


char str1[MAXL];
char str2[MAXL];

map<string,bool> processed[81][81];

inline void longest_common_subsequence()
{
    int i,j,mx,temp_int;

    for(i=0;i<=len1;++i)
    {
        dp[i][0]=0;
    }

    for(i=0;i<=len2;++i)
    {
        dp[0][i]=0;
    }


    for(i=1;i<=len1;++i)
    {
        for(j=1;j<=len2;++j)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];

            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}



inline void generate_n_store_subsequences(int x,int y,string s)
{
    if(processed[x][y].find(s)!=processed[x][y].end())
    return;

    if(x<=0 || y<=0)
    {
        resultt.insert(s);
        //return;
    }
    else if(str1[x-1]==str2[y-1])
    {
        s=str1[x-1]+s;
        generate_n_store_subsequences(x-1,y-1,s);
    }
    else if(dp[x-1][y]==dp[x][y-1])
    {
        generate_n_store_subsequences(x-1,y,s);
        generate_n_store_subsequences(x,y-1,s);
    }
    else if(dp[x-1][y]>dp[x][y-1])
    {
        generate_n_store_subsequences(x-1,y,s);
    }
    else
    {
        generate_n_store_subsequences(x,y-1,s);
    }

    processed[x][y][s] = true;

}


int main()
{
    freopen("Text/TRIP.txt","r",stdin);

    int cases,i,j;
    set<string>::iterator it;

    scanf("%d",&cases);

    while(cases--)
    {
        resultt.clear();

        scanf("%s\n%s",str1,str2);

        len1=strlen(str1);
        len2=strlen(str2);

        longest_common_subsequence();

        generate_n_store_subsequences(len1,len2,"");


        for(it=resultt.begin();it!=resultt.end();++it)
        {
            printf("%s\n",(*it).c_str());
        }

        printf("\n");

    }

    return 0;
}


