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

#define MAXQ 160000
#define MAXN 2007

int dp[2][MAXQ];
int a[MAXN],b[MAXN];
int q,m,k;
int ans;
int summ;


inline void solve()
{
    int i,j;
    ans=0;

    int l;
    int ti;
    if(q<=1)
    {
        return;
    }

    if(summ<q)
    {
        int diff=q-summ;

        sort(b,b+k);

        for(i=k-1;i>=0;--i)
        {
            diff-=b[i];
            if(diff<=0)
            {
                break;
            }
        }

        ans=q-k+i;
        return;
    }

    MSET(dp[0],0);
    int src,destt;
    src=0;
    destt=1;

    for(i=0;i<m;++i)
    {
        for(j=2;j<a[i];++j)
        {

            dp[destt][j]=dp[src][j];
            if(dp[destt][j]==j)
            {
                continue;
            }

            for(l=1;l<=j;++l)
            {
                dp[destt][j]=max(dp[destt][j],dp[src][j-l]+l-1);
            }
        }


        for(j=a[i];j<=q;++j)
        {

            dp[destt][j]=dp[src][j];
            if(dp[destt][j]==j)
            {
                continue;
            }

            for(l=1;l<a[i];++l)
            {
                dp[destt][j]=max(dp[destt][j],dp[src][j-l]+l-1);
            }

            dp[destt][j]=max(dp[destt][j],dp[src][j-a[i]]+a[i]);
        }


        swap(src,destt);

    }

    for(i=0;i<k;++i)
    {
        for(j=2;j<=b[i];++j)
        {
            dp[destt][j]=dp[src][j];
            if(dp[destt][j]==j)
            {
                continue;
            }

            for(l=1;l<=j;++l)
            {
                dp[destt][j]=max(dp[destt][j],dp[src][j-l]+l-1);
            }
        }

        for(j=b[i]+1;j<=q;++j)
        {
            dp[destt][j]=dp[src][j];
            if(dp[destt][j]==j)
            {
                continue;
            }

            for(l=1;l<=b[i];++l)
            {
                dp[destt][j]=max(dp[destt][j],dp[src][j-l]+l-1);
            }
        }


        swap(src,destt);
    }

    ans=dp[src][q];
}

int main()
{
    freopen("Text/FARMER.txt","r",stdin);

    int cases;
    //scanf("%d",&cases);
    cases=readPosInt();
    int i,j;

    while(cases--)
    {
        summ=0;
        //scanf("%d %d %d",&q,&m,&k);
        q=readPosInt();
        m=readPosInt();
        k=readPosInt();

        for(i=0;i<m;++i)
        {
            //scanf("%d",a+i);
            a[i]=readPosInt();
            summ+=a[i];
        }

        for(i=0;i<k;++i)
        {
            //scanf("%d",b+i);
            b[i]=readPosInt();
        }

        solve();
        printf("%d\n",ans);
    }


    return 0;
}
