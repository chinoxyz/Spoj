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


#define MAXN 101

char buff[5000000];

map<string, int> mp;
string arr[MAXN];
int cts[MAXN];


int n;


int scoree(int len)
{
    if(len==0)
    {
        return 0;
    }

    if(len<=4)
    {
        return 1;
    }

    if(len==5)
    {
        return 2;
    }

    if(len==6)
    {
        return 3;
    }

    if(len==7)
    {
        return 5;
    }


    return 11;
}

map<string,int>::iterator it1,it2;


void solve()
{
    int ti;
    int ret=0;
    string ts;
    for(int i=0;i<n;++i)
    {
        ti=0;
        stringstream ss(arr[i]);

        while(ss>>ts)
        {
            if(mp[ts]==1)
            {
                ti+=scoree(ts.size());
            }
        }

        ret=max(ret,ti);
    }


    printf("%d\n",ret);
}

int main()
{
    freopen("Text/BOGGLE.txt","r",stdin);

    scanf("%d ",&n);
    string ts;
    int ct;

    for(int i=0;i<n;++i)
    {
        ct=0;
        getline(cin,arr[i]);
        stringstream ss(arr[i]);

        while(ss>>ts)
        {
            ++mp[ts];
            ++ct;
        }

        cts[i]=ct;
    }

    solve();

    return 0;
}
