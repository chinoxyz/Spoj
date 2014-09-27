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

#define MAXN 1006

int ans[MAXN];

void pre_process()
{
    //fill(ans,ans+MAXN,MAXN+1);
    ans[0]=0;

    ans[1]=1;
    ans[2]=2;

    for(int i=3;i<MAXN;++i)
    {
        ans[i]=MAXN+1;
        for(int j=1;(j*j)<=i;++j)
        {
            ans[i]=min(ans[i],1+ans[i-(j*j)]);
        }
    }
}


int main()
{
    freopen("Text/NFURY.txt","r",stdin);

    pre_process();

    int cases,n;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }

    return 0;
}
