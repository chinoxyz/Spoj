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
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
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

#define MAXN 9999999

int arr[MAXN][3];
bool poss=0;
bool vis[MAXN][3];
int n;
bool dp[MAXN][3][4];
bool fl;

inline bool dfs(int pos,int cx,int cy)
{
    if(fl)
    {
        assert(cx>0 && cx<MAXN && cy>=0 && cy<3);
    }

    if(cy<0 || cy>2)
    {
        return 0;
    }

    if(cx<1)
    {
        if(fl)
        {
            return 0;
        }
        fl=1;
    }

    if(cx>n)
    {
        return 1;
    }

    if(arr[cx][cy]==0)
    {
        return 0;
    }

    if(vis[cx][cy])
    {
        return 0;
    }


    if(dp[cx][cy][pos])
    {
        return 0;
    }

    dp[cx][cy][pos]=1;
    vis[cx][cy]=1;



    if(arr[cx][cy]==1)
    {
        if(pos==3)
        {
            if(cy<2)
            {
                if(dfs(3,cx,cy+1))
                {
                    //printf("%d\t%d\n",cx,cy);
                    return 1;
                }
            }
        }
        else if(pos==1)
        {
            if(cy>0)
            {
                if(dfs(1,cx,cy-1))
                {
                    //printf("%d\t%d\n",cx,cy);
                    return 1;
                }
            }
        }
        else if(pos==0)
        {
            if(dfs(0,cx+1,cy))
            {
                //printf("%d\t%d\n",cx,cy);
                return 1;
            }
        }
        else
        {
            if(cx>1)
            {
                if(dfs(2,cx-1,cy))
                {
                    //printf("%d\t%d\n",cx,cy);
                    return 1;
                }
            }
        }
    }
    else
    {
        if(pos==0 || pos==2)
        {
            if(cy<2)
            {
                if(dfs(3,cx,cy+1))
                {
                    //printf("%d\t%d\n",cx,cy);
                    return 1;
                }
            }

            if(cy>0)
            {
                if(dfs(1,cx,cy-1))
                {
                    //printf("%d\t%d\n",cx,cy);
                    return 1;
                }
            }
        }
        else
        {
            if(dfs(0,cx+1,cy))
            {
                //printf("%d\t%d\n",cx,cy);
                return 1;
            }

            if(cx>1)
            {
                if(dfs(2,cx-1,cy))
                {
                    //printf("%d\t%d\n",cx,cy);
                    return 1;
                }
            }
        }
    }


    vis[cx][cy]=0;
    return 0;
}

void MAIN()
{
    int cases;
    scanf("%d",&cases);
    int j;
    int i;
    arr[0][0]=arr[0][1]=arr[0][2]=1;

    while(cases--)
    {
        scanf("%d",&n);
        //printf("N\t%d\n",n);
        poss=0;
        MSET(dp,0);

        MSET(vis,0);

        for(i=1;i<=n;++i)
        {
            for(j=0;j<3;++j)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        for(i=0;i<3;++i)
        {
            fl=0;
            if(dfs(0,0,i))
            {
                poss=1;
                break;
            }
        }

        if(poss)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}

int main()
{
	freopen("Text/MAZE.txt","r",stdin);

    MAIN();

	return 0;
}

