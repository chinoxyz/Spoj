#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>
#include <cassert>
#include<cmath>


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

#define MAXN 6250000
#define INF 0x7f7f7f7f

int distt[MAXN];
int mx;
int n,src,dest;
int a[4],b[4];

int encode(VI arr)
{
    int ret=0;
    int ti=1;

    for(int i=0;i<n;++i)
    {
        ret+=ti*arr[i];
        ti*=50;
    }

    return ret;
}

VI decode(int numm)
{
    VI ret;
    int ti=50;

    for(int i=0;i<n;++i)
    {
        ret.PB(numm%ti);
        numm/=ti;
    }

    return ret;
}

VI move1(VI v,int i,int j)
{
    int t1=a[j]-v[j];
    int t2=v[i];

    int mn=min(t1,t2);
    v[i]-=mn;
    v[j]+=mn;

    return v;
}

VI move2(VI v,int pos)
{
    VI ret;
    if(v[pos]==0)
    {
        return ret;
    }

    v[pos]=0;
    return v;
}

void solve()
{
    MSET(distt,INF);

    priority_queue<PII > pq;

    pq.push(MP(-0,src));
    VI v,v2;
    int td,x;
    int ti;

    while(!pq.empty())
    {
        td=-pq.top().first;
        x=pq.top().second;
        pq.pop();
        //printf("%d\t%d\n",td,x);

        if(distt[x]<INF)
        {
            continue;
        }
        distt[x]=td;

        v=decode(x);

        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                v2.clear();
                v2=move1(v,i,j);
                if(v2.size())
                {
                    ti=encode(v2);
                    if(distt[ti]==INF)
                    {
                        pq.push(MP(-(td+1),ti));
                    }
                }

                v2.clear();
                v2=move1(v,j,i);
                if(v2.size())
                {
                    ti=encode(v2);
                    if(distt[ti]==INF)
                    {
                        pq.push(MP(-(td+1),ti));
                    }
                }
            }
        }


        for(int i=0;i<n;++i)
        {
            v2.clear();
            v2=move2(v,i);
            if(v2.size())
            {
                ti=encode(v2);
                if(distt[ti]==INF)
                {
                    pq.push(MP(-(td+1),ti));
                }
            }
        }
    }

    if(distt[dest]==INF)
    {
        printf("NO\n");
    }
    else
    {
        printf("%d\n",distt[dest]);
    }
}




int main()
{
    freopen("Text/CTAIN.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);

        mx=pow(50,n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",a+i);
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",b+i);
        }

        src=dest=0;
        int ti=1;

        for(int i=0;i<n;++i)
        {
            src+=a[i]*ti;
            dest+=b[i]*ti;
            ti*=50;
        }

        solve();
    }





    return 0;
}

