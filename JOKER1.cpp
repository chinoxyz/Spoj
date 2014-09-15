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


const i64 MOD=1000000007;

int arr[70];


int main()
{
    freopen("Text/JOKER1.txt","r",stdin);
    int cases,i,n;

    i64 ret=1;

    scanf("%d",&cases);

    while(cases--)
    {
        ret=1;
        scanf("%d",&n);
        for(i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
        }

        sort(arr+1,arr+n+1);

        for(i=1;i<=n;++i)
        {
            if(arr[i]<i)
            {
                ret=0;
                break;
            }

            ret*=(arr[i]-i+1);
            ret%=MOD;
        }

        printf("%lld\n",ret);
    }

    printf("KILL BATMAN\n");


    return 0;
}


