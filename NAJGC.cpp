#include <bits/stdc++.h>

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


i64 gcdd(i64 a,i64 b)
{
    if(b==0LL)
    {
        return a;
    }

    return gcdd(b,a%b);
}


int main()
{
    freopen("Text/NAJGC.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    i64 a,b,c,d;

    for(int t=1;t<=cases;++t)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        i64 n1=a*(c+1LL)+b*(d+1LL);
        i64 d1=(a+b)*(c+1LL+d);
        i64 gg=gcdd(d1,n1);

        if(gg)
        {
            n1/=gg;
            d1/=gg;
        }

        if(n1)
        {
            printf("Case %d: %lld/%lld\n",t,n1,d1);
        }
        else
        {
            printf("Case %d: 0\n",t);
        }

    }


    return 0;
}

