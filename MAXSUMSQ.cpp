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
#define u64 unsigned i64

#define MAXN 100002
#define INF 999999999

int arr[MAXN];





int main()
{
    freopen("Text/MAXSUMSQ.txt","r",stdin);
    int cases,i,max_sum,summ,min_sum,n;
    i64 ct,rt;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);

        REP(i,n)
        {
            scanf("%d",arr+i);
        }

        max_sum=-INF;
        min_sum=summ=rt=0;
        ct=1;

        REP(i,n)
        {
            summ+=arr[i];

            if(summ-min_sum>max_sum)
            {
                max_sum=summ-min_sum;
                rt=ct;
            }
            else if(summ-min_sum==max_sum)
            {
                rt+=ct;
            }

            if(summ<min_sum)
            {
                min_sum=summ;
                ct=1;
            }
            else if(summ==min_sum)
            {
                ++ct;
            }
        }

        printf("%d %lld\n",max_sum,rt);


    }
    return 0;
}



