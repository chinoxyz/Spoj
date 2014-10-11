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

#define MAXN 102

map<int,int> mp;
map<int,int>::iterator it;


int main()
{
    freopen("Text/PUCMM334.txt","r",stdin);
    int ans,n,ti;
    int x1,y1,x2,y2,mx,mn,sz;

    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%d",&ti);
        ++mp[ti];
    }

    sz=mp.size();
    //printf("%d\n",sz);

    if(sz>2)
    {
        ans=-1;
    }
    else if(sz==1)
    {
        x1=ti;
        y1=n;

        if(x1==0)
        {
            ans=0;
        }
        else if(x1==(n-1))
        {
            ans=n;
        }
        else
        {
            ans=-1;
        }
    }
    else
    {
        it=mp.begin();
        x1=it->first;
        y1=it->second;
        ++it;
        x2=it->first;
        y2=it->second;
        mn=min(x1,x2);
        mx=max(x1,x2);

        if(mx>=n || mn<0 || (mx-mn)!=1)
        {
            ans=-1;
        }
        else if(mx!=(n-mp[mx]))
        {
            ans=-1;
        }
        else
        {
            ans=mx;
        }

    }

    printf("%d\n",ans);


    return 0;
}
