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

#define MAXN 500001
int n,b;
int arr[MAXN];
int mx;

bool checkk(int v)
{
    int ret=0;

    for(int i=0;i<n;++i)
    {
        ret+=ceil(arr[i]/(double)v);
    }

    if(ret>b)
    {
        return false;
    }

    return true;
}


void solve()
{
    int st=0;
    int en=mx;

    while(st<en)
    {
        int midd=(st+en)>>1;

        if(checkk(midd))
        {
            en=midd;
        }
        else
        {
            st=midd+1;
        }
    }

    printf("%d\n",st);
}


int main()
{
    freopen("Text/BALLOT.txt","r",stdin);

    while(true)
    {
        mx=0;
        scanf("%d %d",&n,&b);
        if(n==-1 && b==-1)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
            mx=max(mx,arr[i]);
        }

        solve();
    }



    return 0;
}








