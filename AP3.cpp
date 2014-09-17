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



int main() {


        freopen("Text/AP3.txt","r",stdin);

        i64 cases,x,y,summ,i,a,num_terms,diff;
        long double n,cd,d;

        scanf("%lld",&cases);

        while(cases--) {
            scanf("%lld %lld %lld",&x,&y,&summ);

            d = 5.0 * y + 7.0 * x + 2.0 * summ;

            n = (d + sqrt(d * d - 48.0 * summ * (x + y))) / (2.0 * (x + y));
            num_terms = llrint(n);

            cd = (y - x) / (num_terms - 6.0);
            diff = llrint(cd);
            a = x - 2 * diff;

            printf("%lld\n",num_terms);

            for(i=0;i<num_terms;i++) {
                printf("%lld ",a + diff * i);
            }
            printf("\n");
    }
    return 0;
}
