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

//#define gc getchar_unlocked
#define gc getchar

inline double Read_Double ( void )
{
    bool Negative = false;
    char Ch;

    while ( ! isdigit ( Ch = gc ( ) ) ) if ( Ch == '-' ) Negative = true;
        else Negative = false;

    double Ret = Ch - '0';

    while ( isdigit ( Ch = gc ( ) ) ) Ret = Ret * 10 + ( Ch - '0' );

    double Mul = 1.00;

    if ( Ch == '.' )
    {
        while ( isdigit ( Ch = gc ( ) ) )
        {
            Mul /= 10.00;

            Ret += ( Ch - '0' ) * Mul;
        }
    }

    if ( Negative ) Ret *= -1.00;

    return Ret;
}

double mn[8],mx[8];
double a,b,c,d;
int n;


int main()
{
    freopen("Text/ICAMPSEQ.txt","r",stdin);

    //scanf("%d",&n);
    n=Read_Double();
    double ans=0,ti;
    int i;

    for(i=0;i<8;++i)
    {
        mn[i]=1LL<<34;
        mx[i]=-(1LL<<34);

    }

    for(i=0;i<n;++i)
    {
        //scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        a=Read_Double();
        b=Read_Double();
        c=Read_Double();
        d=Read_Double();

        ti=a+b+c+d;

        mn[0]=min(ti,mn[0]);
        mx[0]=max(ti,mx[0]);




        ti=a+b+c-d;

        mn[1]=min(ti,mn[1]);
        mx[1]=max(ti,mx[1]);




        ti=a+b-c+d;

        mn[2]=min(ti,mn[2]);
        mx[2]=max(ti,mx[2]);



        ti=a+b-c-d;

        mn[3]=min(ti,mn[3]);
        mx[3]=max(ti,mx[3]);






        ti=a-b+c+d;

        mn[4]=min(ti,mn[4]);
        mx[4]=max(ti,mx[4]);





        ti=a-b+c-d;

        mn[5]=min(ti,mn[5]);
        mx[5]=max(ti,mx[5]);




        ti=a-b-c+d;

        mn[6]=min(ti,mn[6]);
        mx[6]=max(ti,mx[6]);






        ti=a-b-c-d;

        mn[7]=min(ti,mn[7]);
        mx[7]=max(ti,mx[7]);

    }

    for(i=0;i<8;++i)
    {
        ti=mx[i]-mn[i];
        ans=max(ans,ti);
    }

    printf("%.3f\n",ans);



    return 0;
}

