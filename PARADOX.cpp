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

int arr[MAXN][2];
bool vis[MAXN];
int val[MAXN];
VI adj[MAXN];
VI adjval[MAXN];


int main()
{
    freopen("Text/PARADOX.txt","r",stdin);

    int n,ti,v;

    char buff[10];
    bool poss;
    queue<PII > q;

    while(true)
    {
        while(!q.empty())
        {
            q.pop();
        }
        poss=true;
        //scanf("%d",&n);
        cin>>n;
        if(n==0)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            adj[i].clear();
            adjval[i].clear();
        }

        MSET(vis,0);

        for(int i=0;i<n;++i)
        {
            //scanf("%d %s",&arr[i][0],buff);
            cin>>arr[i][0]>>buff;
            --arr[i][0];
            if(buff[0]=='f')
            {
                arr[i][1]=0;
            }
            else
            {
                arr[i][1]=1;
            }

            adj[arr[i][0]].PB(i);
            adjval[arr[i][0]].PB(arr[i][1]);
        }


        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                v=1;
                ti=i;
                q.push(MP(ti,1));

                while(!q.empty())
                {
                    ti=q.front().first;
                    v=q.front().second;
                    q.pop();
                    //printf("%d\t%d\n",ti,v);

                    if(vis[ti])
                    {
                        if(v!=val[ti])
                        {
                            poss=false;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }

                    vis[ti]=1;
                    val[ti]=v;

                    if(v)
                    {
                        q.push(MP(arr[ti][0],arr[ti][1]));
                    }
                    else
                    {
                        q.push(MP(arr[ti][0],1^arr[ti][1]));
                    }

                    for(int j=0;j<adj[ti].size();++j)
                    {
                        if(arr[adj[ti][j]][1]==v)
                        {
                            q.push(MP(adj[ti][j],1));
                        }
                        else
                        {
                            q.push(MP(adj[ti][j],0));
                        }
                    }
                }
            }
        }

        if(poss)
        {
            printf("NOT PARADOX\n");
        }
        else
        {
            printf("PARADOX\n");
        }

    }


    return 0;
}
