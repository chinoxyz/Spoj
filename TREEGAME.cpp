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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXL 1<<17

int tree[MAXL];
int leaff;


void solve(int node,int val,int leftt,int rightt)
{
    if(leftt==rightt)
    {
        tree[node]=val;
        printf("%d",val-1);
        return;
    }

    int lc=tree[2*node],rc=tree[2*node+1],midd=(leftt+rightt)>>1,req;

    if(val==1)
    {
        req=2;
    }
    else if(lc==0 && rc==0)
    {
        req=2;
    }
    else
    {
        req=1;
    }

    if(leaff<=midd)
    {
        solve(2*node,req,leftt,midd);
    }
    else
    {
        solve(2*node+1,req,midd+1,rightt);
    }

    lc=tree[2*node];
    rc=tree[2*node+1];

    if(lc*rc)
    {
        tree[node]=val;
    }
}


int main()
{
    freopen("Text/TREEGAME.txt","r",stdin);

    int dep,n;

    scanf("%d",&dep);
    n=1<<dep;

    for(int i=1;i<n;++i)
    {
        if(i>1)
        {
            printf(" ");
        }

        scanf("%d",&leaff);
        solve(1,2,1,n);
    }

    scanf("%d",&leaff);
    printf("\n");


    return 0;
}
