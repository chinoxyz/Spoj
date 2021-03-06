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

int n,q;

i64 tree[MAXN];

void update(int idx,i64 val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}

i64 readd(int idx)
{
    i64 ret=0;

    while(idx)
    {
        ret+=tree[idx];
        idx-=(idx&-idx);
    }
    return ret;
}



int main()
{
    freopen("Text/NAJMS.txt","r",stdin);

    char c[10];


    int cases;

    scanf("%d",&cases);
    int x,y;
    i64 v;
    i64 ti,ret;

    for(int t=1;t<=cases;++t)
    {
        MSET(tree,0);
        printf("Case %d:\n",t);
        scanf("%d %d",&n,&q);

        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&ti);
            update(i,ti);
            update(i+1,-ti);
            //printf("dd\n");
        }

        for(int i=0;i<q;++i)
        {
            scanf("%s",c);

            if(c[0]=='m')
            {
                scanf("%d",&x);
                ret=readd(x);
                update(x,-ret);
                update(x+1,ret);
            }
            else if(c[0]=='f')
            {
                scanf("%d",&x);
                printf("%lld\n",readd(x));
            }
            else
            {
                scanf("%d %d %lld",&x,&y,&v);
                update(x,v);
                update(y+1,-v);
            }
        }

        printf("\n");
    }



    return 0;
}
