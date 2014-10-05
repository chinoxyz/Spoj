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
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MAXN 100003

Vi64 pos;

struct data
{
    int first,second;

    bool operator<(const data &b) const
    {
        return  first<b.first;
    }

};

data arr[MAXN];

Vi64::iterator it1;
int len;
int n;
i64 ans;
i64 tmp,t1,t2,t3;


//#define gc getchar_unlocked
#define gc getchar

inline i64 readPosLLD()
{
    i64 ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}

int main() {

	freopen("Text/NITT8.txt","r",stdin);


	int cases,i,nm1;
	int mx,mn;

	scanf("%d",&cases);

	while(cases--)
    {
        ans=0;
        pos.clear();

        scanf("%d",&n);

        pos.resize(n);

        for(i=0;i<n;++i)
        {
            t3=readPosLLD();
            arr[i].first=t3;
            arr[i].second=i;
            pos[i]=i;
        }

        sort(arr,arr+n);
        nm1=n-1;

        mn=arr[n-1].second;
        mx=arr[n-1].second;

        for(i=n-2;i>=0;--i)
        {
            t1=0;
            t2=0;
            tmp=arr[i].first;

            mn=min(mn,arr[i].second);
            mx=max(mx,arr[i].second);

            t1=tmp*(arr[i].second-mn);
            t2=tmp*(mx-arr[i].second);

            ans=max(ans,max(t1,t2));

        }

        printf("%lld\n",ans);
    }




    return 0;
}
