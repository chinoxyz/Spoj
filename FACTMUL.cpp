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


#define MAXN 10000001
#define MODD 109546051211LL

u64 fact[MAXN],summ[MAXN];

u64 mul_mod(u64 a,u64 b)
{
    if(a<(MODD/100) && b<(MODD/100))
    {
        return (a*b)%MODD;
    }
    u64 ret=0;

    while(b)
    {
        if(b&1)
        {
            ret+=a;
            if(ret>=MODD)
            {
                ret-=MODD;
            }
        }

        b>>=1;
        a+=a;
        if(a>=MODD)
        {
           a-=MODD;
        }
    }

    return ret;
}

int main() {

    freopen("Text/FACTMUL.txt","r",stdin);

    u64 n;
    fact[0]=fact[1]=summ[0]=summ[1]=1LL;
    scanf("%llu",&n);

    for(u64 i=2;i<=n;++i)
    {
        fact[i]=mul_mod(fact[i-1],i);
        summ[i]=mul_mod(fact[i],summ[i-1]);
    }

    //printf("%llu\t%llu\n",summ[n],(MODD/100LL)*(MODD/100LL)/(MODD/100LL));
    printf("%llu\n",summ[n]);


	return 0;
}
