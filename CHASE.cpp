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


#define MAXN 2222

int x[MAXN];
int y[MAXN];
double slopee[MAXN];
int infs,ninfs;
int ans=0;


int main()
{
    freopen("Text/CHASE.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    int ti=0;
    int n;

    while(cases--)
    {
        ans=0;
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d %d",x+i,y+i);
        }

        for(int i=0;i<n;++i)
        {
            infs=ninfs=0;
            ti=0;
            for(int j=i+1;j<n;++j)
            {
                if(x[i]==x[j])
                {
                    ++infs;
                }
                else
                {
                    slopee[ninfs++]=(double)(y[j]-y[i])/(double)(x[j]-x[i]);
                }
            }

            ans=max(ans,infs);

            sort(slopee,slopee+ninfs);

            for(int j=0;j<ninfs;++j)
            {
                if(!j || slopee[j-1]!=slopee[j])
                {
                    ti=1;
                }
                else
                {
                    ++ti;
                }

                ans=max(ans,ti);
            }
        }

        printf("%d\n",ans);
    }



    return 0;
}








