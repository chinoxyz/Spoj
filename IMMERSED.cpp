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

double p,c;
const double MA=14.0;

#define EPS 1e-7


double solve(double v)
{
    double ret=pow(v,c*v+1);
    return ret;
}

int main()
{
    freopen("Text/IMMERSED.txt","r",stdin);
    int cases;
    double st,en,midd;

    //scanf("%d",&cases);
    cin>>cases;
    double td;


    while(cases--)
    {
        //scanf("%f %f",&p,&c);
        cin>>p>>c;
        st=0;
        en=MA;

        while(en-st>EPS)
        {
            midd=(st+en)/2.0;

            td=solve(midd);
            if(td<(p-EPS))
            {
                st=midd;
            }
            else
            {
                en=midd;
            }

            //printf("%.6f\n",st);
            //cout<<st<<endl;
        }

        printf("%.6f\n",st);
        //cout<<st<<endl;
    }


    return 0;
}

