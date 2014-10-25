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



int n,k,all_summ;
VI arr[2];


void solve(int w,int l,int r)
{
    if(w==0)
    {
        return;
    }
    int mn=0;
    int summ=1;
    int poww=1;

    while(summ<w)
    {
        poww*=3;
        summ+=poww;
        ++mn;
    }

    if(poww>=w)
    {
        arr[r].PB(mn);
        w=poww-w;
        solve(w,r,l);
    }
    else
    {
        arr[r].PB(mn);
        w-=poww;
        solve(w,l,r);
    }
}




int main()
{
    freopen("Text/SCALE.txt","r",stdin);

    scanf("%d %d",&n,&k);
    int pp;

    all_summ=(pow(3,n)-1)/2;

    if(all_summ<k)
    {
        printf("-1\n");
    }
    else
    {
        solve(k,0,1);

        sort(arr[0].begin(),arr[0].end());
        sort(arr[1].begin(),arr[1].end());

        for(int i=0;i<arr[0].size();++i)
        {
            printf("%d ",arr[0][i]+1);
        }
        printf("\n");

        for(int i=0;i<arr[1].size();++i)
        {
            printf("%d ",arr[1][i]+1);
        }
        printf("\n");


    }


    return 0;
}
