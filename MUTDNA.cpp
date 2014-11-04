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

#define MAXN 1000003
char buff[MAXN];
bool arr[MAXN];
int n;

void solve()
{
    int ans=0;
    int c=0;

    for(int i=n;i>0;--i)
    {
        if(arr[i]==c)
        {
            continue;
        }

        if(arr[i]==arr[i-1])
        {
            ++ans;
            while(arr[i]==arr[i-1])
            {
                --i;
            }
            c^=1;
        }
        else
        {
            ++ans;
        }
    }



    printf("%d\n",ans);
}


int main()
{
    freopen("Text/MUTDNA.txt","r",stdin);

    scanf("%d",&n);
    scanf("%s",buff+1);

    for(int i=1;i<=n;++i)
    {
        arr[i]=buff[i]-'A';
    }

    solve();

    return 0;
}

