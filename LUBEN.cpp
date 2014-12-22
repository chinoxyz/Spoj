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

#define MAXN 20

char arr[MAXN<<1];

int n,h;
int fct[MAXN],fmask[MAXN],lastTime[1<<MAXN];
i64 summState[1<<MAXN];




void solve()
{
    int curr=fmask[0];
    lastTime[curr]=1;
    summState[curr]=fct[0];

    i64 summ=fct[0];
    i64 ti=0;
    int nxt;
    int ct;
    int j;
    i64 pd;

    for(int i=2;i<=h;++i)
    {
        nxt=0;
        ti=0;
        for(j=0;j<n;++j)
        {
            if(curr&(1<<j))
            {
                nxt^=fmask[j];
                ti+=fct[j];
            }
            else
            {
                ti+=(fct[j]<<1);
            }
        }

        curr=nxt;
        summ+=ti;

        if(lastTime[curr])
        {
            pd=i-lastTime[curr];
            ct=(h-i)/pd;
            i+=ct*pd;
            summ+=ct*(summ-summState[curr]);
            MSET(lastTime,0);
        }
        else
        {
            lastTime[curr]=i;
            summState[curr]=summ;
        }
    }

    printf("%lld\n",summ);
}

void MAIN()
{
    scanf("%d %d",&n,&h);

    int i;
    int j;

    for(i=0;i<n;++i)
    {
        scanf("%s",arr);
        for(j=0;j<n;++j)
        {
            if(arr[j]=='1')
            {
                fmask[i]|=1<<j;
                ++fct[i];
            }
        }
    }

    solve();
}

int main ()
{
	freopen("Text/LUBEN.txt","r",stdin);

    MAIN();

	return 0;
}
