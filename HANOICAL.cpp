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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MAXN 44
int arr[2][MAXN];
int n;

int solve(int arr[],int n,int en)
{
    int ret=0;

    for(;n;--n)
    {
        if(arr[n]!=en)
        {
            ret+=1<<(n-1);
            en=3-arr[n]-en;
        }
    }

    return ret;
}

void MAIN()
{
    int en,ans,i,j;

    while(true)
    {
        ans=0;
        scanf("%d",&n);
        if(!n)
        {
            break;
        }

        for(i=0;i<2;++i)
        {
            for(j=1;j<=n;++j)
            {
                scanf("%d",&arr[i][j]);
                --arr[i][j];
            }
        }

        while(arr[0][n]==arr[1][n] && n)
        {
            --n;
        }

        if(n)
        {
            en=3-arr[0][n]-arr[1][n];

            ans=1+solve(arr[0],n-1,en)+solve(arr[1],n-1,en);
        }



        printf("%d\n",ans);
    }

}

int main()
{
	freopen("Text/HANOICAL.txt","r",stdin);

    MAIN();

	return 0;
}

