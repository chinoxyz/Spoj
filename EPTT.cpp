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

#define MAXN 1000004
int arr[MAXN];
int ans=0;


int main()
{
    freopen("Text/EPTT.txt","r",stdin);

    int i,j;
    int n;
    int st;

    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
        scanf("%d",arr+i);
    }

    sort(arr,arr+n);

    int ct=0;
    for(i=0;i<n;++i)
    {
        if(arr[i]>=0)
        {
            ++ans;
            st=arr[i]+30;
            arr[i]=-1;
            ct=1;
            for(j=i+1;j<n;++j)
            {
                if(arr[j]==-1)
                {
                    continue;
                }
                if(arr[j]>st)
                {
                    break;
                }
                if(arr[j]==st)
                {
                    st=arr[j]+30;
                    arr[j]=-1;
                    ++ct;
                    if(ct==4)
                    {
                        break;
                    }
                }
            }
        }
    }

    printf("%d\n",ans);


    return 0;
}
