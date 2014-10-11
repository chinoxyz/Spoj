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

#define MAXN 10001

VI adj[MAXN];
int indeg[MAXN];
map<string,int> mp;
int n=0;
bool onleft[MAXN];

char buff1[MAXN],buff2[MAXN];

void solve()
{
    int ct=0,u;

    queue<int> q;

    for(int i=1;i<=n;++i)
    {
        if(onleft[i] && indeg[i]==0)
        {
            q.push(i);
            ++ct;
        }
    }

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(int i=0;i<adj[u].size();++i)
        {
            --indeg[adj[u][i]];
            if(indeg[adj[u][i]]==0)
            {
                q.push(adj[u][i]);
                ++ct;
            }
        }
    }



    printf("%d\n",ct);
}



int main()
{
    freopen("Text/DEPEND.txt","r",stdin);
    int u,v;

    while(scanf("%s",buff1)!=EOF)
    {
        string s1(buff1);

        if(mp.count(s1))
        {
            v=mp[s1];
        }
        else
        {
            ++n;
            mp[s1]=n;
            v=n;
        }

        onleft[v]=true;
        scanf("%s",buff2);

        while(strcmp(buff2,"0"))
        {
            string s2(buff2);

            if(mp.count(s2))
            {
                u=mp[s2];
            }
            else
            {
                ++n;
                mp[s2]=n;
                u=n;
            }

            ++indeg [v];
            adj[u].PB(v);
            scanf("%s",buff2);
        }
    }

    solve();



    return 0;
}
