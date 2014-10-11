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

#define MAXN 300002

i64 ans[MAXN][3];
i64 ct=0;
int n;
set<int> tree;
set<int>::iterator it;


int main()
{
    freopen("Text/BST.txt","r",stdin);

    int x;

    scanf("%d %d",&n,&x);
    tree.insert(tree.begin(),x);
    printf("0\n");


    while(--n)
    {
        scanf("%d",&x);
        //printf("X\t%d\n",x);
        it=tree.lower_bound(x);

        if(it==tree.end())
        {
            tree.insert(it,x);
            --it;
            --it;
            ans[*it][2]=1;
            ans[x][0]=ans[*it][0]+1;
        }
        else if(it==tree.begin())
        {
            tree.insert(it,x);
            ans[*it][1]=1;
            ans[x][0]=ans[*it][0]+1;
        }
        else
        {
            tree.insert(it,x);
            --it;
            --it;

            if(!ans[*it][2])
            {
                ans[*it][2]=1;
                ans[x][0]=ans[*it][0]+1;
            }
            else
            {
                ++it;
                ++it;
                ans[*it][1]=1;
                ans[x][0]=ans[*it][0]+1;
            }
        }

        ct+=ans[x][0];
        printf("%lld\n",ct);
    }


    return 0;
}
