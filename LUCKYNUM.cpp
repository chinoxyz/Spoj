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

struct data
{
    int eight_count,six_count,modd;

    data(int x,int y,int z)
    {
        eight_count=x;
        six_count=y;
        modd=z;

    }
};


bool vis[202][202];


void solve(int x)
{
    MSET(vis,0);
    queue<data> q;
    bool poss=false;


    q.push(data(0,1,6%x));
    q.push(data(1,0,8%x));

    int ce,cs,cm;

    while(!q.empty())
    {
        ce=q.front().eight_count;
        cs=q.front().six_count;
        cm=q.front().modd;
        q.pop();

        if(vis[ce][cs])
        {
            continue;
        }

        if(cm==0)
        {
            poss=true;
            break;
        }

        if(cs+ce>=200)
        {
            continue;
        }

        if(cs>0)
        {
            q.push(data(ce,cs+1,(cm*10+6)%x));
        }
        else
        {
            q.push(data(ce,cs+1,(cm*10+6)%x));
            q.push(data(ce+1,cs,(cm*10+8)%x));
        }

    }



    if(!poss)
    {
        printf("-1\n");
    }
    else
    {
        for(int i=0;i<ce;++i)
        {
            printf("8");
        }

        for(int i=0;i<cs;++i)
        {
            printf("6");
        }
        printf("\n");
    }
}


int main(){

    freopen("Text/LUCKYNUM.txt","r",stdin);

    int cases,x;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&x);
        solve(x);
    }

    return 0;
}
