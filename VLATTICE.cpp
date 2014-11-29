#include<bits/stdc++.h>
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


#define MAXN 1000006

bool nprime[MAXN];
int primes[MAXN],pct,mobb[MAXN];


void pree()
{
    mobb[1]=nprime[1]=1;
    pct=0;
    int i,j;

    for(i=2;i<MAXN;++i)
    {
        if(!nprime[i])
        {
            primes[pct++]=i;
            mobb[i]=-1;
        }

        for(j=0;j<pct;++j)
        {
            if(i*primes[j]>=MAXN)
            {
                break;
            }

            nprime[i*primes[j]]=1;

            if(i%primes[j]==0)
            {
                mobb[i*primes[j]]=0;
                break;
            }

            mobb[i*primes[j]]=-mobb[i];
        }
    }

}




int main()
{
    freopen("Text/VLATTICE.txt","r",stdin);

    pree();

    int cases,n;
    i64 ans;

    scanf("%d",&cases);
    int i;

    while(cases--)
    {
        scanf("%d",&n);

        ans=3;

        for(i=1;i<=n;++i)
        {
            ans+=(i64)mobb[i]*(n/i)*(n/i)*(n/i+3);
        }

        printf("%lld\n",ans);
    }




    return 0;
}
