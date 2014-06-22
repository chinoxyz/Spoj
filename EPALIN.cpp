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



#define MAXN 100002
char str[MAXN];
int dp[MAXN];
int mx=0,n;

void solve()
{
    //MSET(dp,-1);
    fill(dp,dp+MAXN,-2);
    n=strlen(str);
    mx=0;

    int i,j,k;
    bool mt;

    i=0;
    j=0;
    dp[0]=-1;

    while(i<n-1-j)
    {

        mt=true;
        while(j>=0 && str[i]!=str[n-1-j])
        {
            mt=false;
            //j=dp[j];


            if(dp[j]!=-2)
            {
                j=dp[j];
            }
            else
            {
                k=dp[j-1];

                while(k>=0 && str[n-1-j]!=str[n-1-k])
                {
                    k=dp[k];
                }
                ++k;
                dp[j]=k;
                j=dp[j];
            }

            //printf("DD\n");
        }

        //if(mt)
        {
            ++i;
            ++j;
        }
        //++j;



        if(mt && dp[j]==-2)
        {
                k=dp[j-1];

                while(k>=0 && str[n-1-j+1]!=str[n-1-k])
                {
                    k=dp[k];
                }
                ++k;
                dp[j]=k;
        }

    }

    if(i==n-1-j)
    {
        mx=1+2*(j);
    }
    else
    {
        mx=2*(j);
    }

    if(mx<=0)
    {
        mx=1;
    }


    //printf("%s",str);
    for(i=0;i<n;++i)
    {
        printf("%c",str[i]);
    }
    //printf("|");
    mx=n-mx;
    if(mx>0)
    {
        for(i=mx-1;i>=0;--i)
        {
            printf("%c",str[i]);
        }
    }
    printf("\0");
    printf("\n");
    //printf("%d\n",mx);
/*
    for(i=0;i<=n;++i)
    {
        printf("%d\t",dp[i]);
    }
    printf("\n");
*/
}


int main()
{

    freopen("Text/EPALIN.txt","r",stdin);

    //while(scanf("%s",str)!=EOF)
    while(gets(str))
    {
        //printf("%s",str);
        solve();
    }

    return 0;
}

