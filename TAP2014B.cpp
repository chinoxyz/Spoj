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
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
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

#define MAXN 999999
char arr[MAXN];


void MAIN()
{
    int cases,n;
    int lenn;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        lenn=0;

        while(n)
        {
            if(n%3==0)
            {
                arr[lenn++]='0';
            }
            else if(n%3==1)
            {
                arr[lenn++]='+';
            }
            else
            {
                arr[lenn++]='-';
                ++n;
            }
            n/=3;
        }

        reverse(arr,arr+lenn);
        arr[lenn]=0;
        printf("%s\n",arr);
    }
}

int main()
{
	freopen("Text/TAP2014B.txt","r",stdin);

    MAIN();

	return 0;
}

