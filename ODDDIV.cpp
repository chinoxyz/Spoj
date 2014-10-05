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


#define MAXK 10002

#define MAXX 100002

vector<i64> numbers[MAXK];




int main()
{
    freopen("Text/ODDDIV.txt","r",stdin);

    int cases,n;

    scanf("%d",&cases);

    for(i64 i=1;i<MAXX;++i)
    {
        i64 n=i;

        int cnt=1;

        for(i64 d=2;d*d<=n;++d)
        {
            i64 dc=0;

            while(n%d==0)
            {
                n/=d;
                ++dc;
            }

            cnt*=(2*dc+1);
        }

        if(n!=1)
        {
            cnt*=3;
        }

        numbers[cnt].PB(i*i);
    }



    while(cases--)
    {
        int k,cnt=0;

        i64 l,h;

        scanf("%d %lld %lld",&k,&l,&h);

        vector<i64>::iterator lower=lower_bound(numbers[k].begin(),numbers[k].end(),l);
        vector<i64>::iterator upper=upper_bound(numbers[k].begin(),numbers[k].end(),h);

        cnt=upper-lower;

        printf("%d\n",cnt);

    }

    return 0;
}
