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


i64 solve(i64 numm)
{
    i64 arr[12];

    int lenn=0;

    i64 ti=numm;

    while(ti)
    {
        arr[lenn]=ti%10;
        ti/=10;
        ++lenn;
    }

    reverse(arr,arr+lenn);
    i64 ret=0;
    i64 poww=1;
    for(int i=1;i<lenn;++i)
    {
        poww*=5;
        ret+=poww;
    }

    for(int i=0;i<lenn;++i)
    {
        ret+=(((arr[i])/2LL)*pow(5,lenn-i-1));
        if((arr[i]&1)==0)
        {
            break;
        }
    }

    if(lenn)
    {
        bool poss=1;
        for(int i=0;i<lenn;++i)
        {
            if((arr[i]&1)==0)
            {
                poss=0;
                break;
            }
        }

        if(poss)
        {
            ++ret;
        }
    }


    //printf("RET\t%lld\n",ret);


    return ret;


}

int main()
{
    freopen("Text/GEEKOUNT.txt","r",stdin);

    int cases;
    i64 l,r;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld %lld",&l,&r);
        --l;
        //++r;

        printf("%lld\n",r-l-(solve(r)-solve(l)));

    }



    return 0;
}




