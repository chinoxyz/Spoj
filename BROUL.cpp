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
#define Vi64 vector<i64>
#define Vu64 vector<u64>



int main()
{
    freopen("Text/BROUL.txt","r",stdin);

    int st,en,bet;

    while(true)
    {
        scanf("%d %d %d",&st,&bet,&en);

        if(st==0 && bet==0 && en==0)
        {
            break;
        }

        int tt=abs(st-en);

        if(tt%bet)
        {
            printf("No accounting tablet\n");
        }
        else
        {
            int ans=0;
            ans+=tt/(3*bet);
            tt%=(3*bet);

            ans+=tt/(2*bet);
            tt%=(2*bet);

            ans+=tt/bet;
            printf("%d\n",ans);
        }
    }

	return 0;
}
