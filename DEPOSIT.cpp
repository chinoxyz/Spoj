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


#define MAXN 22
int arr[MAXN][2],summ[MAXN][2];

void pree()
{
    arr[0][0]=arr[1][1]=summ[0][0]=1;

    for(int i=2;i<MAXN;++i)
    {
        arr[i][0]=arr[i-1][0]+arr[i-2][0];
        arr[i][1]=arr[i-1][1]+arr[i-2][1];
    }

    for(int i=1;i<MAXN;++i)
    {
        summ[i][0]=summ[i-1][0]+arr[i][0];
        summ[i][1]=summ[i-1][1]+arr[i][1];
    }
}

void MAIN()
{
    pree();
    int f,s;
    int r,k,t;
    int x,y;
    int ans;

    while(true)
    {
        scanf("%d",&r);
        if(!r)
        {
            break;
        }

        scanf("%d %d",&k,&t);
        f=summ[r-1][0];
        s=summ[r-1][1];

        x=0;

        while(true)
        {
            ++x;
            if(!((t-f*x)%s))
            {
                y=(t-f*x)/s;
                break;
            }
        }

        ans=k*(x*arr[r-1][0] + y*arr[r-1][1]);
        printf("%d %d %d\n",x,y,ans);
    }

}

int main()
{
	freopen("Text/DEPOSIT.txt","r",stdin);

    MAIN();

	return 0;
}

