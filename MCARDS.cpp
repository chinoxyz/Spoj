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

#define INF 999999999
#define MAXN 101

int mp[5][MAXN];
int color[MAXN<<2];
int numm[MAXN<<2];
int arr[MAXN<<2];

int permm[]={1,2,3,4};
int n,c;
int tot,ct;
VI::iterator it;

int lis()
{

    int ret=0;

    VI tarr;
    tarr.PB(arr[0]);

    for(int i=1;i<tot;++i)
    {
        it=upper_bound(tarr.begin(),tarr.end(),arr[i]);
        if(it==tarr.end())
        {
            tarr.PB(arr[i]);
        }
        else
        {
            *it=arr[i];
        }
    }

    ret=tarr.size();


    return ret;
}


int main()
{
    freopen("Text/MCARDS.txt","r",stdin);

    int ans=INF;

    scanf("%d %d",&c,&n);
    tot=n*c;

    for(int i=0;i<tot;++i)
    {
        scanf("%d %d",color+i,numm+i);
    }

    do
    {

        ct=0;
        for(int i=0;i<c;++i)
        {
            for(int j=1;j<=n;++j)
            {
                mp[permm[i]][j]=++ct;
            }
        }

        for(int j=0;j<ct;++j)
        {
            arr[j]=mp[color[j]][numm[j]];
        }
        ans=min(ans,tot-lis());
    }
    while(next_permutation(permm,permm+c));

    printf("%d\n",ans);

    return 0;
}

