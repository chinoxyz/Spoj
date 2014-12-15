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

#define MAXN 505
PII deg[MAXN];
int ct[MAXN];
int gr[MAXN][MAXN];



int main()
{
    freopen("Text/XYI.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    int ans=1;
    int x,y;
    int n,m;
    int ti;

    for(int t=1;t<=cases;++t)
    {
        ans=1;
        scanf("%d %d",&n,&m);

        MSET(deg,0);
        MSET(ct,0);
        MSET(gr,0);

        for(int i=1;i<=n;++i)
        {
            deg[i].second=i;
        }

        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&x,&y);
            --deg[x].first;
            --deg[y].first;
            --ct[x];
            --ct[y];
            gr[x][y]=1;
            gr[y][x]=1;
        }

        sort(deg+1,deg+n+1);

        if(deg[1].first==-4)
        {
            if(deg[2].first<-2)
            {
                ans=1;
            }
            else
            {
                ti=deg[1].second;
                for(int i=1;i<=n;++i)
                {
                    if(!gr[ti][i])
                    {
                        continue;
                    }
                    for(int j=i+1;j<=n;++j)
                    {
                        if(gr[ti][j] && gr[i][j])
                        {
                            ans=0;
                            break;
                        }
                    }
                    if(!ans)
                    {
                        break;
                    }
                }

                if(!ans)
                {
                    ans=1;
                }
                else
                {
                    ans=4;
                }
            }
        }
        else if(deg[1].first==-3)
        {
            if(deg[2].first<-2)
            {
                ans=1;
            }
            else
            {
                ti=deg[1].second;
                for(int i=1;i<=n;++i)
                {
                    if(!gr[ti][i])
                    {
                        continue;
                    }
                    for(int j=i+1;j<=n;++j)
                    {
                        if(gr[ti][j] && gr[i][j])
                        {
                            ans=0;
                            break;
                        }
                    }
                    if(!ans)
                    {
                        break;
                    }
                }

                if(!ans)
                {
                    ans=1;
                }
                else
                {
                    ans=3;
                }
            }
        }
        else if(deg[1].first==-2)
        {
            if(deg[n].first==-1 && deg[n-1].first==-1)
            {
                ans=2;
            }
        }
        else
        {
            ans=1;
        }

        printf("Case %d: ",t);

        if(ans==1)
        {
            printf("NotValid\n");
        }
        else if(ans==2)
        {
            printf("I\n");
        }
        else if(ans==3)
        {
            printf("Y\n");
        }
        else
        {
            printf("X\n");
        }
    }


    return 0;
}
