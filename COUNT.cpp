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

#define MAXN 5001
#define MODD 1988

int ans[MAXN][MAXN];


int main(){

    freopen("Text/COUNT.txt","r",stdin);

    ans[0][0]=ans[1][1]=1;
    int n,k;

    for(int x=2;x<MAXN;++x)
    {
        for(int y=1;y<=x/2;++y)
        {
            ans[x][y]=ans[x-1][y-1]+ans[x-y][y];
            ans[x][y]%=MODD;
        }

        for(int y=x/2+1;y<=x;++y)
        {
            ans[x][y]=ans[x-1][y-1];
            ans[x][y]%=MODD;
        }
    }


    while(true)
    {
        scanf("%d %d",&n,&k);

        if(n==0 &&k==0)
        {
            break;
        }

        printf("%d\n",ans[n][k]);
    }

    return 0;
}




