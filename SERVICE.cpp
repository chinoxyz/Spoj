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


//#define gc getchar_unlocked
#define gc getchar

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}



#define MAXL 202
#define MAXN 1002
#define INF 0x7f7f7f7f

int distt[MAXL][MAXL];
int arr[MAXN];

int dp[2][MAXL][MAXL];
int l,n;

int ans;
int tarr[3];
int barr[3];
int mn,mx;
int ti;

inline void solve()
{
    int i,j,k;

    for(i=0;i<n;++i)
    {
        for(j=1;j<=l;++j)
        {
            for(k=j+1;k<=l;++k)
            {
                dp[(i+1)&1][j][k]=INF;
            }
        }
        for(j=1;j<=l;++j)
        {
            if(j==arr[i])
            {
                continue;
            }
            for(k=j+1;k<=l;++k)
            {
                if(k==arr[i])
                {
                    continue;
                }

               if(dp[i&1][j][k]<INF)
               {
                   if(arr[i+1]==arr[i])
                   {
                       dp[(i+1)&1][j][k]=min(dp[(i+1)&1][j][k],dp[i&1][j][k]);
                   }
                   else if(arr[i+1]==j)
                   {
                       mn=min(arr[i],k);
                       mx=max(arr[i],k);

                       dp[(i+1)&1][mn][mx]=min(dp[(i+1)&1][mn][mx],dp[i&1][j][k]);

                   }
                   else if(arr[i+1]==k)
                   {
                       mn=min(arr[i],j);
                       mx=max(arr[i],j);

                       dp[(i+1)&1][mn][mx]=min(dp[(i+1)&1][mn][mx],dp[i&1][j][k]);

                   }
                   else
                   {
                       ti=distt[arr[i]][arr[i+1]];
                       dp[(i+1)&1][j][k]=min(dp[(i+1)&1][j][k],ti+dp[i&1][j][k]);


                       ti=distt[j][arr[i+1]];
                       mn=min(arr[i],k);
                       mx=max(arr[i],k);
                       dp[(i+1)&1][mn][mx]=min(dp[(i+1)&1][mn][mx],ti+dp[i&1][j][k]);



                       ti=distt[k][arr[i+1]];
                       mn=min(arr[i],j);
                       mx=max(arr[i],j);
                       dp[(i+1)&1][mn][mx]=min(dp[(i+1)&1][mn][mx],ti+dp[i&1][j][k]);

                   }
               }
            }
        }
    }

    ans=INF;

    for(i=1;i<=l;++i)
    {
        if(i==arr[n])
        {
            continue;
        }
        for(j=i+1;j<=l;++j)
        {
            ans=min(ans,dp[n&1][i][j]);
        }
    }
}




int main()
{
    freopen("Text/SERVICE.txt","r",stdin);

    int cases;

    int ti;

    //scanf("%d",&cases);
    cases=readPosInt();
    int i,j;

    while(cases--)
    {
        //scanf("%d %d",&l,&n);
        l=readPosInt();
        n=readPosInt();

        for(i=1;i<=l;++i)
        {
            for(j=1;j<=l;++j)
            {
                //scanf("%d",&distt[i][j]);
                distt[i][j]=readPosInt();
            }
        }
        arr[0]=1;
        for(i=1;i<=n;++i)
        {
            //scanf("%d",arr+i);
            arr[i]=readPosInt();
        }

        MSET(dp,0x7f);

        dp[0][2][3]=0;

        solve();

        printf("%d\n",ans);
    }


    return 0;
}

