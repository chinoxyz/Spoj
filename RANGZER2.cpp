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

#define MAXN 13

int a,b;
int arr[MAXN];
i64 p10[MAXN];
int lenn;
int l[MAXN],r[MAXN];

void pree()
{
    p10[0]=1;

    for(int i=1;i<MAXN;++i)
    {
        p10[i]=p10[i-1]*10;
    }
}


int solve(int numm)
{
    int tn=numm;
    if(numm<10)
    {
        return 1;
    }

    lenn=0;
    MSET(arr,0);

    while(tn)
    {
        arr[lenn++]=tn%10;
        tn/=10;
    }

    for(int i=0;i<lenn;++i)
    {
        l[i]=numm/p10[i];
        r[i]=numm%p10[i];
    }

    int ret=1;

    for(int i=0;i<lenn-1;++i)
    {
        if(arr[i]==0)
        {
            ret+=(l[i+1]-1)*p10[i];
            ret+=r[i]+1;
        }
        else
        {
            ret+=l[i+1]*p10[i];
        }
    }

    return ret;
}

void MAIN()
{
    int cases;
    pree();

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&a,&b);
        --a;
        printf("%d\n",solve(b)-solve(a));
    }
}

int main()
{
	freopen("Text/RANGZER2.txt","r",stdin);

    MAIN();

	return 0;
}

