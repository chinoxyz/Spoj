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

map<i64,i64> p,q,ret;
map<i64,i64>::iterator it;

int main()
{
    freopen("Text/WPC5I.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    i64 a,b;
    i64 ans=1;
    int i,j;

    while(cases--)
    {
        p.clear();
        q.clear();
        ret.clear();
        ans=1;
        scanf("%lld %lld",&a,&b);

        for(i=2;i*i<=a;++i)
        {
            while(a%i==0)
            {
                a/= i;
                ++p[i];
            }
        }

        if(a>1)
        {
            ++p[a];
        }

        for(i=2;i*i<=b;++i)
        {
            while(b%i==0)
            {
                b/= i;
                ++q[i];
            }
        }

        if(b>1)
        {
            ++q[b];
        }


        for(it=q.begin();it!=q.end();it++)
        {
            if(it->second > p[it->first])
            {
                ret[it->first]=it->second;
            }
        }

        for(it=p.begin();it!=p.end();it++)
        {
            if(it->second > q[it->first])
            {
                if(it->second >= ret[it->first])
                {
                    ret[it->first]=it->second;
                }
            }
        }

        for(it=ret.begin();it!=ret.end();it++)
        {
            ans*=pow(it->first,it->second);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
