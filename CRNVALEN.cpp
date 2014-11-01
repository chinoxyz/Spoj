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

#define INF 999999999
#define MAXN 51
#define MAXMN ( MAXN*MAXN*4 + MAXN*7 )
#define MAXNN ( MAXN*7 )



int main()
{
    freopen("Text/CRNVALEN.txt","r",stdin);
    int cases,n;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        set<int> nums;
        set<int>::iterator it;
        int ans;

        int ti;

        for(int i=0;i<n;++i)
        {
            scanf("%d",&ti);
            nums.insert(ti);
        }

        it=nums.begin();

        if(nums.size()>2)
        {
            ans=-1;
        }
        else if(nums.size()==1)
        {
            {

                if(*it==0)
                {
                    ans=0;
                }
                else if(*it==n-1)
                {
                    ans=n;
                }
                else
                {
                    ans=-1;
                }
            }
        }
        else
        {
            int a=*it;
            ++it;
            int b=*it;

            int mx=max(a,b);
            int mn=min(a,b);

            if(mx-mn!=1)
            {
                ans=-1;
            }
            else if(mx>n-1)
            {
                ans=-1;
            }
            else if(mx<=0)
            {
                ans=-1;
            }
            else
            {
                ans=mx;
            }
        }

        printf("%d\n",ans);
    }



    return 0;
}
