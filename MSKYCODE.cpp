#include <bits/stdc++.h>


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
#define Vi64 veszor<i64>
#define Vu64 veszor<u64>

#define MAXN 10002
int primes[MAXN];
bitset<MAXN> bs;
int plen;
i64 nc4[MAXN];
int arr[MAXN],mx;

void pree()
{
    nc4[4]=1;

    for(int i=5;i<MAXN;++i)
    {
        nc4[i]=nc4[i-1]*i/(i-4);
    }

    primes[plen++]=2;

    for(int i=3;i<MAXN;i+=2)
    {
        if(!bs.test(i))
        {
            primes[plen++]=i;

            for(int j=i*i;j<MAXN;j+=i)
            {
                bs.set(j);
            }
        }
    }
}


i64 solve(int numm,int pos)
{
    i64 ret;
    int i,nxt,ct=0;

    for(i=numm;i<=mx;i+=numm)
    {
        ct+=arr[i];
    }

    ret=nc4[ct];

    if(ct>=4)
    {
        for(i=pos;i<plen;++i)
        {
            nxt=numm*primes[i];
            if(nxt>mx)
            {
                break;
            }
            ret-=solve(nxt,i+1);
        }
    }

    return ret;
}

void MAIN()
{
    pree();
    int n,ti;

    while(scanf("%d",&n)==1)
    {
        MSET(arr,0);
        mx=0;

        for(int i=0;i<n;++i)
        {
            scanf("%d",&ti);
            mx=max(mx,ti);
            ++arr[ti];
        }

        printf("%lld\n",solve(1,0));
    }


}

int main()
{

	freopen("Text/MSKYCODE.txt","r",stdin);

    MAIN();

	return 0;
}
