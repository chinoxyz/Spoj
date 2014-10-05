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
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 1000001
int arr[MAXN];

int main()
{
    freopen("Text/MAIN12A.txt","r",stdin);

    int cases;
    scanf("%d",&cases);

    arr[0]=1;

    int curr=2;
    int en=1,j;

    for(int i=0;i<MAXN;++i)
    {
        for(j=0;j<arr[i];++j)
        {
            if(en>=MAXN)
            {
                break;
            }
            arr[en++]=curr;
        }

            if(en>=MAXN)
            {
                break;
            }

        ++curr;
    }

    int n;

    for(int t=1;t<=cases;++t)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",t,arr[n-1]);
    }


	return 0;
}
