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



int main()
{
	freopen("Text/TWOGAME.txt","r",stdin);

	int cases;
	scanf("%d",&cases);
	i64 a,b,ti;

	while(cases--)
    {
        scanf("%lld %lld",&a,&b);

        if(a<b)
        {
            swap(a,b);
        }

        while(b)
        {
            ti=a;
            a=b;
            b=ti%b;
        }

        while(!(a&1))
        {
            a>>=1;
        }

        if(a==1)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }


	return 0;
}
