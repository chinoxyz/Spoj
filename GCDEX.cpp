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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64


#define MAXN 1000001

i64 ans[MAXN];
int phii[MAXN];


void pre_comp()
{
    phii[1]=1;
    int i,j;

    for(i=2;i<MAXN;++i)
    {
        if(!phii[i])
        {
            phii[i]=i-1;

            for(j=(i<<1);j<MAXN;j+=i)
            {
                if(!phii[j])
                {
                    phii[j]=j;
                }

                phii[j]=phii[j]/i*(i-1);
            }
        }
        ans[i]+=phii[i];
    }



    i64 ti;
    i64 k,l;

    for(k=2;(ti=k*k)<MAXN;++k)
    {
        ans[ti]+=k*phii[k];
    }

    for(k=2;k<MAXN;++k)
    {
        for(l=k+1;(ti=k*l)<MAXN;++l)
        {
            //printf("DD\n");
            ans[ti]+=k*phii[l];
            ans[ti]+=l*phii[k];
        }
    }

    for(i=2;i<MAXN;++i)
    {
        ans[i]+=ans[i-1];
    }


}

int main()
{
    freopen("Text/GCDEX.txt","r",stdin);

    pre_comp();
    int n;

    while(true)
    {
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }

        printf("%lld\n",ans[n]);
    }




    return 0;
}
