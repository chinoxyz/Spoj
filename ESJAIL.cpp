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

#define MAXN 100003
#define MAXM 100004

int first_edge[MAXN],to[MAXM<<1],nxt[MAXM<<1];
int n,m;
int k;
int ktl[MAXN],ltk[MAXN];
int e;
bool kf[MAXN];
bool vis[MAXN];

void add_edge(int x,int y)
{
    to[e]=y;
    nxt[e]=first_edge[x];
    first_edge[x]=e++;

    to[e]=x;
    nxt[e]=first_edge[y];
    first_edge[y]=e++;
}

bool poss;
void solve()
{
    queue<int> ff;
    queue<int> ss;

    if(ltk[1])
    {
        return;
    }


    ff.push(1);
    if(ktl[1])
    {
        kf[ktl[1]]=true;
    }
    vis[1]=1;
    bool changee;
    int ti;
    int v;

    //printf("DD\n");

    while(true)
    {
        while(!ff.empty())
        {

            ti=ff.front();
            ff.pop();
            //printf("%d\n",ti);

            for(int i=first_edge[ti];i!=-1;i=nxt[i])
            {
                v=to[i];
                if(v==n)
                {
                    poss=true;
                    return;
                }
                if(vis[v])
                {
                    continue;
                }
                vis[v]=true;
                if(ktl[v])
                {
                    ff.push(v);
                    kf[ktl[v]]=1;
                }
                else if(ltk[v])
                {
                    if(kf[v])
                    {
                        ff.push(v);
                    }
                    else
                    {
                        ss.push(v);
                    }
                }
                else
                {
                    ff.push(v);
                }
            }
        }

        changee=false;
        int sz=ss.size();

        for(int i=0;i<sz;++i)
        {
            ti=ss.front();
            ss.pop();

            if(kf[ti])
            {
                ff.push(ti);
                changee=1;
            }
            else
            {
                ss.push(ti);
            }
        }

        if(!changee)
        {
            return;
        }
    }

}

int main()
{
	freopen("Text/ESJAIL.txt","r",stdin);

	int x,y;

	while(true)
    {
        poss=false;
        e=0;
        scanf("%d %d %d",&n,&k,&m);
        if(n+k+m==-3)
        {
            break;
        }

        MSET(first_edge,-1);
        MSET(ktl,0);
        MSET(ltk,0);
        MSET(kf,0);
        MSET(vis,0);

        for(int i=0;i<k;++i)
        {
            scanf("%d %d",&x,&y);
            ktl[x]=y;
            ltk[y]=x;
        }

        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&x,&y);
            add_edge(x,y);
        }

        solve();
        if(poss)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }


	return 0;
}

