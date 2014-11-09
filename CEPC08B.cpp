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

#define MAXN 1000002
int arr[MAXN];

int main()
{
    freopen("Text/CEPC08B.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    int i,j,k;
    int n;
    int d;
    int ans;
    int ti;

    VPII vc;
    while(cases--)
    {
        vc.clear();
        scanf("%d %d",&k,&d);
        scanf("%d",arr);
        n=1;
        for(i=1;i<k;++i)
        {
            scanf("%d",arr+n);
            if(arr[n]!=arr[n-1])
            {
                ++n;
            }
        }

        if(n>1 && arr[0]>arr[1])
        {
            vc.PB(MP(arr[0],-1));
        }
        else if(n==1)
        {
            vc.PB(MP(arr[0],-1));
        }

        for(i=1;i<n-1;++i)
        {
            if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
            {
                vc.PB(MP(arr[i],1));
            }
            else if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                vc.PB(MP(arr[i],-1));
            }
        }

        if(n>=2 && arr[n-1]>arr[n-2])
        {
            vc.PB(MP(arr[n-1],-1));
        }

        sort(vc.begin(),vc.end());
        k=0;
        ans=1;
        i=0;

        for(j=0;j<d;++j)
        {
            scanf("%d",&ti);
            for(;i<vc.size() && vc[i].first<=ti;++i)
            {
                ans+=vc[i].second;
            }

            printf("%d ",ans);
        }
        printf("\n");
    }
    return 0;
}
