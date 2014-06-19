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

#define MAXN 1000000

i64 etf[MAXN+1];
i64 ans[MAXN+1];


void pre()
{
    int i,j;
    for(i = 1 ;i <= MAXN ; ++i )
    {
        etf[i]=i;
    }

    for(i=2 ; i<= MAXN ; ++i )
    {
        if ( etf[i] == i)
        {
            for(int j = 2*i ; j <= MAXN ; j += i)
            {
                etf[j] -=  etf[j]/ i ;
            }
        }

    }


    for(i=2 ; i<= MAXN ; ++i)
    {
        if ( etf[i]==i)
        {
            etf[i] = i-1;
        }
    }


    for(i=1;i <= MAXN ; ++i)
    {
        for (j = i ; j <= MAXN ; j += i  )
        {
            ans[j]+= i*etf[i];
        }
    }
}

int main()
{
    freopen("text/LCMSUM.txt","r",stdin);
    int cases,n;

    i64 sum;

    pre();

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        //printf("%d\n",n);
        sum=((1+ans[n])*n)/2;
        printf("%lld\n",sum);
    }

    return 0;
}

