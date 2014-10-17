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

#define MAXN 100004

i64 arr[MAXN];
i64 ans[MAXN];


int main()
{
    freopen("Text/RLCIPHER.txt","r",stdin);

    int cases,n;

    scanf("%d",&cases);
    int result[7]={-4,-3,-2,-4,-4,-3,-4};

    while(cases--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%lld",arr+i);
            ans[i]=0;
            if(arr[i]<0)
            {
                ans[i]=arr[i];
            }
            else if(arr[i]>6LL)
            {
                ans[i]=-4;
            }
            else
            {
                ans[i]=result[arr[i]];
            }
        }

        for(int i=0;i<n;++i)
        {
            printf("%d ",ans[i]);
        }

        printf("\n");

        //printf("%d\n",ans[n-1]);
    }






    return 0;
}
