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

#define MAXN 1000002
bool arr[MAXN];

void pree()
{

    int s=sqrt(MAXN);
    int i,j,k;
    int ti;
    for(i=1;i<=s;++i)
    {
        for(j=i+1;j<=s;++j)
        {
            for(k=1;(ti=k*(i*i+j*j))<MAXN;++k)
            {
                //printf("DD\n");
                arr[ti]=1;
            }
        }
    }
}

void MAIN()
{
    int cases;
    pree();
    scanf("%d",&cases);
    int n;


    while(cases--)
    {
        scanf("%d",&n);
        if(arr[n])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}

int main()
{
	freopen("Text/TRIISO.txt","r",stdin);

    MAIN();

	return 0;
}

