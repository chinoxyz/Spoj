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

#define MAXN 100001
int arr[MAXN][10];
bitset<MAXN> bs;


void pree()
{
    arr[1][1]=1;
    int t;

    for(i64 i=2;i<MAXN;++i)
    {
        if(!bs.test(i))
        {
            t=i;

            while(t)
            {
                if(arr[i][t%10]==0)
                {
                    //printf("DD\n");
                    arr[i][t%10]=1;
                    //arr[i][t%10]+=arr[i-1][t%10];
                }
                t/=10;
            }
            for(i64 j=i*i;j<MAXN;j+=i*i)
            {
                bs.set(j);
            }
        }
    }

    for(int i=2;i<MAXN;++i)
    {
        for(int j=0;j<10;++j)
        {
            arr[i][j]+=arr[i-1][j];
        }
    }
}


int main()
{
    freopen("Text/NOSQ.txt","r",stdin);

    int cases,n;
    scanf("%d",&cases);

    pree();
    int a,b,d;


    while(cases--)
    {
        scanf("%d %d %d",&a,&b,&d);
        --a;
        printf("%d\n",arr[b][d]-arr[a][d]);
    }




    return 0;
}
