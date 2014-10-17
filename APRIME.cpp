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

#define MAXS 10001
#define MAXN 1001

bool vis[MAXN];
bitset<MAXS> primes;
int arr[MAXN];
bool poss;
int n,m,d,len;

void sieve()
{
    primes.set(0);
    primes.set(1);

    for(int i=2;i<=sqrt(MAXS);++i)
    {
        if(!primes.test(i))
        {
            for(int j=i*i;j<MAXS;j+=i)
            {
                primes.set(j);
            }
        }
    }
}


bool is_valid(int pos)
{
    int summ=arr[pos-1];

    for(int i=2;i<=d && pos>=i;++i)
    {
        summ+=arr[pos-i];
        if(!primes.test(summ))
        {
            return false;
        }
    }

    return true;

}


void solve(int pos)
{
    if(pos<2 || is_valid(pos))
    {
        if(pos==len)
        {
            poss=true;
            return;
        }
        else
        {
            for(int i=n;i<=m;++i)
            {
                if(!vis[i])
                {
                    arr[pos]=i;
                    vis[i]=true;

                    solve(pos+1);

                    if(poss)
                    {
                        return;
                    }

                    vis[i]=false;
                }
            }
        }
    }
}

int main()
{
    freopen("Text/APRIME.txt","r",stdin);
    sieve();

    while(true)
    {
        scanf("%d %d %d",&n,&m,&d);

        if(n+m+d==0)
        {
            break;
        }

        len=m-n+1;

        poss=false;
        MSET(vis,0);

        solve(0);

        if(!poss)
        {
            printf("No anti-prime sequence exists.\n");
        }
        else
        {
            for(int i=0;i<len;++i)
            {
                if(i>0)
                {
                    printf(",");
                }
                printf("%d",arr[i]);
            }
            printf("\n");
        }
    }



    return 0;
}
