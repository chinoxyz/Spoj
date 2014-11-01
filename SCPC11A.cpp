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

#define MAXN 102


int arr[MAXN];
int n,w;
int leftt,rightt;
int mx;

void solve()
{
    double ans=0.01;
    double br=1.0;
    double ti;

    for(int i=leftt;i<rightt;++i)
    {
        //printf("%d\n",arr[i]);
        ti=br*(arr[i]/(double)arr[mx]);
        //printf("TI\t%f\n",ti);
        ans+=ti;
        br-=(1.0/(double)rightt);
        //printf("%.6f\n",ans);
    }

    printf("%.6f\n",ans);
}

int main()
{
    freopen("Text/SCPC11A.txt","r",stdin);

    int ti;


    while(true)
    {
        scanf("%d %d",&n,&w);
        if(n+w==0)
        {
            break;
        }
        leftt=0;
        rightt=0;
        mx=0;

        MSET(arr,0);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&ti);
            ti/=w;
            ++arr[ti];
            rightt=max(rightt,ti);
            if(arr[ti]>arr[mx])
            {
                mx=ti;
            }
        }

        solve();
    }



    return 0;
}
