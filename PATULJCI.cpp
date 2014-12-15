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

#define MAXN 300001
#define MAXC 100000
#define MAXB 22

int n,c;
int arr[MAXN];
int l[MAXC],r[MAXC];
int m;
int dp[MAXB][MAXN],*summ[MAXB];

PII barr[MAXN];

int main()
{
    freopen("Text/PATULJCI.txt","r",stdin);

    scanf("%d %d",&n,&c);
    int midd;
    int i,j;
    int x,y;
    MSET(l,-1);
    MSET(r,-1);
    int ti,ans,st,en;

    for(i=0;i<n;++i)
    {
        scanf("%d",arr+i);
        --arr[i];
        barr[i].first=arr[i];
        barr[i].second=i;
    }

    sort(barr,barr+n);

    for(i=0;i<n;++i)
    {
        if(l[barr[i].first]==-1)
        {
            l[barr[i].first]=i;
        }
        r[barr[i].first]=i;
    }

    scanf("%d",&m);

    for(i=0;i<MAXB;++i)
    {
        summ[i]=dp[i]+1;
    }

    for(j=0;j<MAXB;++j)
    {
        for(i=0;i<n;++i)
        {
            summ[j][i]=summ[j][i-1];
            if(arr[i]&(1<<j))
            {
                ++summ[j][i];
            }
        }
    }

    while(m--)
    {
        scanf("%d %d",&x,&y);
        --x;
        --y;

        ti=(y-x+1)>>1;
        ans=0;

        for(j=0;j<17;++j)
        {
            if(summ[j][y]-summ[j][x-1]>ti)
            {
                ans|=(1<<j);
            }
        }

        if(ans>=c || l[ans]==-1)
        {
            ans=-1;
        }
        else
        {
            st=l[ans]-1;
            en=r[ans];

            while(st+1<en)
            {
                midd=(st+en)>>1;
                if(barr[midd].second<x)
                {
                    st=midd;
                }
                else
                {
                    en=midd;
                }
            }

            x=en;

            st=l[ans];
            en=r[ans]+1;

            while(st+1<en)
            {
                midd=(st+en)>>1;
                if(barr[midd].second>y)
                {
                    en=midd;
                }
                else
                {
                    st=midd;
                }
            }
            y=st;

            if(y-x+1<=ti)
            {
                ans=-1;
            }
        }

        if(ans==-1)
        {
            printf("no\n");
        }
        else
        {
            printf("yes %d\n",ans+1);
        }
    }



    return 0;
}




