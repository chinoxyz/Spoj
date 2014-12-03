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

#define MAXN 4006

i64 n,m,f;
char arr[MAXN][MAXN];
int summ[MAXN][MAXN];


int solve()
{
    MSET(summ,0);
    int ret=0;
    int ct=0;
    int ti;
    int i,l,j,r;

    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            summ[i][j]+=summ[i][j-1];
            if(arr[i][j]=='H')
            {
                ++summ[i][j];
            }
        }
    }

    for(l=1;l<=n;++l)
    {
        for(r=l;r<=n;++r)
        {
            ti=r-l+1;
            for(i=1;i<=m;++i)
            {
                if((summ[i][r]-summ[i][l-1])==ti)
                {
                    ++ct;
                    ret=max(ret,ct*ti);
                }
                else
                {
                    ct=0;
                }
            }
        }
    }



    return ret;
}


int main()
{
    freopen("Text/JOCHEF.txt","r",stdin);

    while(true)
    {
        scanf("%lld %lld",&m,&n);
        if(m+n==0LL)
        {
            break;
        }
        scanf("%lld",&f);

        for(int i=1;i<=m;++i)
        {
            scanf("%s",&arr[i][1]);
            //printf("%s\n",&arr[i][1]);
        }
        printf("%lld\n",f*(i64)solve());
    }



    return 0;
}
