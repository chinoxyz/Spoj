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

#define MAXN 1005

int x[MAXN];
int y[MAXN];



int main()
{
    freopen("Text/SWTHIN.txt","r",stdin);

    int n;
    int cases=0;
    int ans,ct;

    while(true)
    {
        scanf("%d",&n);
        if(!n)
        {
            break;
        }

        ++cases;
        ans=0;

        for(int i=0;i<n;++i)
        {
            scanf("%d %d",x+i,y+i);
        }

        for(int i=0;i<n-2;++i)
        {
            for(int j=i+1;j<n-2;++j)
            {
                int a=y[i]-y[j];
                int b=x[j]-x[i];
                int c=y[i]*x[j]-y[j]*x[i];
                ct=2;

                for(int k=j+1;k<n;++k)
                {
                    if(a*x[k]+b*y[k]==c)
                    {
                        ++ct;
                    }
                }
                ans=max(ans,ct);
            }
        }

        if(ans>=4)
        {
            printf("Photo %d: %d points eliminated\n",cases,ans);
        }
        else
        {
            printf("Photo %d: 0 points eliminated\n",cases);
        }
    }


    return 0;
}
