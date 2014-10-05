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

#define MAXN 1000001

bitset<MAXN> div2;
bitset<MAXN> prime;

int main()
{
    //freopen("Text/DIV2.txt","r",stdin);

    div2.set();
    prime.set();

    for(i64 i=2;i<MAXN;++i)
    {
        if(!prime.test(i))
        {
            continue;
        }

        div2.reset(i);

        for(i64 j=i*2;j<MAXN;j+=i)
        {
            prime.reset(j);
        }

        i64 k;

        for(i64 j=1,k=i*i;k<MAXN;++j,k=i*i*j)
        {
            div2.reset(k);
        }
    }

    int ct=0;

    for(int i=2;i<MAXN;++i)
    {
        if(div2.test(i))
        {
            ++ct;
            if(ct%108==0)
            {
                printf("%d\n",i);
            }
        }
    }



    return 0;
}
