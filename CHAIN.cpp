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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 50002

int parent[MAXN];
int tree[MAXN];
int pos[MAXN];
int arr[MAXN][3];
int n,k;


inline int findd(int x)
{
    if(x!=parent[x])
    {
        parent[x]=findd(parent[x]);
    }
    return parent[x];
}

inline bool eat(int x,int y)
{
    int px=findd(x);
    int py=findd(y);

    if(tree[px]==tree[py])
    {
        if(pos[px]==0 && pos[py]==1)
        {
            return 1;
        }
        else if(pos[px]==1 && pos[py]==2)
        {
            return 1;
        }
        else if(pos[px]==2 && pos[py]==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int t=tree[px];
        int t2=tree[py];

        int pl=pos[px];
        int pr=pos[py];

        ++pl;
        pl%=3;

        for(int i=0;i<3;++i)
        {
            if(arr[t][pl])
            {
                if(arr[t2][pr])
                {
                    parent[arr[t2][pr]]=arr[t][pl];
                }
            }
            else
            {
                if(arr[t2][pr])
                {
                    arr[t][pl]=arr[t2][pr];
                    pos[arr[t2][pr]]=pl;
                    tree[arr[t2][pr]]=tree[px];
                }
            }

            ++pl;
            ++pr;
            pl%=3;
            pr%=3;
        }
    }

    return 1;
}


inline bool same(int x,int y)
{
    int px=findd(x);
    int py=findd(y);

    if(tree[px]==tree[py])
    {
        if(px==py)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int t=tree[px];
        int t2=tree[py];

        int pl=pos[px];
        int pr=pos[py];

        for(int i=0;i<3;++i)
        {
            if(arr[t][pl])
            {
                if(arr[t2][pr])
                {
                    parent[arr[t2][pr]]=arr[t][pl];
                }
            }
            else
            {
                if(arr[t2][pr])
                {
                    arr[t][pl]=arr[t2][pr];
                    pos[arr[t2][pr]]=pl;
                    tree[arr[t2][pr]]=tree[px];
                }
            }

            ++pl;
            ++pr;
            pl%=3;
            pr%=3;
        }
    }

    return 1;
}


void MAIN()
{
    int cases;

    scanf("%d",&cases);
    int x,y,z;
    int i;
    int ct;

    while(cases--)
    {
        scanf("%d %d",&n,&k);
        MSET(arr,0);
        MSET(pos,0);
        ct=0;

        for(i=1;i<=n;++i)
        {
            parent[i]=tree[i]=arr[i][0]=i;
        }

        for(i=1;i<=k;++i)
        {
            scanf("%d %d %d",&x,&y,&z);

            if(y>n || z>n)
            {
                ++ct;
            }
            else if(x==2 && y==z)
            {
                ++ct;
            }
            else if(x==2)
            {
                if(!eat(y,z))
                {
                    ++ct;
                }
            }
            else
            {
                if(!same(y,z))
                {
                    ++ct;
                }
            }
        }


        printf("%d\n",ct);
    }


}

int main()
{
	freopen("Text/CHAIN.txt","r",stdin);

    MAIN();

	return 0;
}
