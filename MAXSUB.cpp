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
#define u64 unsigned i64


#define MAXN 50005

i64 arr[MAXN];
i64 zcount=0,mx;
i64 mx_count=0,pos_sum=0;


const i64 MODD=1000000009LL;


i64 poww(i64 p)
{
    i64 ret=1;
    i64 st=2;

    while(p>0)
    {
        if(p&1)
        {
            ret*=st;
            ret%=MODD;
        }

        st*=st;
        st%=MODD;
        p>>=1;
    }

    return ret;
}

int main(){

    freopen("Text/MAXSUB.txt","r",stdin);

    int cases,n;

    scanf("%d",&cases);

    while(cases--)
    {
        pos_sum=0;
        mx_count=0;
        zcount=0;
        scanf("%d",&n);

        scanf("%lld",arr);
        mx=arr[0];
        mx_count=1;
        if(arr[0]>0)
        {
            pos_sum=arr[0];
        }
        else if(arr[0]==0)
        {
            ++zcount;
        }

        for(int i=1;i<n;++i)
        {
            scanf("%lld",arr+i);
            if(arr[i]>0)
            {
                pos_sum+=arr[i];
            }
            else if(arr[i]==0)
            {
                ++zcount;
            }

            if(mx<arr[i])
            {
                mx=arr[i];
                mx_count=1;
            }
            else if(mx==arr[i])
            {
                ++mx_count;
            }
        }

        if(mx<0)
        {
            printf("%lld %lld\n",mx,mx_count);
        }
        else if(mx==0)
        {
            printf("%lld %lld\n",0LL,poww(zcount)-1);
        }
        else
        {
            printf("%lld %lld\n",pos_sum,poww(zcount));
        }
    }


    return 0;
}




