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

#define MAXN 100001

int arr[MAXN];
int ans,cases,n;

void solve()
{
    int j;
    ans=0;

    for(int i=0;i<n;++i)
    {
        if(arr[i]==0)
        {
            continue;
        }

        ++ans;

        j=i+1;

        while(j<n && arr[j]>=arr[i])
        {
            if(arr[j]==arr[i])
            {
                arr[j]=0;
            }
            ++j;
        }


        arr[i]=0;
    }


    printf("Case %d: %d\n",cases,ans);
}

int main()
{
    freopen("Text/CITY2.txt","r",stdin);

    cases=0;

    while(scanf("%d",&n)!=EOF)
    {
        ++cases;

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        solve();
    }




    return 0;
}
