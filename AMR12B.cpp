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

#define MAXN 1000003

set<PII > data;
int ct[MAXN];
bool def[MAXN];
int n,m;


int main()
{
    freopen("Text/AMR12B.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    bool poss;
    int x,y;

    while(cases--)
    {
        poss=false;
        scanf("%d %d",&n,&m);
        data.clear();
        MSET(ct,0);
        MSET(def,0);

        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&x,&y);
            if(x>y)
            {
                swap(x,y);
            }

            if(data.find(MP(x,y))==data.end())
            {
                data.insert(MP(x,y));
                ++ct[x];
                def[y]=1;
            }
        }

        for(int i=n;i>=1;--i)
        {
            if(ct[i]==n-i && !def[i])
            {
                printf("2 %d\n",i);
                poss=1;
                break;
            }
        }

        if(!poss)
        {
            printf("1\n");
        }
    }




    return 0;
}
