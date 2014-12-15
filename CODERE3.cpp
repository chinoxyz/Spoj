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


#define MAXN 1005

int arr[MAXN];
int n;
int a[2][MAXN];
VI::iterator it;

void solve(int pos)
{
    VI v;

    v.PB(arr[0]);
    a[pos][0]=1;

    for(int i=1;i<n;++i)
    {
        it=lower_bound(v.begin(),v.end(),arr[i]);
        if(it==v.end())
        {
            v.PB(arr[i]);
            a[pos][i]=v.size();
        }
        else
        {
            *it=arr[i];
            a[pos][i]=it-v.begin()+1;
        }
    }
}

int main()
{
    freopen("Text/CODERE3.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int ans;

    while(cases--)
    {
        ans=0;
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        solve(0);
        reverse(arr,arr+n);
        solve(1);

        for(int i=0;i<n;++i)
        {
            //if(a[0][i]>1 && a[1][n-i-1]>1)
            {
                ans=max(ans,a[0][i]+a[1][n-i-1]-1);
            }
        }

        printf("%d\n",ans);
    }


    return 0;
}
