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

//#define gc getchar_unlocked
#define gc getchar

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}

#define MAXN 3333
PII arr[MAXN];
int rankk[MAXN];
int n;
int uip;
int lip;
int boss;int school;

void MAIN()
{
    int cases;
    cases=readPosInt();
    int i;
    int pos;
    int sz;
    int ti;
    int ans;

    while(cases--)
    {
        school=readPosInt();
        boss=readPosInt();
        n=readPosInt();
        for(i=0;i<n;++i)
        {
            arr[i].first=readPosInt();
            arr[i].second=i;
        }
        sort(arr,arr+n);
        for(i=0;i<n;++i)
        {
            rankk[i]=arr[i].second;
        }
        uip=n%school;
        lip=n-uip;
        sz=n/school;
        pos=0;

        if(boss>=uip)
        {
            pos=uip*(sz+1);
            pos+=(boss-uip)*sz;
        }
        else
        {
            pos=boss*sz;
            ++sz;
        }

        ans=MAXN;

        for(i=0;i<sz;++i)
        {
            if(rankk[pos]<ans)
            {
                ans=rankk[pos];
                ti=arr[pos].first;
            }

            ++pos;
        }


        printf("%d\n",ti);

    }
}

int main()
{
	freopen("Text/BOOK.txt","r",stdin);

    MAIN();

	return 0;
}

