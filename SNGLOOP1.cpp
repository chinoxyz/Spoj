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



void MAIN()
{
    int cases;
    i64 n,m,p;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld %lld",&n,&m);
        p=(m-n)%4;

        if(p==0)
        {
            printf("1\n");
        }
        else if(p==1)
        {
            printf("3\n");
        }
        else if(p==2)
        {
            printf("9\n");
        }
        else
        {
            printf("7\n");
        }
    }
}

int main()
{
	freopen("Text/SNGLOOP1.txt","r",stdin);

    MAIN();

	return 0;
}

