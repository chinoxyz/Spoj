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
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXM 10002

i64 arr[MAXM];
i64 n,m;



void solve()
{
    i64 ret=-1;

    i64 enc=1,enb=0,diff;

    for(i64 i=m-1;i>0;--i)
    {
        diff=arr[i]-arr[i-1];
        if(diff==0)
        {
            enc+=1;
        }
        else
        {
            enc-=diff;

            enb+=diff;

            if(enc<1)
            {
                enc=1;
            }
            else if(enb<0)
            {
                enb=0;
            }
        }

        if(enc+enb>n)
        {
            //poss=false;
            break;
        }

    }

    if(enb+enc<=n)
    {
        ret=enc;
    }


    printf("%lld\n",ret);
}


int main()
{
    freopen("Text/CANDYSTN.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld %lld",&n,&m);

        for(int i=0;i<m;++i)
        {
            scanf("%lld",arr+i);
        }

        solve();
    }



    return 0;
}
