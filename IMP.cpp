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


int distt(PII x)
{
    return abs(x.first)+abs(x.second);
}

PII operator-(PII x,PII y)
{
    return PII(x.first-y.first,x.second-y.second);
}


int main()
{
    freopen("Text/IMP.txt","r",stdin);
    int cases=10;
    int a,b,c,d;

    while(cases--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        PII mx(a,b);
        PII mn(c,d);

        if(distt(mx)<distt(mn))
        {
            swap(mx,mn);
        }

        while(distt(mx)>distt(mn))
        {
            PII tp=mx-mn;

            if(distt(mx)>distt(tp))
            {
                if(distt(mn)>distt(tp))
                {
                    mx=mn;
                    mn=tp;
                }
                else
                {
                    mx=tp;
                }
            }
            else
            {
                break;
            }
        }

        printf("%d\n",distt(mn));
    }



    return 0;
}
