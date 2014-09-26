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


#define MAXN 100001

i64 arr[MAXN];
int num_child,num_candy;
i64 anger_sqrt;
i64 candy_sum=0,ans=0,candy_left;


int main(){

    freopen("Text/C1LJUTNJ.txt","r",stdin);

    scanf("%d %d",&num_candy,&num_child);

    for(int i=0;i<num_child;++i)
    {
        scanf("%lld",arr+i);
        candy_sum+=arr[i];
    }

    candy_left=candy_sum-num_candy;

    sort(arr,arr+num_child);

    for(int i=0;i<num_child;++i)
    {
        anger_sqrt=min(arr[i],candy_left/(num_child-i));
        ans+=anger_sqrt*anger_sqrt;
        candy_left-=anger_sqrt;
    }

    printf("%lld\n",ans);

    return 0;
}
