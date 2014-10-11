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

#define MAXN 22

int arr1[MAXN],arr2[MAXN];
int w,d;


int main()
{
    freopen("Text/CUBARTWK.txt","r",stdin);
    int ans,ti;

    while(true)
    {
        ans=0;
        scanf("%d %d",&w,&d);
        if(w==0 && d==0)
        {
            break;
        }

        MSET(arr1,0);
        MSET(arr2,0);

        for(int i=0;i<w;++i)
        {
            scanf("%d",&ti);
            ++arr1[ti];
        }

        for(int i=0;i<d;++i)
        {
            scanf("%d",&ti);
            ++arr2[ti];
        }

        for(int i=1;i<MAXN;++i)
        {
            ans+=max(arr1[i],arr2[i])*i;
        }

        printf("%d\n",ans);
    }


    return 0;
}
