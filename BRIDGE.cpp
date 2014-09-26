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

#define MAXN 1005

PII arr[MAXN];
VI last;
int n;

int longest_non_dec_seq()
{
    last.clear();
    last.PB(arr[0].second);
    VI::iterator it;

    for(int i=1;i<n;++i)
    {
        it=upper_bound(last.begin(),last.end(),arr[i].second);
        if(it==last.end())
        {
            last.PB(arr[i].second);
        }
        else
        {
            *it=arr[i].second;
        }
    }

    return last.size();
}

int main(){

    freopen("Text/BRIDGE.txt","r",stdin);

    int cases,ti;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",&ti);
            arr[i].first=ti;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",&ti);
            arr[i].second=ti;
        }

        sort(arr,arr+n);

        printf("%d\n",longest_non_dec_seq());
    }

    return 0;
}




