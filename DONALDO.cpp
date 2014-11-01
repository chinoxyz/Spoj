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

#define MAXN 200005
int arr[MAXN];
char buff[55];
int ans;
int timee;
int n;

inline void solve()
{
    ans=0;

    if(n==0)
    {
        return;
    }

    sort(arr,arr+n);

    ans=1;
    int pos,ti;
    int leftt=0;

    for(int i=1;i<n;++i)
    {
        if(arr[i]-arr[leftt]<timee)
        {
            ++ans;
        }
        else
        {
            ++leftt;
        }
    }
}


int main()
{
    freopen("Text/DONALDO.txt","r",stdin);

    int cases;
    int x,y,z;

    scanf("%d",&cases);
    int i;
    const int m1=60*60;

    for(int t=1;t<=cases;++t)
    {
        scanf("%d",&n);

        for(i=0;i<n;++i)
        {
            scanf("%s",buff);
            sscanf(buff,"%d:%d:%d",&x,&y,&z);
            arr[i]=x*m1+y*60+z;
        }

        scanf("%d",&timee);
        solve();

        printf("Case %d: %d\n",t,ans);
    }




    return 0;
}

