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


#define MAXK 2000002

i64 arr[MAXK];
int n,k,v,w;

int main()
{
    freopen("Text/LKS.txt","r",stdin);

    int cases,i;

    scanf("%d %d",&k,&n);

    while(n--)
    {
        scanf("%d %d",&v,&w);

        for(i=k;i>=w;--i)
        {
            arr[i]=max(arr[i],arr[i-w]+v);
            //arr[i+1]=max(arr[i],arr[i+1]);
        }
    }

    i64 mx=arr[0];

    for(i=1;i<=k;++i)
    {
        mx=max(mx,arr[i]);
    }

    printf("%lld\n",mx);


    return 0;
}
