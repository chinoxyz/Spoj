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

#define MAXL 33

const int MAXN=1<<10;
i64 arr[MAXN];
i64 tarr[MAXN];
char buff[MAXL];

int n;
i64 ans;

i64 nc2(i64 numm)
{
    return numm*(numm-1LL)/2LL;
}

void MAIN()
{
    int cases;
    int lenn;
    scanf("%d",&cases);
    //cin>>cases;
    int m1,m2;
    int i,j;
    ans=0;

    while(cases--)
    {
        scanf("%d",&n);
        //cin>>n;
        MSET(arr,0);
        MSET(tarr,0);
        ans=0;

        for(i=0;i<n;++i)
        {
            scanf("%s",buff);
            //printf("%s\n",buff);
            //cin>>buff;
            lenn=strlen(buff);
            m1=0;
            for(j=0;j<lenn;++j)
            {
                m1|=(1<<(buff[j]-'0'));
            }
            ++tarr[m1];
        }

        for(i=1;i<MAXN;++i)
        {
            for(j=1;j<=i;++j)
            {
                if((j&i)==j)
                {
                    arr[j]+=tarr[i];
                }
            }
        }

        for(i=1;i<MAXN;++i)
        {
            if(__builtin_popcount(i)&1)
            {
                ans+=nc2(arr[i]);
            }
            else
            {
                ans-=nc2(arr[i]);
            }
        }

        printf("%lld\n",ans);
    }
}

int main()
{
	freopen("Text/IITKWPCH.txt","r",stdin);

    MAIN();

	return 0;
}

