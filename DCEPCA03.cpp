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


#define MAXN 10001

int ssssss[1000000][10];

int arr[MAXN];
int cumm[MAXN];

void pre_comp()
{
    for(int i=0;i<MAXN;++i)
    {
        arr[i]=i;
    }

    cumm[0]=0;
    cumm[1]=1;

    for(int i=2;i<MAXN;++i)
    {
        if(arr[i]==i)
        {
            --arr[i];
            for(int j=i*2;j<MAXN;j+=i)
            {
                arr[j]/=i;
                arr[j]*=(i-1);
            }
        }

        cumm[i]=cumm[i-1]+arr[i];
    }
}


int main() {

    freopen("Text/DCEPCA03.txt","r",stdin);

    pre_comp();

    int cases,n;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);


        printf("%lld\n",(i64)cumm[n]*(i64)cumm[n]);
    }

	return 0;
}
