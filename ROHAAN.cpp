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

#define MAXN 55

int arr[MAXN][MAXN];
int ans;
int n;


int main()
{
    freopen("Text/ROHAAN.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int ti,x,y;
    int m;

    for(int t=1;t<=cases;++t)
    {
        ans=0;
        scanf("%d",&n);

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    ti=arr[i][k]+arr[k][j];
                    arr[i][j]=min(ti,arr[i][j]);
                }
            }
        }

        scanf("%d",&m);

        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&x,&y);
            ans+=arr[x][y];
        }

        printf("Case #%d: %d\n",t,ans);
    }


    return 0;
}

