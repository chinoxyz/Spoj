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


#define MAXN 100005
#define MAXC 2005

int ct[MAXC];

int main() {

    freopen("Text/LCPC12F.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    int xx,n,num;
    i64 ans;

    for(int t=1;t<=cases;++t)
    {
        ans=0;
        MSET(ct,0);
        scanf("%d %d",&xx,&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",&num);
            if(xx-num>=0)
            {
                ans+=ct[xx-num];
            }

            ++ct[num];
        }

        printf("%d. %lld\n",t,ans);
    }

    return 0;
}
