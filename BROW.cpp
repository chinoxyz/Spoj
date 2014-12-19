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


#define MAXN 9999999
#define INF 999999999999999999LL
#define EPS 1e-8

i64 demand[MAXN<<1],distt[MAXN<<1];
i64 demsumm[MAXN<<1],dissumm[MAXN<<1];
i64 ans;
i64 n;


void MAIN()
{
    int cases;
    scanf("%d",&cases);
    int i;
    i64 ti;
    i64 tdistt,tdem;
    int l,r;
    i64 tr,tl;
    int st,en;

    while(cases--)
    {
        scanf("%lld",&n);
        ans=INF;
        tdistt=0;
        tr=0;
        tl=0;

        for(i=1;i<=n;++i)
        {
            scanf("%lld %lld",demand+i,distt+i+1);
            demand[n+i]=demand[i];
            distt[n+i+1]=distt[i+1];
            tdistt+=distt[i+1];
        }

        for(i=1;i<=(n<<1)+1;++i)
        {
            demsumm[i]=demsumm[i-1]+demand[i];
            dissumm[i]=dissumm[i-1]+distt[i];
            if(2*dissumm[i]<=tdistt)
            {
                r=i;
            }
        }



        tdistt=dissumm[n+1];
        tdem=demsumm[n];

        l=r+1;
        st=1;
        en=n+1;

        for(i=1;i<=r;++i)
        {
            tr+=dissumm[i]*demand[i];
        }

        for(i=l;i<en;++i)
        {
            tl+=(dissumm[en]-dissumm[i])*demand[i];
        }

        ans=min(ans,tr+tl);

        for(i=1;i<n;++i)
        {
            ++en;
            ++st;


            tl+=(demsumm[en-1]-demsumm[l-1])*(distt[st]);
            tr-=(distt[st])*(demsumm[r]-demsumm[st-1]);

            while(true)
            {
                ++r;
                if(2*(dissumm[r]-dissumm[st])>tdistt)
                {
                    --r;
                    break;
                }

                tr+=(dissumm[r]-dissumm[st])*demand[r];
                tl-=(tdistt-dissumm[r]+dissumm[st])*demand[r];
            }
            l=r+1;

            ans=min(ans,tl+tr);
        }

        printf("%lld\n",ans);

    }

}

int main()
{
	freopen("Text/BROW.txt","r",stdin);

    MAIN();

	return 0;
}

