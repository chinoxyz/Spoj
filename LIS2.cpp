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

#define MAXN 100001
set<PII > liss[MAXN];
set<PII >::iterator it,it2;

bool checkk(int pos,PII cand)
{
    for(it=liss[pos].begin();it!=liss[pos].end();++it)
    {
        if(it->first<cand.first && it->second<cand.second)
        {
            return true;
        }
        else if(it->first>=cand.first)
        {
            return false;
        }
    }

    return false;
}



int solve(int st,int en,PII cand)
{
    int midd;
    while(st<en)
    {
        midd=(st+en)/2;
        if(checkk(midd,cand))
        {
            st=midd+1;
        }
        else
        {
            en=midd;
        }
    }

    return st;
}


int main()
{
    freopen("Text/LIS2.txt","r",stdin);

    int x,y,n,pos,ct;

    PII p;
    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%d %d",&x,&y);
        p=PII(x,y);
        pos=solve(0,n-1,p);

        liss[pos].insert(p);
        it=liss[pos].find(p);
        ++it;

        while(it!=liss[pos].end())
        {
            if(it->first>p.first && it->second>p.second)
            {
                it2=++it;
                --it;
                liss[pos].erase(it);
                it=it2;
            }
            else
            {
                ++it;
            }
        }
    }

    ct=0;

    while(!liss[ct].empty())
    {
        ++ct;
    }

    printf("%d\n",ct);



    return 0;
}
