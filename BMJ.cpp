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


#define MAXN 100001
int x[MAXN],y[MAXN];

void pre_process()
{
    x[1]=0;
    y[1]=0;

    x[2]=0;
    y[2]=1;

    int j=2;

    int a=0,b=1;
    int rd=1;

    while(j<MAXN)
    {

        for(int i=0;i<rd;++i)
        {
            ++j;
            if(j>=MAXN)
            {
                break;
            }

            --a;
            x[j]=a;
            y[j]=b;
        }

        if(j>=MAXN)
        {
            break;
        }

        for(int i=0;i<rd;++i)
        {
            ++j;
            if(j>=MAXN)
            {
                break;
            }

            --b;
            x[j]=a;
            y[j]=b;
        }

        if(j>=MAXN)
        {
            break;
        }

        for(int i=0;i<rd;++i)
        {
            ++j;
            if(j>=MAXN)
            {
                break;
            }

            ++a;
            --b;
            x[j]=a;
            y[j]=b;
        }

        if(j>=MAXN)
        {
            break;
        }



        for(int i=0;i<rd;++i)
        {
            ++j;
            if(j>=MAXN)
            {
                break;
            }

            ++a;
            x[j]=a;
            y[j]=b;
        }

        if(j>=MAXN)
        {
            break;
        }

        for(int i=0;i<=rd;++i)
        {
            ++j;
            if(j>=MAXN)
            {
                break;
            }

            ++b;
            x[j]=a;
            y[j]=b;
        }

        if(j>=MAXN)
        {
            break;
        }

        for(int i=0;i<rd;++i)
        {
            ++j;
            if(j>=MAXN)
            {
                break;
            }

            --a;
            ++b;
            x[j]=a;
            y[j]=b;
        }

        if(j>=MAXN)
        {
            break;
        }

        ++rd;

    }


}

int main()
{
    freopen("Text/BMJ.txt","r",stdin);

    pre_process();
    int ti;

    while(scanf("%d",&ti)!=EOF)
    {
        printf("%d %d\n",x[ti],y[ti]);
    }

    return 0;
}
