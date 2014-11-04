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


#define MAXN 10005
char buff[MAXN];
VI dp[26];
string arr[MAXN/2];
int t,n;
int gl[26];
int locc[26];

void solve()
{
    MSET(gl,0);

    for(int i=0;i<26;++i)
    {
        dp[i].clear();
    }

    for(int i=0;i<n;++i)
    {
        int lenn=arr[i].size();
        MSET(locc,0);
        int mx=0;

        for(int j=0;j<lenn;++j)
        {
            ++gl[arr[i][j]-'a'];
            ++locc[arr[i][j]-'a'];
            mx=max(mx,locc[arr[i][j]-'a']);
        }

        int ct=0;
        int candd=-1;

        for(int j=0;j<26;++j)
        {
            if(locc[j]==mx)
            {
                ++ct;
                candd=j;
            }
        }

        if(ct>1)
        {
            continue;
        }

        dp[candd].PB(i);
    }

    int mx=0;
    int candd=-1;

    for(int i=0;i<26;++i)
    {
        if(gl[i]>mx)
        {
            mx=gl[i];
            candd=i;
        }
    }

    printf("Case #%d:\n",t);

    for(int i=0;i<dp[candd].size();++i)
    {
        cout<<arr[dp[candd][i]]<<endl;
    }


}


int main()
{
    freopen("Text/DCEPC207.txt","r",stdin);

    int cases;
    //scanf("%d",&cases);
    cin>>cases;
    getchar();

    for(t=1;t<=cases;++t)
    {
        gets(buff);
        //cout<<buff<<endl;
        n=0;

        stringstream ss(buff);
        while(ss>>arr[n])
        {
            //cout<<arr[n]<<endl;
            ++n;
        }

        solve();
    }



    return 0;
}

