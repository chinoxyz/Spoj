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


int main()
{
    freopen("Text/NY10B.txt","r",stdin);

    int cases,num1,num2,summ,j,sn,base;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d %d",&sn,&base,&num1,&num2);
        j=1;
        summ=0;

        while(num1!=0 || num2!=0)
        {
            summ+=((((num1%base)+(num2%base))%base)*j);

            num1/=base;
            num2/=base;
            j*=base;
        }

        printf("%d %d\n",sn,summ);
    }


    return 0;
}
