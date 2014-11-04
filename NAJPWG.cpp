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

#define MAXN 100001
i64 phi[MAXN];

void pre_process()
{
    phi[1]=1LL;
    i64 i,j;

    for(i=2LL;i<MAXN;++i)
    {
        if(phi[i]==0LL)
        {
            phi[i]=i-1LL;
            for(j=i<<1;j<MAXN;j+=i)
            {
                if(phi[j]==0LL)
                {
                    phi[j]=j;
                }

                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }

    for(i=2LL;i<MAXN;++i)
    {
        phi[i]+=phi[i-1];
    }
}

inline i64 nc2(i64 n)
{
    return (n*(n-1LL)/2LL);
}

int main()
{
    freopen("Text/NAJPWG.txt","r",stdin);

    pre_process();

    int cases;
    scanf("%d",&cases);
    i64 n;

    for(int t=1;t<=cases;++t)
    {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",t,nc2(n+1)-phi[n]);
    }



    return 0;
}

