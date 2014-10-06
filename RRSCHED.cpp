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

#define MAXN 50003LL

struct data
{
    i64 pos;
    i64 timee;

    bool operator<(const data &b) const
    {
        if(timee==b.timee)
        {
            return pos<b.pos;
        }

        return timee<b.timee;
    }
};

i64 n;

data arr[MAXN];
i64 ans[MAXN];
i64 tree_del[MAXN];
i64 tree_timee[MAXN];

void update_del(i64 pos,i64 val)
{
    while(pos<=n)
    {
        tree_del[pos]+=val;
        pos+= (pos & -pos);
    }
}

i64 read_del(i64 pos)
{
    i64 ret=0;

    while(pos>0)
    {
        ret+=tree_del[pos];
        pos-=(pos & -pos);
    }

    return ret;
}

void update_time(i64 pos,i64 val)
{
    while(pos<=n)
    {
        tree_timee[pos]+=val;
        pos+=(pos & -pos);
    }
}

i64 read_time(i64 pos)
{
    i64 ret=0;

    while(pos>0)
    {
        ret+=tree_timee[pos];
        pos-=(pos & -pos);
    }

    return ret;
}


int main()
{
    freopen("Text/RRSCHED.txt","r",stdin);

    scanf("%lld",&n);
    i64 ti;

    for(i64 i=1;i<=n;++i)
    {
        scanf("%lld",&arr[i].timee);
        arr[i].pos=i;
    }

    sort(arr+1,arr+n+1);
/*
    for(int i=1;i<=n;++i)
    {
        printf("%d\t%lld\n",arr[i].pos,arr[i].timee);
    }
*/
    i64 ct=0,leftt,pre_left,pos;
    i64 diff;

    for(i64 i=1;i<=n;++i)
    {
        pos=arr[i].pos;
        ti=arr[i].timee;

        if(i>1 && ti==arr[i-1].timee)
        {
            ++ct;
            ans[pos]=read_time(pos)+pos-read_del(pos)+ct;
            update_del(pos,1);
        }
        else
        {
            pre_left=pos-read_del(pos);
            leftt=n-read_del(n);

            diff=arr[i].timee;
            if(i>1)
            {
                update_time(1,leftt+ct+1);
                diff-=arr[i-1].timee;
            }
            ct=0;


            update_time(1,leftt*(diff-1));
            ans[pos]=read_time(pos)+pre_left;
            update_del(pos,1);
            //update_time(1,pre_left);
            //update_time(pos+1,-pre_left);

        }
    }

    for(i64 i=1;i<=n;++i)
    {
        printf("%lld\n",ans[i]);
    }





    return 0;
}
