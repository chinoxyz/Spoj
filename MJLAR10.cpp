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


int a[3];
int b[2];
map<int,int> mp;

int main()
{
    freopen("Text/MJLAR10.txt","r",stdin);
    int ans;

    while(true)
    {
        mp.clear();
        for(int i=0;i<3;++i)
        {
            scanf("%d",a+i);
            mp[a[i]]++;
        }

        for(int i=0;i<2;++i)
        {
            scanf("%d",b+i);
            mp[b[i]]++;
        }

        if(a[0]==0)
        {
            break;
        }

        sort(a,a+3);
        sort(b,b+2);

        if(b[0]>a[2] && b[1]>a[2])
        {
            ans=1;

            while(mp.count(ans))
            {
                ++ans;
            }
        }
        else if(b[0]>a[1] && b[1]>a[1] && b[0]<a[2] && b[1]<a[2])
        {
            ans=a[1]+1;

            while(mp.count(ans))
            {
                ++ans;
            }
        }
        else if(b[0]>a[0] && b[1]>a[0] && b[0]<a[1] && b[1]<a[1])
        {
            ans=-1;
        }
        else if(b[0]<a[0] && b[1]<a[0])
        {
            ans=-1;
        }
        else if(b[1]>a[2] && b[0]>a[1] && b[0]<a[2])
        {
            ans=a[1]+1;

            while(mp.count(ans))
            {
                ++ans;
            }
        }
        else if(b[1]>a[2] && b[0]>a[0] && b[0]<a[1])
        {
            ans=a[2]+1;

            while(mp.count(ans))
            {
                ++ans;
            }
        }
        else if(b[1]>a[2] && b[0]<a[0])
        {
            ans=a[2]+1;

            while(mp.count(ans))
            {
                ++ans;
            }
        }
        else if( b[1]>a[1] && b[1]<a[2]  &&  b[0]>a[0] && b[0]<a[1])
        {
            ans=-1;
        }
        else if( b[1]>a[1] && b[1]<a[2]  &&  b[0]<a[0])
        {
            ans=-1;
        }
        else if( b[1]>a[0] && b[1]<a[1]  &&  b[0]<a[0])
        {
            ans=-1;
        }


        if(ans>52)
        {
            ans=-1;
        }


        printf("%d\n",ans);

    }

    return 0;
}
