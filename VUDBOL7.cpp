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

#define MAXN 100001
#define MAXX 10000000

VI fibb;
int fct;
int arr[MAXN];
int n;
VI::iterator it1,it2;

void pree()
{
    fibb.PB(0);
    fibb.PB(1);
    fibb.PB(2);
    fct=3;
    int ti;

    while(true)
    {
        ti=fibb[fct-1]+fibb[fct-2];
        fibb.PB(ti);
        ++fct;
        if(fibb[fct-1]>MAXX)
        {
            break;
        }
    }
}


int main()
{
    freopen("Text/VUDBOL7.txt","r",stdin);

    pree();
    int x,y;

    while(true)
    {
        scanf("%d",&n);
        if(!n)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
            it1=lower_bound(fibb.begin(),fibb.end(),arr[i]);
            if(*it1==arr[i])
            {
                continue;
            }

            it2=it1;
            --it1;

            y=*it2-arr[i];
            x=arr[i]-*it1;

            if(x==y || x>y)
            {
                arr[i]=*it2;
            }
            else if(x<y)
            {
                arr[i]=*it1;
            }
        }

        sort(arr,arr+n);

        printf("%d",arr[0]);

        for(int i=1;i<n;++i)
        {
            printf(" %d",arr[i]);
        }

        printf("\n");
    }

    return 0;
}
