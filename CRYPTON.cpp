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

#define MAXL 1000001
#define MAXK 105

int primes[MAXL];
int np;
bool fl[MAXL];
char numm[MAXK];
int lenn;
int l;
int ans;


void pree()
{
    np=1;
    primes[0]=2;
    i64 i,j;

    for(i=3;i<=1000;i+=2)
    {
        if(!fl[i])
        {
            for(j=i*i;j<MAXL;j+=i)
            {
                fl[j]=1;
            }
        }
    }

    for(i=3;i<MAXL;i+=2)
    {
        if(!fl[i])
        {
            primes[np++]=i;
        }
    }
}

void solve(int d)
{
    int ret=0;

    for(int i=0;i<lenn;++i)
    {
        ret*=10;
        ret+=numm[i]-'0';
        ret%=d;
    }

    if(ret==0)
    {
        ans=d;
    }
}



int main()
{
    freopen("Text/CRYPTON.txt","r",stdin);
    pree();
    int i;

    while(true)
    {
        ans=-1;
        cin>>numm>>l;
        if(strcmp(numm,"0")==0 && l==0)
        {
            break;
        }
        lenn=strlen(numm);

        for(i=0;i<np;++i)
        {
            if(primes[i]>=l)
            {
                break;
            }

            solve(primes[i]);
            if(ans!=-1)
            {
                break;
            }
        }

        if(ans==-1)
        {
            printf("GOOD\n");
        }
        else
        {
            printf("BAD %d\n",ans);
        }
    }

    return 0;
}
