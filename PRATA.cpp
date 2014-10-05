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




#define MAXX 4004001
#define MAXP 1001
#define MAXR 9

int arr[MAXR][MAXX];
int num_prata,num_cook;

int ct[MAXR];

inline bool checkk(int x)
{
    int ret=0;
    int i;

    for(i=1;i<MAXR;++i)
    {
        ret+=ct[i]*arr[i][x];
    }


    return (ret>=num_prata);
}


inline int solve()
{
    int l=0,r=MAXX;
    int midd;

    while(l<r)
    {
        midd=(l+r)>>1;
        if(checkk(midd))
        {
            r=midd;
        }
        else
        {
            l=midd+1;
        }
    }

    return l;
}


void pree()
{
    int nxt;
    int summ;
    int rec,i,j;

    for(i=1;i<MAXR;++i)
    {
        summ=0;
        nxt=i;
        rec=1;
        for(j=1;j<MAXX;++j)
        {
            if(j!=nxt)
            {
                arr[i][j]=summ;
            }
            else
            {
                ++rec;
                nxt+=rec*i;
                arr[i][j]=++summ;
            }
        }
    }
}

int main() {

	freopen("Text/PRATA.txt","r",stdin);

	int cases,ti,i;

	//scanf("%d",&cases);
	cases=readPosInt();

	pree();

	while(cases--)
    {
        MSET(ct,0);

        //scanf("%d",&num_prata);
        //scanf("%d",&num_cook);

        num_prata=readPosInt();
        num_cook=readPosInt();

        for(i=0;i<num_cook;++i)
        {
            scanf("%d",&ti);
            ++ct[ti];
        }

        printf("%d\n",solve());
    }



    return 0;
}
