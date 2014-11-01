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

#define MAXN 999999

int mn=0;
int ml=0;

string ans[MAXN];
i64 dp[MAXN][3];

int lenn(i64 numm)
{
    int ret=0;
    if(!numm)
    {
        ret=1;
    }
    else
    {
        while(numm)
        {
            numm/=10LL;
            ++ret;
        }
    }

    return ret;
}

char buff[55];

string nts(i64 numm)
{
    sprintf(buff,"%lld\0",numm);

    string ret(buff);

    return ret;

}

void process()
{
    string ti="";
    int l;
    int i,j;
    int tn;

    ans[mn]="";
    for(i=1;i<ml;++i)
    {
        ans[mn]+=".";
    }
    ans[mn]+=nts(1);
    ans[mn]+="\0";

    for(i=0;i<mn;i+=2)
    {
        ti="";
        l=ml-dp[i+1][1]/2-1;
        for(j=0;j<l;++j)
        {
            ti+=".";
        }
        ti+=nts(1);

        tn=dp[i+1][1]/2;
        for(j=0;j<tn;++j)
        {
            ti+=".";
        }
        ti+="\0";
        ans[i]=ti;
    }

    for(i=1;i<mn;i+=2)
    {
        ti="";
        l=ml-3-dp[i][1]-dp[i][2];

        for(j=0;j<l;++j)
        {
            ti+=".";
        }
        ti+=nts(dp[i][0]);
        ti+=".+.";

        for(j=0;j<dp[i][1];++j)
        {
            ti+="-";
        }

        ti+="\0";
        ans[i]=ti;
    }

}


int solve(int d,i64 x,i64 y)
{
    //printf("DD\n");
    mn=max(mn,d);
    if(y==1LL)
    {
        if(x==1LL)
        {
            dp[d][0]=1LL;
            return 1;
        }
    }

    if(y==0LL)
    {
        return 1;
    }

    int ti=solve(d+2,y,x%y);

    dp[d+1][0]=x/y;
    dp[d+1][1]=ti;

    if(!(x%y))
    {
        dp[d+1][0]-=1;
    }

    int tl=lenn(dp[d+1][0]);
    dp[d+1][2]=tl;

    return ti+3+tl;
}


int main()
{
    freopen("Text/CFRAC.txt","r",stdin);

    int cases=0;
    i64 x,y;
    int i;

    while(true)
    {
        ++cases;
        mn=0;
        ml=0;

        scanf("%lld %lld",&x,&y);

        if(x+y==0LL)
        {
            break;
        }

        ml=solve(0,x,y);

        process();
        printf("Case %d:\n",cases);
        printf("%lld / %lld\n",x,y);

        for(i=0;i<=mn;++i)
        {
            cout<<ans[i]<<endl;
        }
    }


    return 0;
}

