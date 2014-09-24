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

#define MAXN 1001

int arr[MAXN][MAXN];
int n;
int ret[MAXN];

int main()
{
    freopen("Text/UCBINTA.txt","r",stdin);

    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    if(n==2)
    {
        ret[0]=1;
        ret[1]=arr[0][1]-1;
    }
    else
    {
        int diff=arr[0][1]-arr[1][2];
        ret[0]=(diff+arr[0][2])/2;

        for(int i=1;i<n;++i)
        {
            ret[i]=arr[0][i]-ret[0];
        }
    }

    for(int i=0;i<n-1;++i)
    {
        printf("%d ",ret[i]);
    }

    printf("%d\n",ret[n-1]);




    return 0;
}
