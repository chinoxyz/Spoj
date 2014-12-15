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


#define MAXN 2009
char m[MAXN],b[MAXN];
int a,n;


int main()
{
    freopen("Text/DOJO.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    int tm,tb,lm,lb;

    while(cases--)
    {
        scanf("%d %s %d %s",&n,&m,&a,&b);
        lm=strlen(m);
        lb=strlen(b);
        tm=m[lm-1]-'0';
        tb=b[lb-1]-'0';

        if((n&1 && tm&1) && !((a+tb)&1))
        {
            printf("Possible.\n");
        }
        else
        {
            printf("Impossible.\n");
        }
    }



    return 0;
}

