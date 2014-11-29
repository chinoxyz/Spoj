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

#define MAXN 33
int ncr[MAXN][MAXN];

void pree()
{
    ncr[0][0]=1;

    for(int i=1;i<MAXN;++i)
    {
        ncr[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
        }
    }
}

int calc(int numm,int k)
{
    int ret=0;
    int ct=0;

    for(int i=31;i;--i)
    {
        if(numm&(1<<i))
        {
            ++ct;
            if(ct>k)
            {
                break;
            }
            numm^=(1<<i);
        }

        if((1<<(i-1))<=numm)
        {
            ret+=ncr[i-1][k-ct];
        }
    }

    if(ct+numm==k)
    {
        ++ret;
    }

    return ret;
}

int solve(int l,int r,int k)
{
    int pos=1;
    int ct=0;

    for(int i=1;i<32;++i)
    {
        ct=calc(r,i)-calc(l-1,i);
        if(k<=ct)
        {
            pos=i;
            break;
        }
        k-=ct;
    }

    int midd,ll=l;

    int ti=calc(ll-1,pos);

    while(l<r)
    {
        midd=l+(r-l)/2;
        ct=calc(midd,pos)-ti;
        if(ct<k)
        {
            l=midd+1;
        }
        else
        {
            r=midd;
        }
    }

    return l;
}

int main()
{
    freopen("Text/SORTBIT.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    pree();

    int x,y,k;

    while(cases--)
    {
        scanf("%d %d %d",&x,&y,&k);

        if(x>=0)
        {
            if(x==0)
            {
                k-=1;
                ++x;
                if(k==0)
                {
                    printf("0\n");
                    continue;
                }
            }

            printf("%d\n",solve(x,y,k));
        }
        else
        {
            if(y==0)
            {
                k-=1;
                --y;
                if(k==0)
                {
                    printf("0\n");
                    continue;
                }
            }

            x&=~(1<<31);
            y&=~(1<<31);

            printf("%d\n",(1<<31)|solve(x,y,k));
        }
    }


    return 0;
}
