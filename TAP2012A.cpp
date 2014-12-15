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

#define MAXN 505

int arr[MAXN];
int n;
int summ[MAXN];
int mx;
bool poss;

int main()
{
    freopen("Text/TAP2012A.txt","r",stdin);

    while(true)
    {
        MSET(summ,0);
        poss=1;
        scanf("%d",&n);
        if(n==-1)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
            if(arr[i])
            {
                mx=i;
            }
        }

        //printf("%d\n",mx);

        for(int i=mx;i>=0;--i)
        {
            if((arr[i]+summ[i+1])%(i+1))
            {
                poss=0;
                break;
            }

            summ[i]=summ[i+1]+(arr[i]+summ[i+1])/(i+1);
        }

        if(poss)
        {
            printf("S\n");
        }
        else
        {
            printf("N\n");
        }
    }

    return 0;
}
