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

#define MAXN 100010
int n,k,p;
int arr[MAXN];
set<int> s;
set<int>::iterator sit;
int ans;
void MAIN()
{
    int cases;
    scanf("%d",&cases);
    int i;
    int ti;

    while(cases--)
    {
        s.clear();
        scanf("%d %d %d",&n,&k,&p);

        for(i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
            arr[i]=(arr[i-1]+arr[i])%p;
        }

        ans=p;

        for(i=n;i>=0;--i)
        {
            ti=arr[i];
            sit=s.lower_bound(ti+k);

            if(sit!=s.end())
            {
                ans=min(ans,*sit-ti);
            }
            s.insert(ti);
            s.insert(ti+p);
        }

        printf("%d\n",ans);
    }


}

int main()
{

	freopen("Text/PARTSUM.txt","r",stdin);

    MAIN();

	return 0;
}
