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

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}





int s_bitcount(unsigned int set1)
{
    int ret=0;

    ret=(set1&0x55555555) + ((set1>>1) & 0x55555555);
    ret=(ret&0x33333333) + ((ret>>2) & 0x33333333);
    ret=(ret&0x0F0F0F0F) + ((ret>>4) & 0x0F0F0F0F);
    ret=(ret&0x00FF00FF) + ((ret>>8) & 0x00FF00FF);
    ret=(ret&0x0000FFFF) + ((ret>>16));

    return ret;
}



#define MAXN 200008
char str[MAXN];
int dp[MAXN];


string preProcess(string s)
{
    int n=s.length();

    if(n==0)
    {
        return "^$";
    }

    string ret="^";

    for(int i=0;i<n;++i)
    {
        ret+="#";
        ret+=s.substr(i,1);
    }

    ret+="#$";

    return ret;

}

void solve(string s)
{
    //printf("%s\n",s.c_str());
    string t=preProcess(s);
    //printf("%s\n",t.c_str());
    MSET(dp,0);
    int n=t.length();
    int c=0,r=0;

    for(int i=1;i<n-1;++i)
    {
        int i_mirror=2*c-i;

        dp[i] = (r>i)?min(dp[i_mirror],r-i):0;

        while(t[i+1+dp[i]]==t[i-1-dp[i]])
        {
            ++dp[i];
        }

        if(i+dp[i]>r)
        {
            c=i;
            r=i+dp[i];
        }
    }
/*
    for(int i=0;i<n;++i)
    {
        printf("%d\t",dp[i]);
    }
    printf("\n");
*/

    int mc=0,ml=0;

    for(int i=1;i<n-1;++i)
    {
        if((i+dp[i])==(n-1) || (i+dp[i])==(n-2))
        {
            if(dp[i]>ml)
            {
                //printf("____________________________\n");
                ml=dp[i];
                mc=i;
            }
        }
    }



    int tc=(mc-1-ml)/2;
    //printf("%d\n",tc);
    printf("%s",s.c_str());

    for(int i=tc-1;i>=0;--i)
    {
        printf("%c",s[i]);
    }
    printf("\n");

}


int main()
{

    freopen("Text/EPALIN.txt","r",stdin);

    //while(scanf("%s",str)!=EOF)
    while(gets(str))
    {
        string s(str);
        solve(s);
    }

    return 0;
}

