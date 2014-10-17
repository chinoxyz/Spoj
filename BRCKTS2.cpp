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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXN 350005
char arr[MAXN];
int lenn;
i64 ans;
i64 height[MAXN];
i64 width[MAXN];
int ct[MAXN];
int numm;
stack<int> st;

void solve()
{
    int ti,ti2;

    for(int i=0;i<lenn;++i)
    {
        if(arr[i]=='(')
        {
            st.push(numm);
            ++numm;
        }
        else
        {
            ti=st.top();
            st.pop();

            ++height[ti];
            ++width[ti];

            if(!st.empty())
            {
                ti2=st.top();
                height[ti2]=max(height[ti2],height[ti]);
                width[ti2]+=1+width[ti];
            }

            if(ti&1)
            {
                ans-=height[ti]*width[ti];
            }
            else
            {
                ans+=height[ti]*width[ti];
            }
            --numm;
            height[ti]=width[ti]=0;

        }
    }
}


int main()
{
    freopen("Text/BRCKTS2.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        MSET(height,0);
        MSET(width,0);
        MSET(ct,0);
        numm=0;
        ans=0;
        scanf("%s",arr);
        lenn=strlen(arr);
        solve();
        printf("%lld\n",ans);
    }

    return 0;
}
