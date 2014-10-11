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

#define MAXN 50002
int n1,n2,tot,d;

VI adj[2*MAXN];
int indeg[2*MAXN];
int indegcp[2*MAXN];


int solve(int pos)
{
    int ret=0,u,v;

    queue<int> q[2];

    for(int i=0;i<tot;++i)
    {
        if(indeg[i]==0)
        {
            if(i<n1)
            {
                q[pos].push(i);
            }
            else
            {
                q[pos^1].push(i);
            }
        }
    }

    ret+=1;
    int ct=0;

    while(ct<tot)
    {
        ++ret;
        while(!q[0].empty())
        {
            u=q[0].front();
            q[0].pop();
            ++ct;
            //printf("UU\t%d\t%d\n",pos,u);

            for(int i=0;i<adj[u].size();++i)
            {
                v=adj[u][i];
                --indeg[v];
                if(indeg[v]==0)
                {
                    if(v<n1)
                    {
                        q[pos].push(v);
                    }
                    else
                    {
                        q[pos^1].push(v);
                    }
                }
            }
        }

        if(ct==tot)
        {
            break;
        }

        ++ret;


        while(!q[1].empty())
        {
            u=q[1].front();
            q[1].pop();
            ++ct;
            //printf("UD\t%d\t%d\n",pos,u);

            for(int i=0;i<adj[u].size();++i)
            {
                v=adj[u][i];
                --indeg[v];
                if(indeg[v]==0)
                {
                    if(v<n1)
                    {
                        q[pos].push(v);
                    }
                    else
                    {
                        q[pos^1].push(v);
                    }
                }
            }
        }
    }


    return ret;
}


int main()
{
    freopen("Text/ALL.txt","r",stdin);
    int u,v;

    while(true)
    {
        scanf("%d %d %d",&n1,&n2,&d);

        if(n1==0 && n2==0 && d==0)
        {
            break;
        }
        tot=n1+n2;
        MSET(indeg,0);

        for(int i=0;i<tot;++i)
        {
            adj[i].clear();
        }

        for(int i=0;i<d;++i)
        {
            scanf("%d %d",&v,&u);
            --v;
            --u;
            ++indeg[v];
            adj[u].PB(v);
        }

        memcpy(indegcp,indeg,sizeof(indeg));
        int xx=solve(0);
        memcpy(indeg,indegcp,sizeof(indeg));
        int yy=solve(1);
        printf("%d\n",min(xx,yy));
        //printf("%d\n",solve(xx));
        //printf("%d\n",solve(yy));
    }

    return 0;
}
