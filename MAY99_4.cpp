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


#define MOD 10000007

int ncr_arr[101][101];


int ncr(int n,int r)
{
    if(n<r)
    {
        return 0;
    }

    if(n==r)
    {
        ncr_arr[n][r]=1;
        return ncr_arr[n][r];
    }

    if(r==1)
    {
        ncr_arr[n][r]=n;
        return ncr_arr[n][r];
    }

    if(ncr_arr[n][r]!=0)
    {
        return ncr_arr[n][r];
    }

    ncr_arr[n][r]=(ncr(n-1,r-1)+ncr(n-1,r))%MOD;

    return ncr_arr[n][r];
}


int main() {

    freopen("Text/MAY99_4.txt","r",stdin);

    int n,r;
    scanf("%d %d",&n,&r);

    if(n<r)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",ncr(n-1,r-1));
    }

    return 0;
}
