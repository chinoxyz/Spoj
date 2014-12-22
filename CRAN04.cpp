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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MAXN 1000005
i64 n,k;
i64 ans;
char arr[MAXN];

i64 nc2(i64 a)
{
    return a*(a-1)/2;
}

void solve0()
{
    int i,j;
    for(i=0;i<n;++i)
    {
        if(arr[i]=='0')
        {
            for(j=i+1;j<n;++j)
            {
                if(arr[j]=='1')
                {
                    break;
                }
            }

            ans+=nc2(j-i+1);
            i=j;
        }
    }
}

void solve()
{
    int i,j;
    int a,b,c,d;
    a=-1;
    b=-1;
    d=-1;
    int ct=0;

    for(i=0;i<n;++i)
    {

        if(arr[i]=='1')
        {
            b=i;
            for(j=i;j<n;++j)
            {
                if(arr[j]=='1')
                {
                    ++ct;
                    if(ct==k)
                    {
                        c=j;
                        break;
                    }
                }
            }

            if(ct<k)
            {
                return;
            }
            for(j=c+1;j<n;++j)
            {
                if(arr[j]=='1')
                {
                    d=j;
                    break;
                }
            }
            if(j>=n)
            {
                d=j;
            }

            ans+=(b-a)*(d-c);
            break;
        }
    }

    for(i=b+1;i<n;++i)
    {
        if(d>=n)
        {
            return;
        }
        if(arr[i]=='1')
        {
            a=b;
            b=i;
            for(j=d+1;j<n;++j)
            {
                if(arr[j]=='1')
                {
                    break;
                }
            }
            c=d;
            d=j;
            ans+=(b-a)*(d-c);
            i=b;
        }
    }
}

void MAIN()
{
    int cases;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld %lld",&n,&k);
        scanf("%s",arr);
        ans=0;

        if(k==0)
        {
            solve0();
        }
        else
        {
            solve();
        }

        printf("%lld\n",ans);
    }
}

int main()
{
	freopen("Text/CRAN04.txt","r",stdin);

    MAIN();

	return 0;
}

