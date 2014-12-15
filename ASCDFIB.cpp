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


#define MODD 100000
#define MAXN 1100005

int fibb[MAXN];
int ct[MODD];

void pree()
{
    fibb[1]=0;
    fibb[2]=1;

    for(int i=3;i<MAXN;++i)
    {
        fibb[i]=(fibb[i-1]+fibb[i-2])%MODD;
    }
}

int main()
{
    freopen("Text/ASCDFIB.txt","r",stdin);

    int cases;
    int a,b;
    pree();

    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        printf("Case %d:" ,t);
        scanf("%d %d",&a,&b);

        MSET(ct,0);

        for(int i=0;i<=b;++i)
        {
            ++ct[fibb[a+i]];
        }

        int tot=min(100,b+1);

        for(int i=0;i<MODD;++i)
        {
            for(int j=0;j<ct[i];++j)
            {
                printf(" %d",i);
                --tot;

                if(!tot)
                {
                    break;
                }
            }

            if(!tot)
            {
                break;
            }
        }

        printf("\n");

    }


    return 0;
}
