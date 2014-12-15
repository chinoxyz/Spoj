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

#define MAXN 100000

int arr[MAXN][2];
int n;
map<int,int> tot;
map<int,int> top,cand;
map<int,int>::iterator it;
bool poss;

int main()
{
    freopen("Text/NAUGHTY.txt","r",stdin);

    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        ++tot[arr[i][0]];
        ++top[arr[i][0]];

        if(tot[arr[i][0]]>=(n+1)/2)
        {
            cand[arr[i][0]]=tot[arr[i][0]];
        }

        if(arr[i][0]!=arr[i][1])
        {
            ++tot[arr[i][1]];
            if(tot[arr[i][1]]>=(n+1)/2)
            {
                cand[arr[i][1]]=tot[arr[i][1]];
            }
        }

    }

    int ans=MAXN;
    if(cand.size()==0)
    {
        printf("Impossible\n");
    }
    else
    {
        it=cand.begin();

        while(it!=cand.end())
        {
            ans=min(ans,max(0,(n+1)/2-top[it->first]));

            ++it;
        }

        printf("%d\n",ans);
    }

    return 0;
}
