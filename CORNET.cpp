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

#define MAXN 20005
#define MODD 1000

int par[MAXN],distt[MAXN];

void findd(int node)
{
    if(node!=par[node])
    {
        findd(par[node]);
        distt[node]+=distt[par[node]];
        par[node]=par[par[node]];
    }
}


int main()
{
    freopen("Text/CORNET.txt","r",stdin);

    int cases;
    char buff[10];
    int n,oldd,neww,node;

    scanf("%d",&cases);

    while(cases--)
    {

        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            distt[i]=0;
            par[i]=i;
        }

        while(true)
        {
            //printf("DD\n");
            scanf("%s",buff);
            if(buff[0]=='O')
            {
                break;
            }

            if(buff[0]=='E')
            {
                scanf("%d",&node);
                findd(node);
                printf("%d\n",distt[node]);
            }
            else
            {
                scanf("%d %d",&oldd,&neww);
                par[oldd]=par[neww];
                distt[oldd]=distt[neww]+abs(oldd-neww)%MODD;
            }
        }
    }


    return 0;
}
