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


#define MAXN 100002


int arr[MAXN],sqarr[MAXN];

int n,m,bsz,nb;
char c[11];

int upperboundd(int st,int en,int v)
{
    int midd;
    while(st<en)
    {
        midd=(st+en)>>1;
        if(sqarr[midd]<=v)
        {
            st=midd+1;
        }
        else
        {
            en=midd;
        }
    }

    return st;
}

int lowerboundd(int st,int en,int v)
{
    int midd;
    while(st<en)
    {
        midd=(st+en)>>1;
        if(sqarr[midd]<v)
        {
            st=midd+1;
        }
        else
        {
            en=midd;
        }
    }

    return st;
}


void insertt(int st,int en,int j,int v,int x)
{
    int i=j;
    sqarr[j]=arr[x]=v;

    for(i=j;i+1<en && sqarr[i]>sqarr[i+1];++i)
    {
        swap(sqarr[i],sqarr[i+1]);
    }

    for(i=j;i-1>=st && sqarr[i]<sqarr[i-1];--i)
    {
        swap(sqarr[i],sqarr[i-1]);
    }
}


int main()
{
    freopen("Text/RACETIME.txt","r",stdin);

    scanf("%d %d",&n,&m);
    bsz=sqrt(n);
    nb=bsz;
    int ans;
    int st,en;
    int x,y,z,leftt,rightt;
    int j;
    int k;

    if(bsz*bsz!=n)
    {
        ++nb;
    }

    for(int i=0;i<n;++i)
    {
        scanf("%d",arr+i);
        sqarr[i]=arr[i];
    }

    for(int i=0;i<n;++i)
    {
        sort(sqarr+i,sqarr+min(i+bsz,n));
        i+=bsz-1;
    }

    while(m--)
    {
        scanf("%s",c);

        if(c[0]=='C')
        {
            scanf("%d %d %d",&x,&y,&z);
            --x;
            --y;
            leftt=x/bsz;
            rightt=y/bsz;
            ans=0;

            if(leftt==rightt)
            {
                for(int i=x;i<=y;++i)
                {
                    if(arr[i]<=z)
                    {
                        ++ans;
                    }
                }

                printf("%d\n",ans);
            }
            else
            {
                en=min((leftt+1)*bsz,n);
                for(int i=x;i<en;++i)
                {
                    if(arr[i]<=z)
                    {
                        ++ans;
                    }
                }

                for(int i=rightt*bsz;i<=y;++i)
                {
                    if(arr[i]<=z)
                    {
                        ++ans;
                    }
                }

                for(int i=leftt+1;i<=rightt-1;++i)
                {
                    ans+=upperboundd(i*bsz,min((i+1)*bsz,n),z)-i*bsz;
                }

                printf("%d\n",ans);
            }
        }
        else
        {
            scanf("%d %d",&x,&y);
            --x;
            k=x/bsz;
            st=k*bsz;
            en=min((k+1)*bsz,n);
            j=lowerboundd(st,en,arr[x]);

            insertt(st,en,j,y,x);
        }
    }




    return 0;
}
