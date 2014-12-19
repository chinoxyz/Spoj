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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXL 222
u64 summ[MAXL];
int arr[MAXL];
int lenn;

void pree()
{
    summ[0]=1;
    summ[1]=2;
    for(int i=2;i<MAXL;++i)
    {
        summ[i]=summ[i-1]+summ[i-2];
    }

}

void solve(u64 n)
{
    for(lenn=0;lenn<MAXL;++lenn)
    {
        if(summ[lenn]>n)
        {
            break;
        }
    }
    int i,j;
    j=0;

    while(lenn>0)
    {
        arr[j]=n/summ[lenn-1];
        n%=summ[lenn-1];
        ++j;
        --lenn;
    }

    for(i=0;i<j;++i)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int main()
{
	freopen("Text/NBIN.txt","r",stdin);

	int cases;
	u64 n;
	scanf("%d",&cases);
	pree();

	while(cases--)
    {
        scanf("%llu",&n);
        solve(n);
    }


	return 0;
}
