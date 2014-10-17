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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64


#define MAXN 1001
char arr[MAXN][MAXN];
u64 numm[MAXN];

int n,m;
u64 up,downn;

u64 gcdd(u64 a,u64 b)
{
    if(a<b)
    {
        return gcdd(b,a);
    }

    u64 ti;

    while(b)
    {
        ti=a%b;
        a=b;
        b=ti;
    }

    return a;
}

int main()
{
    freopen("Text/CFRAC2.txt","r",stdin);
    u64 ti;
    int j,i;

    while(true)
    {
        scanf("%d %d",&n,&m);
        if(n+m==0)
        {
            break;
        }
        up=downn=1;

        for(i=0;i<n;++i)
        {
            scanf("%s",&arr[i]);
            ti=0;

            j=0;

            while(arr[i][j]<'0' || arr[i][j]>'9')
            {
                ++j;
            }

            while(j<m && arr[i][j]>='0' && arr[i][j]<='9')
            {
                ti=ti*10LL+arr[i][j]-'0';
                ++j;
            }

            numm[i]=ti;
            //printf("%llu\n",numm[i]);
        }

        up=numm[n-1];

        i=n-2;

        while(i>=0)
        {
            ti=up;
            up=numm[i-1]*downn;
            downn=ti;

            up=downn*numm[i]+up;

            ti=gcdd(up,downn);
            up/=ti;
            downn/=ti;
            i-=2;
            //printf("%llu %llu\n",up,downn);
        }

        printf("%llu %llu\n",up,downn);
    }


    return 0;
}
