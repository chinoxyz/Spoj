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
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>



#define INF 99999999
#define MAXN 1001

int arr[MAXN];
int pos[MAXN];
int sorted[MAXN];
bool inc[MAXN];

int main()
{
    freopen("Text/SSORT.txt","r",stdin);

    int cases=0,ans=0;
    int p,q,r,s,n,tt;
    int mina,minc,st,nxt,k;

    while(true)
    {
        MSET(inc,0);
        mina=minc=INF;
        ans=0;
        ++cases;
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        MSET(pos,-1);

        for(int i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
            sorted[i]=arr[i];
            mina=min(mina,arr[i]);
            pos[arr[i]]=i;
            ans+=arr[i];
        }

        sort(sorted+1,sorted+n+1);

        for(int i=1;i<=n;++i)
        {
            if(inc[pos[sorted[i]]]==true)
            {
                continue;
            }

            if(pos[sorted[i]]==i)
            {
                inc[pos[sorted[i]]]=true;
                ans-=sorted[i];
                continue;
            }
            minc=INF;


            st=sorted[i];
            inc[pos[sorted[i]]]=true;
            minc=min(minc,sorted[i]);
            nxt=st;
            k=1;

            while(sorted[pos[nxt]]!=st)
            {
                ++k;
                nxt=sorted[pos[nxt]];
                inc[pos[nxt]]=true;
                minc=min(minc,nxt);
            }

            ans+=min((k-2)*minc,(k+1)*mina+minc);
        }


        printf("Case %d: %d\n",cases,ans);
    }

    return 0;
}
