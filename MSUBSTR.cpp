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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MAXN 6666
char a[MAXN],b[MAXN];
int lenn;
int ans,ct;
int arr[MAXN];


void expandd()
{
    a[0]='^';
    for(int i=1;i<=lenn;++i)
    {
        a[2*i-1]='#';
        a[2*i]=b[i-1];
    }
    lenn=2*lenn+3;
    a[lenn-1]='$';
    a[lenn-2]='#';
    a[lenn]=0;
}

void solve()
{
    MSET(arr,0);
    expandd();
    //printf("%s\n",a);
    //printf("%d\n",lenn);

    int c=0,r=0;
    int im;

    for(int i=1;i<lenn-1;++i)
    {
        im=2*c-i;

        arr[i]=(r>i)?min(r-i,arr[im]):0;
        while(a[i+1+arr[i]]==a[i-1-arr[i]])
        {
            ++arr[i];
        }

        if(i+arr[i]>r)
        {
            c=i;
            r=i+arr[i];
        }
    }

    for(int i=1;i<lenn-1;++i)
    {
        //printf("%d %d\n",ans,ct);
        if(arr[i]>ans)
        {
            ans=arr[i];
            ct=1;
        }
        else if(arr[i]==ans)
        {
            ++ct;
        }
    }
}

void MAIN()
{
    int cases;
    scanf("%d",&cases);

    while(cases--)
    {
        ans=ct=0;
        scanf("%s",b);
        lenn=strlen(b);
        solve();

        printf("%d %d\n",ans,ct);
    }

}

int main()
{
	freopen("Text/MSUBSTR.txt","r",stdin);

    MAIN();

	return 0;
}

