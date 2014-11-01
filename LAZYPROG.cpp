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
PIPII arr[MAXN];
int n;

const double EPS=1e-9;


void solve()
{
    int prevv=0;
    priority_queue<pair<int,int> > pq;
    double ans=0;
    int timee,ti;
    int a,durr,req;

    for(int i=0;i<n;++i)
    {
        timee=arr[i].first;
        durr=arr[i].second.second;
        a=-arr[i].second.first;

        //printf("%d\t%d\t%d\n",timee,durr,a);

        ti=prevv+durr;
        pq.push(MP(a,durr));

        if(ti<=timee)
        {
            prevv=ti;
            continue;
        }

        prevv=timee;
        req=ti-timee;

        while(req>0)
        {
            a=pq.top().first;
            ti=pq.top().second;
            pq.pop();

            timee=min(ti,req);

            ti=ti-timee;
            req-=timee;
            if(ti>0)
            {
                pq.push(MP(a,ti));
            }

            ans+=(double)timee/(double)a;
        }
    }

    printf("%.2f\n",ans);
}


int main()
{
    freopen("Text/LAZYPROG.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int x,y,z;

    while(cases--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d %d %d",&x,&y,&z);
            arr[i].second.first=-x;
            arr[i].second.second=y;
            arr[i].first=z;
        }

        sort(arr,arr+n);

        solve();
    }

    return 0;
}

