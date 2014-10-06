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

#define MAXN 120
#define INF 99999999
bool data[MAXN][5][5];
int arr[MAXN][5];
int a[MAXN][5];
int mp[MAXN];

int n;


int calc(int x,int y)
{
    int ret=0;

    for(int i=0;i<5;++i)
    {
        for(int j=i;j<5;++j)
        {
            if(data[x][i][j]!=data[y][i][j])
            {
                ++ret;
            }
        }
    }

    return ret;
}


void pre_comp()
{
    int a[5]={0,1,2,3,4};
    int ct=-1;

    do
    {
        ++ct;
        for(int i=0;i<5;++i)
        {
            arr[ct][i]=a[i];
        }
/*
        for(int i=0;i<5;++i)
        {
            printf("%c",arr[ct][i]+'A');
        }
        printf("\n");
*/
        for(int i=0;i<5;++i)
        {
            for(int j=i;j<5;++j)
            {
                data[ct][a[i]][a[j]]=1;
            }
        }
    }
    while(next_permutation(a,a+5));
}

void solve()
{
    int ans=-1;
    int mn=INF;
    int i,j,k;
    int ct=0;

    for(i=0;i<n;++i)
    {
        for(j=0;j<MAXN;++j)
        {
            for(k=0;k<5;++k)
            {
                if(a[i][k]!=arr[j][k])
                {
                    break;
                }
            }

            if(k==5)
            {
                mp[i]=j;
            }
        }
    }

    for(i=0;i<MAXN;++i)
    {
        ct=0;

        for(j=0;j<n;++j)
        {
            ct+=calc(i,mp[j]);
        }

        if(ct<mn)
        {
            mn=ct;
            ans=i;
        }
    }


    for(int i=0;i<5;++i)
    {
        printf("%c",arr[ans][i]+'A');
    }
    printf(" is the median ranking with value %d.\n",mn);
}

char buff[10];


int main()
{
    freopen("Text/TRANK.txt","r",stdin);

    pre_comp();

    while(true)
    {
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%s",buff);
            for(int j=0;j<5;++j)
            {
                a[i][j]=buff[j]-'A';
            }
        }

        solve();
    }


    return 0;
}
