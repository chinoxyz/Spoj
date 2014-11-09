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

#define MAXN 100005
bool poss;
int n;
char s[MAXN];
char t[MAXN];
int arr[MAXN];
int tlen;
int kmpp[MAXN];


void kmp_preprocess()
{
    int i=0;
    int j=-1;
    kmpp[i]=j;

    while(i<tlen)
    {
        while(j>=0 && t[i]!=t[j])
        {
            j=kmpp[j];
        }
        ++i;
        ++j;
        kmpp[i]=j;
    }

}

void kmp_search()
{
    int i=0;
    int j=0;

    while(i<n-1)
    {
        while(j>=0 && s[i]!=t[j])
        {
            j=kmpp[j];
        }
        ++i;
        ++j;
        if(j==tlen)
        {
            poss=true;
            return;
        }
    }
}

void solve()
{
    tlen=strlen(t);
    kmp_preprocess();
    kmp_search();
    if(poss)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}


int main()
{
    freopen("Text/TESSER.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        poss=false;
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        for(int i=1;i<n;++i)
        {
            if(arr[i]>arr[i-1])
            {
                s[i-1]='G';
            }
            else if(arr[i]==arr[i-1])
            {
                s[i-1]='E';
            }
            else
            {
                s[i-1]='L';
            }
        }
        scanf("%s",t);

        solve();
    }

    return 0;
}
