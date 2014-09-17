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


const double P_I=3.14159265;


int main()
{
    freopen("Text/HAMSTER1.txt","r",stdin);

    int cases;
    int velocity,k1,k2;
    double theta,score;

    scanf("%d",&cases);
    //printf("%d\n",cases);

    while(cases--)
    {
        //scanf("%lf %lf %lf",&velocity,&k1,&k2);
        scanf("%d %d %d",&velocity,&k1,&k2);

        //printf("%lf\t%lf\t%lf\n",velocity,k1,k2);
        //printf("%d\t%d\t%d\n",velocity,k1,k2);

        if(k2==0)
        {
            theta=P_I/4.0;
        }
        else if(k1==0)
        {
            theta=P_I/2.0;
        }
        else
        {
            theta = atan(-(double)4.0*k1/(double)k2)/2.0;
			if (theta < 0)
            {
                theta += P_I/2.0;
            }
        }

        score = ((double)velocity*velocity)/10.0*(k1*sin(2.0*theta) + k2*sin(theta)*sin(theta)/2.0);
        printf("%.3lf %.3lf\n", theta, score);
    }

    return 0;
}



