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

vector<i64> ans;



bool solve2(i64 n,i64 s)
{
        if(s > n*(n-1)/2) return false;
        if(s < -n*(n-1)/2) return false;
        if( (n/2)%2 != abs(s)%2) return false;

        if(n==1) return true;

        if(solve2(n-1,s-(n-1)))
        {
                ans.push_back(+1);
				return true;
        }
        else if(solve2(n-1,s+(n-1)))
        {
                ans.push_back(-1);
				return true;
        }

        return false;
}


void solve(i64 n,i64 s)
{
    ans.clear();

    if(solve2(n,s))
    {
        i64 summ=0;

        printf("0\n");
        for(int i=ans.size()-1;i>=0;--i)
        {
            summ+=ans[i];
        printf("%lld\n",summ);
        }
    }
    else
    {
        printf("No\n");
    }
}

int main(){

    freopen("Text/SUM1SEQ.txt","r",stdin);

    int cases;
    i64 n,S;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld %lld",&n,&S);
        solve(n,S);
        printf("\n");
    }

    return 0;
}
