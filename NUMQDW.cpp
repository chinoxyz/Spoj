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
#define Vi64 veszor<i64>
#define Vu64 veszor<u64>


#define MAXN 64
#define MODD 4242

int mx;

struct Matrix
{
    int arr[MAXN][MAXN];
};


void mull(Matrix &a,Matrix &b)
{
    int tmp[MAXN][MAXN];

    int i,j,k;

    for(i=0;i<=mx;++i)
    {
        for(j=0;j<=mx;++j)
        {
            tmp[i][j]=0;
            for(k=0;k<=mx;++k)
            {
                tmp[i][j]+=a.arr[i][k]*b.arr[k][j];
                tmp[i][j]%=MODD;
            }
        }
    }

    for(i=0;i<=mx;++i)
    {
        for(j=0;j<=mx;++j)
        {
            a.arr[i][j]=tmp[i][j];
        }
    }
}

void poww(Matrix &a,int p)
{
    Matrix tmp;
    int i,j;

    memcpy(&tmp,&a,sizeof(tmp));
    memset(&a,0,sizeof(a));

    for(i=0;i<=mx;++i)
    {
        a.arr[i][i]=1;
    }

    while(p>0)
    {
        if(p&1)
        {
            mull(a,tmp);
        }

        mull(tmp,tmp);
        p>>=1;
    }
}


void MAIN()
{
    int i,j,n,c,nnxt[7];
    int cases;
    Matrix m;
    char s[9999];
    set<char> sett;
    set<char>::iterator it;
    int lenn;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %s",&n,&c,s);
        lenn=strlen(s);

        MSET(nnxt,0);
        sett.clear();

        for(i=0;i<lenn;++i)
        {
            for(it=sett.begin();it!=sett.end();++it)
            {
                nnxt[*it-'A']|=1<<(s[i]-'A');
            }
            sett.insert(s[i]);
        }

        memset(&m,0,sizeof(m));
        mx=(1<<c)-1;

        for(i=0;i<=mx;++i)
        {
            for(j=0;j<c;++j)
            {
                if(i&(1<<j))
                {
                    ++m.arr[i][i&(~nnxt[j])];
                }
            }
        }

        poww(m,n);

        int ans=0;

        for(i=0;i<=mx;++i)
        {
            ans+=m.arr[mx][i];
            ans%=MODD;
        }

        printf("%d\n",ans);


    }
}

int main()
{
	freopen("Text/NUMQDW.txt","r",stdin);

    MAIN();

	return 0;
}
