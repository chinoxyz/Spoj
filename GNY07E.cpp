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


//#define gc getchar_unlocked
#define gc getchar

#define MAXN 33
char buff[3333];

int arr[MAXN];
int n;
VI vc;
int ans;


void flipp(int pos)
{
    ++ans;
    vc.PB(pos+1);
    int st=0;
    int ti;

    while(st<pos)
    {
        ti=arr[st];
        arr[st]=-arr[pos];
        arr[pos]=-ti;
        ++st;
        --pos;
    }

    if(st==pos)
    {
        arr[st]=-arr[st];
    }
}


void solve()
{
    vc.clear();
    ans=0;
    int ct=0;
    int i,j;

    while(true)
    {
        if(ct==n)
        {
            break;
        }

        for(i=n-ct-1;i>=0;--i)
        {
            if(abs(arr[i])==(n-ct))
            {
                break;
            }
        }

        if(i==(n-ct-1) && arr[i]>0)
        {
            ++ct;
            continue;
        }

        flipp(i);

        if(ct<n-1)
        {
            if(arr[0]>0)
            {
                flipp(0);
            }

            flipp(n-ct-1);
        }
        ++ct;
    }

}

int main()
{
    freopen("Text/GNY07E.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    int i;

    for(int t=1;t<=cases;++t)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        solve();
        i=0;
        if(ans)
        {
            printf("%d ",t);
            printf("%d ",ans);
            for(i=0;i<ans-1;++i)
            {
                printf("%d ",vc[i]);
            }
            printf("%d\n",vc[i]);
        }
        else
        {
            printf("%d\n",t);
        }

    }


    return 0;
}
