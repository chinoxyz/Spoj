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



#define MAXN 505

int arr[MAXN];
int rarr[MAXN];
int n,k;


int main()
{
    freopen("Text/XORROUND.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int ti;
    int i,j;
    int til,tir;

    while(cases--)
    {
        scanf("%d %d",&n,&k);

        for(i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        int poww=1;

        while(k)
        {
            if(k&1)
            {
                for(int i=0;i<n;++i)
                {
                    rarr[i]=arr[i]^arr[(i+poww)%n]^arr[(i+n-poww)%n];
                }

                memcpy(arr,rarr,sizeof(arr));
            }

            poww<<=1;
            poww%=n;

            k>>=1;
        }

        for(int i=0;i<n;++i)
        {
            printf("%d ",arr[i]);
        }

        printf("\n");
    }

    return 0;
}
