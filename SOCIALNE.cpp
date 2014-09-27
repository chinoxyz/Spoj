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


char arr[55][55];
int mem=-1,mx=-9999;
int m;


void solve(int pos)
{
    set<int> poss;

    for(int i=0;i<m;++i)
    {
        if(arr[pos][i]=='Y')
        {
            for(int j=0;j<m;++j)
            {
                if(j==pos)
                {
                    continue;
                }

                if(arr[i][j]=='Y' && arr[pos][j]=='N')
                {
                    poss.insert(j);
                }
            }
        }
    }

    int curr=poss.size();

    if(curr>mx)
    {
        mx=curr;
        mem=pos;
    }
}


int main()
{
    freopen("Text/SOCIALNE.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        mem=-1;
        mx=-999;
        scanf("%s",&arr);
        m=strlen(arr[0]);

        for(int i=1;i<m;++i)
        {
            scanf("%s",&arr[i]);
        }


        for(int i=0;i<m;++i)
        {
            solve(i);
        }

        printf("%d %d\n",mem,mx);
    }

    return 0;
}
