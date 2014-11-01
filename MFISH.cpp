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

int dp[MAXN];
int b[MAXN];
int n;
int m;
int press[MAXN];


int main()
{
    freopen("Text/MFISH.txt","r",stdin);

    scanf("%d",&n);
    int j;
    int summ;
    int x,y,l,prevv=0;
    bool is_first=1;

    for(int i=0;i<n;++i)
    {
        scanf("%d",b+i);
    }

    scanf("%d",&m);

    for(int i=0;i<m;++i)
    {
        scanf("%d %d",&x,&y);
        press[x-1]=y;
    }


    for(int i=0;i<n;++i)
    {
        if(!press[i])
        {
            if(i>0)
            {
                dp[i]=max(dp[i],dp[i-1]);
            }

            continue;
        }

        summ=0;
        l=max(prevv,i-press[i]+1);

        for(j=l;j<min(l+press[i],n);++j)
        {
            summ+=b[j];
        }

        prevv=j;

        if(is_first)
        {
            dp[min(l+press[i]-1,n-1)]=summ;
            is_first=0;
        }
        else
        {
            dp[min(l+press[i]-1,n-1)]=summ+dp[l-1];
        }

        for(j=min(l+press[i],n);j<min(n,i+press[i]);++j)
        {
            summ=summ+b[j]-b[j-press[i]];
            dp[j]=max(dp[j-1],dp[j-press[i]]+summ);
        }
    }

    printf("%d\n",dp[n-1]);


    return 0;
}

