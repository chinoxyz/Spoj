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

int a,b,c;
int t=0;

int gcd(int a,int b)
{
    if(a<b)
    {
        return gcd(b,a);
    }

    int ti;

    while(b)
    {
        ti=a%b;
        a=b;
        b=ti;
    }

    return a;
}
void solve()
{
    ++t;

    string ans="Yes";

    if(c%gcd(a,b))
    {
        ans="No";
    }



    printf("Case %d: %s\n",t,ans.c_str());
}


int main()
{
    freopen("Text/CEQU.txt","r",stdin);


    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&a,&b,&c);
        solve();
    }



    return 0;
}
