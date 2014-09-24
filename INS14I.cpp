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
#define u64 unsigned i64


int n,top,finn,curr,k;
int ans[100005],num[30000005];

struct data
{
    int sn,x;
} q[100005];


inline bool cmp(const data &a,const data &b)
{
    return a.x<b.x;
}

int main()
{

    freopen("Text/INS14I.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    for(int i=1;i<=cases;++i)
    {
        scanf("%d",&q[i].x);
        ++q[i].x;
        q[i].sn=i;
    }


    sort(q+1,q+cases+1,cmp);

    k=1;
    num[1]=1;
    curr=1;
    finn=1;
    top=1;


    while(finn<=cases && q[finn].x==curr)
    {
        ans[q[finn].sn]=4;
        ++finn;
    }

    for(int i=1;finn<=cases;++i)
    {
        if(i==num[k])
        {
            curr+=5;
            while(finn<=cases && q[finn].x<curr)
            {
                ans[q[finn].sn]=5;
                ++finn;
            }

            if(top<=30000000)
            {
                num[++top]=curr;
            }

            while(finn<=cases && q[finn].x==curr)
            {
                ans[q[finn].sn]=4;
                ++finn;
            }

            ++k;
        }
        else
        {
            curr+=6;

            while(finn<=cases && q[finn].x<curr)
            {
                ans[q[finn].sn]=5;
                ++finn;
            }

            if(top<=30000000)
            {
                num[++top]=curr;
            }

            while(finn<=cases&&q[finn].x==curr)
            {
                ans[q[finn].sn]=4;
                ++finn;
            }
        }
    }


    for(int i=1;i<=cases;++i)
    {
        printf("%d\n",ans[i]);
    }


    return 0;
}
