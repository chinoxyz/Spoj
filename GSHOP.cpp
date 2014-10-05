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


int arr[102];
int n,k;
int summ=0;

int main() {

	freopen("Text/GSHOP.txt","r",stdin);

    int cases;

	scanf("%d",&cases);

	while(cases--)
    {
        scanf("%d %d",&n,&k);

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        sort(arr,arr+n);

        for(int i=0;i<n && k>0 && arr[i]<0;++i)
        {
            arr[i]=-arr[i];
            --k;
        }

        if(k&1)
        {
            sort(arr,arr+n);
            arr[0]=-arr[0];
        }
        summ=0;

        for(int i=0;i<n;++i)
        {
            summ+=arr[i];
        }

        printf("%d\n",summ);
    }



    return 0;
}
