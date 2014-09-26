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


#define CW 4.19
#define CI 2.09
#define EM 335.0

int main(){

    freopen("Text/DRINK.txt","r",stdin);

    double mw,mi,tw,ti,mi2,mw2,energy;

    while(true)
    {
        scanf("%lf %lf %lf %lf",&mw,&mi,&tw,&ti);

        if(mw==0.0 && mi==0.0)
        {
            break;
        }

        energy=mw*tw*CW+mi*ti*CI-mi*EM;

        if(energy>=0.0)
        {
            printf("0.0 g of ice and %.1lf g of water at %.1lf C\n", mw + mi, energy/ CW/ (mw + mi));
        }
        else if ( energy < 0.0 && energy <= -( mi + mw ) * EM )
        {
			energy += ( mi + mw ) * EM;
			printf("%.1lf g of ice and 0.0 g of water at %.1lf C\n", mw + mi, energy/ CI/ (mw + mi));
		}

		else if ( energy < 0.0 && energy > -( mi + mw ) * EM )
        {
			mi2 = - energy/ EM;
			mw2  = mi + mw - mi2;
			printf("%.1lf g of ice and %0.1lf g of water at 0.0 C\n", mi2, mw2);
		}
    }

    return 0;
}
