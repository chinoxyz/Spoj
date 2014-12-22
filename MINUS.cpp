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

#define MAXN 104
#define MAXM 10005
bool dp[MAXN][MAXM];
bool prevv[MAXN][MAXM];
int ans[MAXN];
int signn[MAXN];

int arr[MAXN];
int cts[MAXN];
int vis[MAXN];
int n,m;

bool solve(int pos,int summ)
{
    if(pos==n)
    {
        if(summ==m)
        {
            return 1;
        }
        return 0;
    }

    if(dp[pos][summ])
    {
        return 0;
    }

    dp[pos][summ]=1;

    if(solve(pos+1,summ+arr[pos]))
    {
        prevv[pos][summ+arr[pos]]=0;
        return 1;
    }

    if(solve(pos+1,summ-arr[pos]))
    {
        prevv[pos][summ-arr[pos]]=1;
        return 1;
    }

    return 0;
}

void MAIN()
{
    int cases;
    int x,y,i;
    scanf("%d",&cases);

    while(cases--)
    {
        MSET(vis,0);
        MSET(cts,0);
        MSET(ans,0);
        MSET(dp,0);
        MSET(prevv,0);
        scanf("%d %d",&n,&m);
        for(i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        if(n==1)
        {
            printf("\n");
        }
        else
        {
            dp[0][arr[0]]=1;
            dp[1][arr[0]-arr[1]]=1;
            prevv[1][arr[0]-arr[1]]=1;
            signn[0]=0;
            signn[1]=1;
            bool ti=solve(2,arr[0]-arr[1]);

            for(int i=n-1;i>0;--i)
            {
                signn[i]=prevv[i][m];
                if(prevv[i][m])
                {
                    m+=arr[i];
                }
                else
                {
                    m-=arr[i];
                }
            }

            int ct=0;


            for(int i=2;i<n;++i)
            {
                if(signn[i]==0)
                {
                    int j=i;
                    while(j<n && signn[j]==0)
                    {
                        vis[j]=1;
                        printf("%d\n",j-ct);
                        ++ct;
                        cts[j]=ct;
                        ++j;
                    }
                    i=j-1;
                }
            }

            ct=0;
            for(int i=1;i<n;++i)
            {
                if(!vis[i])
                {
                    printf("%d\n",1);
                    ++ct;
                }
            }
        }

        printf("\n");
    }
}

int main() {

	freopen("Text/MINUS.txt","r",stdin);

    MAIN();

	return 0;
}
