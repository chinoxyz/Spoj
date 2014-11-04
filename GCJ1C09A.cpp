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

#define MAXN 40
#define MAXL 66

i64 vis[MAXN];
char arr[MAXL];
i64 ans[MAXL];


i64 encode(char c)
{
    i64 ti;
    if(c>='a' && c<='z')
    {
        ti=c-'a';
    }
    else
    {
        ti=26+c-'0';
    }

    return ti;
}

i64 tt=0;


void solve()
{
    ++tt;
    int lenn=strlen(arr);

    MSET(vis,0LL);
    i64 n=0;
    i64 ti;

    for(i64 i=0;i<lenn;++i)
    {
        ti=encode(arr[i]);
        if(!vis[ti])
        {
            vis[ti]=1LL;
            ++n;
        }
    }

    n=max(n,2LL);
    MSET(vis,-1LL);

    ans[0]=1LL;
    ti=encode(arr[0]);
    vis[ti]=1;

    i64 nxt=0LL;

    for(i64 i=1LL;i<lenn;++i)
    {
        ti=encode(arr[i]);
        if(vis[ti]!=-1LL)
        {
            ans[i]=vis[ti];
        }
        else
        {
            vis[ti]=nxt;
            ans[i]=nxt;
            nxt+=1LL;;
            if(nxt==1LL)
            {
                nxt+=1LL;;
            }
        }
    }

    i64 ret=0LL;
    i64 p=1LL;



    for(i64 i=lenn-1LL;i>=0LL;i-=1LL)
    {
        ret+=ans[i]*p;
        p*=n;
        //printf("%lld\t%lld\n",ans[i],p);
    }

    if(ret==0LL)
    {
        ret=1LL;
    }

    printf("Case #%lld: %lld\n",tt,ret);
    //cout<<ret<<endl;

}



int main()
{
    freopen("Text/GCJ1C09A.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%s",arr);
        solve();
    }

    return 0;
}

