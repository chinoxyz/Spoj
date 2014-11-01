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

#define MAXN 104
#define INF 999999999

double distt[MAXN][MAXN];
int x[MAXN],y[MAXN],arr[MAXN];
int n;
int preff[MAXN][MAXN];
double md[MAXN];
bool vis[MAXN];


double dcalc(int i,int j)
{
    double ret=0;

    ret=pow(x[i]-x[j],2)+pow(y[i]-y[j],2);

    return ret;
}


void solve()
{
    for(int i=1;i<=n;++i)
    {
        md[i]=INF;
    }

    priority_queue< pair<double,int> > pq;

    pq.push(MP(-0,1));
    int u;
    double ti;


    while(!pq.empty())
    {
        u=pq.top().second;
        ti=-pq.top().first;

        pq.pop();
        //printf("%d\t%f\n",u,ti);

        if(vis[u])
        {
            continue;
        }

        vis[u]=1;

        md[u]=ti;

        for(int i=0;i<n-1 && arr[u];++i)
        {
            if(vis[preff[u][i]])
            {
                continue;
            }

            --arr[u];
            pq.push(MP(-(ti+distt[u][preff[u][i]]),preff[u][i]));
            //vis[preff[u][i]]=1;
        }
    }

    md[1]=0;

    for(int i=1;i<=n;++i)
    {
        printf("%f\n",md[i]);
    }

}



int main()
{
    freopen("Text/GONDOR.txt","r",stdin);

    scanf("%d",&n);

    double ti;

    for(int i=1;i<=n;++i)
    {
        scanf("%d %d %d",x+i,y+i,arr+i);
        for(int j=0;j<n-1;++j)
        {
            scanf("%d",&preff[i][j]);
        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            ti=sqrt(dcalc(i,j));
            distt[i][j]=distt[j][i]=ti;
        }
    }


    solve();



    return 0;
}

