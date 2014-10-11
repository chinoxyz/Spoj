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


#define MAXN 1000005

string arr;
i64 n,m,len;


void solve()
{
    i64 mn=999999999,mx=0;
    i64 st,ct;

    if(m<n)
    {
        mn=len;
        st=0;
        mx=0;

        while(st<len)
        {
            while(st<len && arr[st]!='a')
            {
                ++st;
                ++mx;
            }
            ct=0;

            while(st<len && arr[st]=='a')
            {
                ++ct;
                ++st;
            }

            mx+=(ct%m);
            mx+=((ct/m)*n);
        }

    }
    else if(m>n)
    {
        mx=len;

        st=0;
        mn=0;

        while(st<len)
        {
            while(st<len && arr[st]!='a')
            {
                ++st;
                ++mn;
            }
            ct=0;

            while(st<len && arr[st]=='a')
            {
                ++ct;
                ++st;
            }

            mn+=(ct%m);
            mn+=((ct/m)*n);
        }
    }
    else
    {
        mx=mn=len;
    }

    printf("%lld %lld\n",mn,mx);
}

int main()
{
    freopen("Text/IITWPC4A.txt","r",stdin);

    i64 cases;

    scanf("%lld",&cases);

    while(cases--)
    {
        cin>>arr;
        len=arr.size();
        cin>>m>>n;

        solve();
    }


    return 0;
}
