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

#define MAXN 55

int a[MAXN];


int main()
{
    freopen("Text/MATGAME.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        int n,m;
        scanf("%d %d",&n,&m);

        int x=0;

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                scanf("%d",a+j);
            }

            int ans=0;

            for(int j=m;j--;)
            {
                ans=a[j]-(a[j]<=ans);
            }
            x^=ans;
        }

        if(x)
        {
            printf("FIRST\n");
        }
        else
        {
            printf("SECOND\n");
        }
    }



    return 0;
}
