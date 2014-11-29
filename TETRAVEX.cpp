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

int u[9],d[9],l[9],r[9];
int upp[]={-1,-1,-1,0,1,2,3,4,5};
int leftt[]={-1,0,1,-1,3,4,-1,6,7};
bool poss;
bool used[9];
int mp[9];

void solve(int pos)
{
    if(pos==9)
    {
        poss=1;
        return;
    }

    int x=upp[pos]>=0?d[mp[upp[pos]]]:-1;
    int y=leftt[pos]>=0?r[mp[leftt[pos]]]:-1;

    for(int i=0;i<9;++i)
    {
        if(!used[i] && (x==-1 || x==u[i]) && (y==-1 || y==l[i]))
        {
            used[i]=1;
            mp[pos]=i;
            solve(pos+1);
            used[i]=0;
        }
    }
}


int main()
{
    freopen("Text/TETRAVEX.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        poss=false;
        MSET(used,0);

        for(int i=0;i<9;++i)
        {
            scanf("%d %d %d %d",u+i,r+i,d+i,l+i);
        }

        solve(0);

        if(poss)
        {
            printf("Case %d: YES\n", t);
        }
        else
        {
            printf("Case %d: NO\n",t);
        }
        if(t<cases)
        {
            printf("\n");
        }


    }


    return 0;
}
