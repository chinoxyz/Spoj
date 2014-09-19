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


const long double g=9.8;

int main() {

    freopen("Text/FTHEELF.txt","r",stdin);

    long double vel,hei,ang,ans;

    while(true)
    {
        scanf("%Lf %Lf",&vel,&hei);

        if(vel==-1 || hei==-1)
        {
            break;
        }

        if(vel==0 && hei==0)
        {
            printf("0.000000\n");
        }
        else
        {
            ang=acos(sqrt((2*g*hei+vel*vel)/(2*g*hei+2*vel*vel)));;
            ans=vel*cos(ang)*(vel*sin(ang)+sqrt(vel*vel*sin(ang)*sin(ang)+2*g*hei))/g;

            printf("%.6Lf\n",ans);
        }
    }

    return 0;
}
