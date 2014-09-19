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






int main(){

    freopen("Text/TIPTOP.txt","r",stdin);

    int t,i;
    scanf("%i", &t);

    for(i=1; i<=t; i++)
    {
        unsigned long long n;
        scanf("%llu", &n);
        unsigned long long s=sqrt(n);

        if(s*s==n || (s-1)*(s-1)==n || (s+1)*(s+1)==n)
        {
            printf("Case %i: Yes\n", i);
        }
        else
        {
            printf("Case %i: No\n", i);
        }
 }
return 0;

    return 0;
}
