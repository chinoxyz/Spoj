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

i64 gcd(i64 a,i64 b)
{
    if(!b)
    {
        return a;
    }

    return gcd(b,a%b);
}


i64 lcm(i64 a,i64 b)
{
    return (a*b)/gcd(a,b);
}

#define MAXX 16


i64 n,cn,lc;
int k,ct;
int arr[MAXX];

int main(){

    freopen("Text/NGM2.txt","r",stdin);

    int finn;

    scanf("%d %d",&n,&k);
    cn=n;


    for(int i=0;i<k;++i)
    {
        scanf("%d",arr+i);
    }

    finn=(1<<k);

    for(int i=1;i<finn;++i)
    {
        ct=0;
        lc=1;

        for(int j=0;j<k;++j)
        {
            if(i&(1<<j))
            {
                ++ct;
                lc=lcm(lc,arr[j]);
            }
        }

        if(ct&1)
        {
            n-=cn/lc;
        }
        else
        {
            n+=cn/lc;
        }
    }

    printf("%lld\n",n);



    return 0;
}


