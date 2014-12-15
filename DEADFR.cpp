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


#define MAXL 55

char nstr[MAXL];
char non_repeating[MAXL];
char repeating[MAXL];

struct fraction
{
    i64 numerator,denominator;
};

inline i64 gcd(i64 a,i64 b)
{
    if(!b)
    {
        return a;
    }

    return gcd(b,a%b);

}

int lenn;

fraction arr[MAXL];


int main()
{
    freopen("Text/DEADFR.txt","r",stdin);
    int rlenn,nrlenn,st,tr;
    i64 nr,denn;
    i64 numm,poww,td,g;
    int ct;
    i64 ansd,ansn;

    while(true)
    {
        scanf("%s",nstr);
        ct=0;


        if(strcmp(nstr,"0")==0)
        {
            break;
        }

        lenn=0;

        while(nstr[lenn]!='\0')
        {
            ++lenn;
        }

        rlenn=0;
        rlenn=1;


        while(nstr[lenn-rlenn-3]!='.')
        {
            st=2;
            nrlenn=0;

            while(nstr[st+rlenn+3]!='\0')
            {
                non_repeating[nrlenn]=nstr[st];
                ++st;
                ++nrlenn;
            }

            non_repeating[nrlenn]='\0';

            tr=0;

            while(nstr[st]!='.')
            {
                repeating[tr]=nstr[st];
                ++st;
                ++tr;
            }

            repeating[tr]='\0';

            sscanf(repeating,"%lld",&nr);
            denn=9;

            tr=1;

            while(tr<rlenn)
            {
                denn*=10;
                denn+=9;
                ++tr;
            }

            numm=nr;

            if(nrlenn>0)
            {
                poww=(i64)pow(10,nrlenn);
                sscanf(non_repeating,"%lld",&td);
                td*=denn;
                denn*=poww;
                numm+=td;
            }

            if(numm!=0)
            {
                g=gcd(denn,numm);
                arr[ct].numerator=numm/g;
                arr[ct].denominator=denn/g;
                ++ct;
            }

            ++rlenn;
        }

        ansd=arr[0].denominator;
        ansn=arr[0].numerator;

        for(int i=1;i<ct;++i)
        {
            if(arr[i].denominator<ansd)
            {
                ansd=arr[i].denominator;
                ansn=arr[i].numerator;
            }
        }


        printf("%lld/%lld\n",ansn,ansd);

    }


    return 0;
}

