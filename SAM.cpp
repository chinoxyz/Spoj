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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64


#define MAXP 500006

int arr[MAXP],nxt[MAXP],lastt[MAXP];
bool on_floor[MAXP];

int n,p,k;


void solve()
{
    priority_queue<PII > pq;

    for(int i=0;i<n;++i)
    {
        lastt[i]=p;
    }

    MSET(on_floor,0);

    for(int i=p-1;i>=0;--i)
    {
        nxt[i]=lastt[arr[i]];
        lastt[arr[i]]=i;
    }

    int fc=0,ans=0;
    PII ti;

    for(int i=0;i<p;++i)
    {
        if(on_floor[arr[i]])
        {
            pq.push(MP(nxt[i],arr[i]));
            continue;
        }

        if(fc<k)
        {
            ++ans;
            ++fc;
            on_floor[arr[i]]=true;
            pq.push(MP(nxt[i],arr[i]));
            continue;
        }

        ti=pq.top();
        pq.pop();
        on_floor[ti.second]=false;
        ++ans;
        on_floor[arr[i]]=true;
        pq.push(MP(nxt[i],arr[i]));
    }

    printf("%d\n",ans);
}

int main()
{
    freopen("Text/SAM.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&n,&k,&p);

        for(int i=0;i<p;++i)
        {
            scanf("%d",arr+i);
            --arr[i];
        }


        solve();
    }



    return 0;
}
