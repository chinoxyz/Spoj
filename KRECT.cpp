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

#define MAXN 104

int dp[MAXN][MAXN];
char arr[MAXN][MAXN];

int n,m,k;

int main()
{
    freopen("Text/KRECT.txt","r",stdin);

    scanf("%d %d %d",&m,&n,&k);

    int i,j,w,h;

    for(i=1;i<=m;++i)
    {
        scanf("%s",&arr[i][1]);
    }

    int ret=0,maskk,ct=0;
    int ti;
    int ti1,ti2;

    for(j=1;j<=m;++j)
    {
        ti1=m-j+1;
        for(i=1;i<=n;++i)
        {
            ti2=n-i+1;
            for(h=1;h<=ti1;++h)
            {
                for(w=1;w<=ti2;++w)
                {
                    maskk=dp[h-1][w]|dp[h][w-1];
                    ct=__builtin_popcount(maskk);
                    ti=arr[j+h-1][i+w-1]-'A';
                    if(!(maskk&(1<<ti)))
                    {
                        ++ct;
                        maskk|=(1<<ti);
                    }
                    dp[h][w]=maskk;
                    if(ct==k)
                    {
                        ++ret;
                    }
                    else if(ct>k)
                    {
                        break;
                    }
                }
            }
        }
    }

    printf("%d\n",ret);


    return 0;
}

