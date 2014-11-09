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

#define MAXN 51
#define INF 999999999999999999LL
int n,tot;

struct matrixx
{
    i64 arr[MAXN][MAXN];
};

matrixx *am;


matrixx *solve(matrixx *a,matrixx *b)
{
    matrixx *ret=new matrixx();
    int i,j,k;


    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            ret->arr[i][j]=INF;
            for(k=0;k<n;++k)
            {
                ret->arr[i][j]=min(ret->arr[i][j],a->arr[i][k]+b->arr[k][j]);
            }
        }
    }



    return ret;
}


matrixx *poww(matrixx *a,int p)
{
    if(p==0)
    {
        return new matrixx();
    }

    if(p==1)
    {
        return a;
    }

    matrixx *ti=poww(a,p/2);
    ti=solve(ti,ti);

    if(p&1)
    {
        ti=solve(ti,a);
    }

    return ti;
}


int main()
{
    freopen("Text/PLHOP.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    am=new matrixx();
    matrixx *tam;
    int i,j,k;

    for(int t=1;t<=cases;++t)
    {

        scanf("%d %d",&tot,&n);

        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
            {

                scanf("%lld",&(am->arr[i][j]));
                //printf("%lld\n",am->arr[i][j]);
            }
        }


        for(k=0;k<n;++k)
        {
            for(i=0;i<n;++i)
            {
                for(j=0;j<n;++j)
                {
                    am->arr[i][j]=min(am->arr[i][j],am->arr[i][k]+am->arr[k][j]);
                }
            }
        }

        tam=poww(am,tot);
        printf("Region #%d:\n",t);

        for(i=0;i<n;++i)
        {
            for(j=0;j<n-1;++j)
            {
                printf("%lld ",tam->arr[i][j]);
            }
            printf("%lld\n",tam->arr[i][j]);
        }
        printf("\n");
    }



    return 0;
}
