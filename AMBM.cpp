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

i64 arr[51];
i64 n;
int k;

void solve()
{
    //printf("%lld\t%d\n",n,k);

    stack<int> st;

    for(int i=k;i>0;--i)
    {
        if(arr[i]<=n)
        {
            st.push(i);
            n-=arr[i];
        }
    }

    if(n!=0)
    {
        printf("-1\n");
    }
    else
    {
        while(st.size()>1)
        {
            printf("%d ",st.top());
            st.pop();
        }

        printf("%d\n",st.top());
    }

    //printf("%lld\t%d\n",n,k);
}


int main()
{
    freopen("Text/AMBM.txt","r",stdin);

    int cases,ti;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld %d",&n,&k);

        //printf("%lld\t%d\n",n,k);

        for(int i=0;i<k;++i)
        {
            scanf("%d",&ti);
            arr[i+1]=2*arr[i]+ti;
        }

        solve();
    }



    return 0;
}
