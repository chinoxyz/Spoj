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

#define MAXN 100002
#define MAXL 7

bitset<MAXN> primes;
int ct[MAXN];
int arr[10];
int lenn;
int tarr[10],tlenn;


bool checkk(int numm,int lenn)
{
    tlenn=0;
    int tn=numm;

    while(tn)
    {
        tarr[tlenn++]=tn%10;
        tn/=10;
    }

    reverse(tarr,tarr+tlenn);


    int i,j;

    for(i=2;i<(1<<lenn);++i)
    {
        tn=0;

        for(j=0;j<lenn;++j)
        {
            if(i&(1<<j))
            {
                tn*=10;
                tn+=tarr[j];
            }
        }

        if(!primes.test(tn))
        {
            return 0;
        }
    }

    return 1;
}


void pree()
{
    i64 i,j;

    for(i=3;i<MAXN;i+=2)
    {
        if(!primes.test(i))
        {
            for(j=i*i;j<MAXN;j+=i)
            {
                primes.set(j);
            }
        }
    }

    for(i=4;i<MAXN;i+=2)
    {
        primes.set(i);
    }

    primes.set(0);
    primes.set(1);
    queue<PII > q;

    arr[lenn++]=0;
    ++ct[0];
    for(i=1;i<10;++i)
    {
        if(primes.test(i))
        {
            arr[lenn++]=i;
            //++ct[i];
            q.push(MP(i,1));
            //printf("DD\t%d\n",i);
        }
    }

    int ti;
    int tl;
    int numm;

    while(!q.empty())
    {
        ti=q.front().first;
        tl=q.front().second;
        q.pop();



        if(ti>=MAXN)
        {
            continue;
        }

        ++ct[ti];
        for(i=0;i<lenn;++i)
        {
            numm=ti*10+arr[i];
            //printf("DD\t%d,",numm);
            if(numm>=MAXN)
            {
                continue;
            }
            if(checkk(numm,tl+1))
            {
                q.push(MP(numm,tl+1));
            }
        }
    }

    for(i=1;i<MAXN;++i)
    {
        ct[i]+=ct[i-1];
    }

}

void MAIN()
{
    int cases;
    pree();
    int a,b;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&a,&b);
        if(a>b)
        {
            swap(a,b);
        }
        --a;
        printf("%d\n",ct[b]-ct[a]);
    }
}

int main()
{
	freopen("Text/MAIN111.txt","r",stdin);

    MAIN();

	return 0;
}
