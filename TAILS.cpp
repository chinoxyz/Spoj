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

int arr[1<<20];

int solve(int st)
{
    if(st==0)
    {
        return 0;
    }
    queue<PII > q;
    q.push(MP(1,st));
    arr[st]=1;
    int ti,d;
    int i;

    while(true)
    {
        st=q.front().second;
        d=q.front().first;
        q.pop();

        ti=st;
        ti^=1;
        ti^=2;

        if(ti==0)
        {
            return d;
        }
        else
        {
            if(arr[ti])
            {
                continue;
            }
            q.push(MP(d+1,ti));
        }

        ti=st;
        ti^=(1<<19);
        ti^=(1<<18);

        if(ti==0)
        {
            return d;
        }
        else
        {
            if(arr[ti])
            {
                continue;
            }
            q.push(MP(d+1,ti));
        }

        for(i=1;i<19;++i)
        {
            ti=st;
            ti^=(1<<(i-1));
            ti^=(1<<i);
            ti^=(1<<(i+1));

            if(ti==0)
            {
                return d;
            }
            else
            {
                if(arr[ti])
                {
                    continue;
                }
                arr[ti]=d+1;
                q.push(MP(d+1,ti));
            }
        }
    }
}

int main()
{
    freopen("Text/TAILS.txt","r",stdin);

    int st=0;
    int ti;

    for(int i=0;i<20;++i)
    {
        scanf("%d",&ti);
        if(ti)
        {
            st|=(1<<i);
        }
    }

    printf("%d",solve(st));

    return 0;
}
