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
char buff[MAXN];
int arr[MAXN];
int n;
int ans;
int lenn;

inline void solve()
{
    int i=0,j=-1;
    arr[i]=j;
    while(i<lenn)
    {
        while(j>=0 && buff[i]!=buff[j])
        {
            j=arr[j];
        }
        ++i;
        ++j;
        arr[i]=j;
    }

    int diff=lenn-arr[lenn];

    ans=1+(n-lenn)/diff;
}

int main()
{
    freopen("Text/FILRTEST.txt","r",stdin);

    while(true)
    {
        scanf("%d %s",&n,&buff);
        if(n==-1 && !strcmp(buff,"*"))
        {
            break;
        }
        ans=0;

        lenn=strlen(buff);
        if(lenn>n)
        {
            ans=0;
        }
        else
        {
            //MSET(arr,0);
            solve();
        }

        printf("%d\n",ans);
    }




    return 0;
}
