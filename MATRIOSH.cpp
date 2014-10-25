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

#define MAXN 20000001

char buff[MAXN];
int arr[MAXN];
int n;
int mp[MAXN];
int wt[MAXN];
int ns;

inline void solve()
{
    bool poss=true;
    stack<int> st;
    st.push(0);
    int ti;
    int i;


    for(i=1;i<=n;++i)
    {
        if(arr[i]<0)
        {
            ++ns;
            mp[i]=ns;
            wt[ns]=-arr[i];

            ti=st.top();
            wt[mp[ti]]+=arr[i];
            st.push(i);
        }
        else
        {
            ti=st.top();
            st.pop();

            if(arr[ti]!=-arr[i])
            {
                poss=false;
                break;
            }
        }
    }

    if(st.size()!=1)
    {
        poss=false;
    }

    if(poss)
    {
        for(i=1;i<=ns;++i)
        {
            //printf("%d\n",wt[i]);
            if(wt[i]<=0)
            {
                poss=false;
                break;
            }
        }
    }


    if(poss)
    {
        printf(":-) Matrioshka!\n");
    }
    else
    {
        printf(":-( Try again.\n");
    }
}

int main()
{
    freopen("Text/MATRIOSH.txt","r",stdin);
    int ti;


    while(gets(buff)!=NULL)
    {
        ns=0;
        //MSET(mp,0);
        //MSET(wt,0);
        n=0;
        string s(buff);
        stringstream ss(s);

        while(ss>>ti)
        {
            arr[++n]=ti;
            //printf("%d\t",ti);
        }
        //printf("\n");

        solve();
    }



    return 0;
}
