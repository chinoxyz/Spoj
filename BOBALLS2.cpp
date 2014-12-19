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

#define MAXN 3003

i64 x,y;
i64 n,k;
i64 pos;
pair<i64,i64> arr[MAXN];
i64 xs[MAXN],ys[MAXN],dx[MAXN],dy[MAXN];
void MAIN()
{
    scanf("%lld %lld",&x,&y);

    scanf("%lld",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%lld %lld %lld %lld",xs+i,ys+i,dx+i,dy+i);
        //printf("%lld\t%lld\t%lld\t%lld\n",xs[i],ys[i],dx[i],dy[i]);

    }
    scanf("%lld",&k);

    for(int i=0;i<k;++i)
    {
        scanf("%lld",&pos);
        //printf("%lld\n",pos);

        for(int j=0;j<n;++j)
        {
            arr[j].first=((xs[j]+pos*dx[j])%(2*x));
            if(arr[j].first<0)
            {
                arr[j].first=-arr[j].first;
            }
            if(arr[j].first>x)
            {
                arr[j].first=2*x-arr[j].first;
            }

            arr[j].second=((ys[j]+pos*dy[j])%(2*y));
            if(arr[j].second<0)
            {
                arr[j].second=-arr[j].second;
            }
            if(arr[j].second>y)
            {
                arr[j].second=2*y-arr[j].second;
            }
        }

        sort(arr,arr+n);

        for(int j=0;j<n;++j)
        {
            printf("%lld %lld\n",arr[j].first,arr[j].second);
        }
        printf("\n");
    }
}

int main()
{

	freopen("Text/BOBALLS2.txt","r",stdin);

    MAIN();

	return 0;
}
