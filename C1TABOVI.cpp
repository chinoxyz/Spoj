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

#define MAXN 1002

int arr[MAXN];
int n;
int ans;

void solve(int x,int y)
{
    //printf("%d\t%d\n",x,y);
    if(x>y)
    {
        return;
    }

    if(x==y)
    {
        ans+=abs(arr[x]);
        return;
    }


    int i=x;

    while(i<=y)
    {
        while(i<=y && arr[i]==0)
        {
            ++i;
        }

        if(i>y)
        {
            return;
        }
        int mn=0;

        int sn=1;
        int st=i;
        if(arr[i]<0)
        {
            sn=-1;
        }
        arr[i]=abs(arr[i]);
        mn=arr[i];

        while(i+1<=y && arr[i+1] && arr[i+1]/abs(arr[i+1])==sn)
        {
            arr[i+1]=abs(arr[i+1]);
            mn=min(mn,arr[i+1]);
            ++i;
        }
        int en=i;

        ans+=mn;

        for(int j=st;j<=en;++j)
        {
            arr[j]-=mn;
        }

        solve(st,en);
    }


}



int main()
{
    freopen("Text/C1TABOVI.txt","r",stdin);

    int cases=1;

    //scanf("%d",&cases);
    int ti;

    while(cases--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",&ti);
            arr[i]-=ti;
            //printf("A\t%d\n",arr[i]);
        }

        ans=0;
        solve(0,n-1);

        printf("%d\n",ans);
    }

    return 0;
}

