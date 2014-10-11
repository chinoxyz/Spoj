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



int main()
{
    freopen("Text/UCV2013C.txt","r",stdin);

    u64 d,f,b,m,p,p1,p2;

    while(true)
    {
        scanf("%lld %lld %lld %lld",&d,&f,&b,&m);

        if(d==0 && f==0 && b==0 && m==0)
        {
            break;
        }

        p=f*(f+1)/2+1;
        p1=p*b;
        p2=p1+m;

        if(p2>d)
        {
          printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n",p2-d);
        }
        else
        {
            printf("Farmer Cream will have %lld Bsf to spend.\n",d-p1);
        }
    }


    return 0;
}
