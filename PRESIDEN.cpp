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

#define MAXN 103

int arr[MAXN][MAXN],mp[MAXN][MAXN];
int ct[MAXN],mx1,mx2;


int main()
{
    freopen("Text/PRESIDEN.txt","r",stdin);

    int cases;
    int ans1,ans2,c,v;

    scanf("%d",&cases);

    while(cases--)
    {

        scanf("%d %d",&c,&v);

        for(int i=1;i<=v;++i)
        {
            for(int j=1;j<=c;++j)
            {
                scanf("%d",&arr[i][j]);
                mp[i][arr[i][j]]=j;
            }
        }

        MSET(ct,0);
        mx1=mx2=0;
        ans1=ans2=0;

        for(int i=1;i<=v;++i)
        {
            ++ct[arr[i][1]];
        }

        for(int i=1;i<=c;++i)
        {
            if(ct[i]>mx1)
            {
                mx2=mx1;
                mx1=ct[i];
                ans2=ans1;
                ans1=i;
            }
            else if(ct[i]>mx2)
            {
                mx2=ct[i];
                ans2=i;
            }
        }

        if(mx1>v/2)
        {
            printf("%d %d\n",ans1,1);
            continue;
        }

        MSET(ct,0);

        for(int i=1;i<=v;++i)
        {
            if(mp[i][ans1]<mp[i][ans2])
            {
                ++ct[ans1];
            }
            else
            {
                ++ct[ans2];
            }
        }

        if(ct[ans1]>ct[ans2])
        {
            printf("%d %d\n",ans1,2);
        }
        else
        {
            printf("%d %d\n",ans2,2);
        }

    }


    return 0;
}
