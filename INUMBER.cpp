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

#define MAXN 1001

short pres[MAXN][MAXN];
short prer[MAXN][MAXN];
short qs[MAXN*MAXN];
short qr[MAXN*MAXN];
int n;
int frontt,backk;

inline void printt(int ss,int rr)
{
    if(pres[ss][rr]==10)
    {
        return;
    }

    printt(ss-pres[ss][rr],prer[ss][rr]);
    printf("%d",pres[ss][rr]);
}


int ts,s,r,tr;

inline void solve()
{
    MSET(pres,-1);
    MSET(prer,-1);
    frontt=backk=0;
    pres[0][0]=10;
    prer[0][0]=10;
    qs[0]=0;
    qr[0]=0;

    while(pres[n][0]==-1)
    {
        s=qs[frontt];
        r=qr[frontt++];

        for(int i=0;i<10;++i)
        {
            ts=s+i;
            if(ts>n)
            {
                continue;
            }
            tr=(r*10+i)%n;

            if(pres[ts][tr]==-1)
            {
                ++backk;
                qs[backk]=ts;
                qr[backk]=tr;
                pres[ts][tr]=i;
                prer[ts][tr]=r;

            }
        }
    }

    printt(n,0);
    printf("\n");


}

int main()
{
    freopen("Text/INUMBER.txt","r",stdin);

    int cases;
    scanf("%d",&cases);


    while(cases--)
    {
        scanf("%d",&n);
        solve();

    }




    return 0;
}
