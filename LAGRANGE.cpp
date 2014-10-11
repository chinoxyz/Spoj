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


#define MAXN 32769

int ans[MAXN],sqr[200];

void pree()
{
    for(int i=0;i<=sqrt(MAXN)+1;++i)
    {
        sqr[i]=i*i;
    }

    int s1,s2;

    for(int i=0;4*sqr[i]<MAXN;++i)
    {
        for(int j=i;sqr[i]+3*sqr[j]<MAXN;++j)
        {
            s1=sqr[i]+sqr[j];
            for(int k=j;s1+2*sqr[k]<MAXN;++k)
            {
                s2=s1+sqr[k];
                for(int l=k;s2+sqr[l]<MAXN;++l)
                {
                    ++ans[s2+sqr[l]];
                }
            }
        }
    }
}



int main()
{
    freopen("Text/LAGRANGE.txt","r",stdin);

    MSET(ans,0);

    char buff[9999];


    pree();
    int n;

    while(true)
    {
        //scanf("%d",&n);
        gets(buff);

        stringstream ss(buff);
        ss>>n;

        if(n==0)
        {
            break;
        }

        printf("%d\n",ans[n]);

    }

    return 0;
}
