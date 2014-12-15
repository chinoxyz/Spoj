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
#include<cmath>


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

#define MAXN 4006

i64 f;
int n,m;
char arr[MAXN][MAXN];
int summ[MAXN][MAXN];


inline int calc(int roww)
{
    int ret=0;

    stack<int> st;
    st.push(0);
    int ti;
    int ti2;

    for(int i=1;i<=n+1;++i)
    {
        while(st.size() && summ[roww][st.top()]>=summ[roww][i])
        {
            ti2=st.top();
            st.pop();
            if(!st.empty())
            {
                ti=summ[roww][ti2]*(i-st.top()-1);
            }
            else
            {
                ti=summ[roww][ti2]*(i-1);
            }

            ret=max(ret,ti);
        }
        st.push(i);
    }

    return ret;
}

inline int solve()
{
    //MSET(summ,0);
    int ret=0;
    int i,j;

    for(i=0;i<=n+1;++i)
    {
        summ[0][i]=0;
    }

    for(i=1;i<=m;++i)
    {
        summ[i][0]=0;
        summ[i][n+1]=0;
        for(j=1;j<=n;++j)
        {

            if(arr[i][j]=='H')
            {
                summ[i][j]=summ[i-1][j];
                ++summ[i][j];
            }
            else
            {
                summ[i][j]=0;
            }
        }

        ret=max(ret,calc(i));
    }

    return ret;
}


int main()
{
    freopen("Text/JOCHEF.txt","r",stdin);

    while(true)
    {
        scanf("%d %d",&m,&n);
        if(m+n==0)
        {
            break;
        }
        scanf("%lld",&f);

        for(int i=1;i<=m;++i)
        {
            scanf("%s",&arr[i][1]);
        }
        printf("%lld\n",f*(i64)solve());
    }



    return 0;
}
