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

#define MAXN 100004

pair<i64,i64> arr[MAXN];
int n;
int k;


int main()
{
    freopen("Text/VOLNTEER.txt","r",stdin);

    scanf("%d %d",&n,&k);
    i64 ti;

    for(int i=0;i<n;++i)
    {
        scanf("%lld",&ti);
        arr[i].first=-abs(ti);
        arr[i].second=-ti;
    }

    sort(arr,arr+n);


    i64 ans=0;
    int nct=0;

    for(int i=0;i<k;++i)
    {
        ans+=abs(arr[i].first);
        if(arr[i].second>0)
        {
            ++nct;
        }
    }

    if(nct&1)
    {
        i64 gg=-1,bb=-1,bx=-1,gx=-1;
        for(int i=k;i<n;++i)
        {
            if(arr[i].second<0)
            {
                gg=-arr[i].first;
                break;
            }
        }

        for(int i=k;i<n;++i)
        {
            if(arr[i].second>0)
            {
                bb=-arr[i].first;
                break;
            }
        }

        for(int i=k-1;i>=0;--i)
        {
            if(arr[i].second>0)
            {
                bx=-arr[i].first;
                break;
            }
        }

        for(int i=k-1;i>=0;--i)
        {
            if(arr[i].second<0)
            {
                gx=-arr[i].first;
                break;
            }
        }

        bool vis=false;
        i64 ans1,ans2;

        //printf("%lld\t%lld\t%lld\t%lld\t%lld\n",gx,bx,gg,bb,ans);

        if(bx!=-1 && gg!=-1)
        {
            vis=true;
            ans1=ans-bx+gg;
        }

        if(bb!=-1 && gx!=-1)
        {
            if(vis)
            {
                //printf("%lld\t%lld\t%lld\t%lld\t%lld\n",gx,bx,gg,bb,ans);
                ans=max(ans1,ans-gx+bb);
                //printf("%lld\t%lld\t%lld\t%lld\t%lld\n",gx,bx,gg,bb,ans);
            }
            else
            {
                vis=true;
                ans=ans-gx+bb;
            }
        }
        else if(vis)
        {
            ans=ans1;
        }

        if(!vis)
        {
            ans=0;

            for(int i=0;i<k;++i)
            {
                ans+=arr[n-i-1].first;
            }
        }
    }


    printf("%lld\n",ans);



    return 0;
}

