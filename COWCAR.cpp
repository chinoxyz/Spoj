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



#define MAXN 50002

int num_cows,num_highways,speed_reduction,min_speed;
int ct=0;

VI arr;


int main()
{
    freopen("Text/COWCAR.txt","r",stdin);

    scanf("%d %d %d %d",&num_cows,&num_highways,&speed_reduction,&min_speed);
    int itr=0,ti,ms;
    VI::iterator it;

    for(int i=0;i<num_cows;++i)
    {
        scanf("%d",&ti);
        arr.PB(ti);
    }

    sort(arr.begin(),arr.end());

    int st=0,en;
    while(true)
    {
        ms=min_speed+itr*speed_reduction;
        it=lower_bound(arr.begin()+st,arr.end(),ms);

        if(it==arr.end())
        {
            break;
        }

        st=it-arr.begin();
        ++itr;
        en=min(st+num_highways-1,num_cows-1);
        ct+=en-st+1;
        st=en+1;
        if(st>=num_cows)
        {
            break;
        }
    }

    printf("%d\n",ct);

    return 0;
}
