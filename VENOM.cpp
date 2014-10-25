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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXN 1000005


int main()
{
    freopen("Text/VENOM.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    int ti;
    int health,poison,heal;
    double ans;

    while(cases--)
    {
        ans=0;
        scanf("%d %d %d",&health,&poison,&heal);

        if(health>0)
        {
            health-=poison;
        }

        if(health<=0)
        {
            ans=1;
        }
        else
        {
            ans=1;
            ans+=2.0*ceil(((2.0*heal-3.0*poison)+sqrt(pow(2.0*heal-3.0*poison,2)+8.0*poison*health))/(2.0*poison));
        }

        printf("%.0f\n",ans);
    }

    return 0;
}
