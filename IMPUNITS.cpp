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

u64 arr[11][2];
int n;
u64 denn,numm;

u64 gcdd(u64 a,u64 b)
{
    if(a<b)
    {
        return gcdd(b,a);
    }

    u64 t;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }

    return a;
}


int main()
{
    freopen("Text/IMPUNITS.txt","r",stdin);
    u64 ti;

    while(true)
    {
        scanf("%d",&n);

        if(n==-1)
        {
            break;
        }
        numm=denn=1;

        for(int i=1;i<n;++i)
        {
            scanf("%llu %llu",&arr[i][0],&arr[i][1]);
            denn*=arr[i][0];
            numm*=arr[i][1];
            ti=gcdd(denn,numm);
            denn/=ti;
            numm/=ti;
        }
        printf("%llu %llu\n",denn,numm);
    }


    return 0;
}
