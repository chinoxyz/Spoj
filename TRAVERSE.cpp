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

#define MAXN 12

char arr[MAXN][MAXN];
int ct[MAXN][MAXN];

int main(){

    freopen("Text/TRAVERSE.txt","r",stdin);
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%s",&arr[i]);
    }

    ct[0][0]=1;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(arr[i][j]=='0' || ct[i][j]==0)
            {
                continue;
            }

            if(j+arr[i][j]-'0'<n)
            {
                ct[i][j+arr[i][j]-'0']+=ct[i][j];
            }

            if(i+arr[i][j]-'0'<n)
            {
                ct[i+arr[i][j]-'0'][j]+=ct[i][j];
            }

        }
    }

    printf("%d",ct[n-1][n-1]);



    return 0;
}




