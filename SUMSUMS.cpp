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


const i64 MOD=98765431;

struct Matrix
{
    i64 mat[2][2];

    Matrix()
    {
        MSET(mat,0);
    }

    i64 operator()(int i,int j) const
    {
        return mat[i][j];
    }

    i64 &operator()(int i,int j)
    {
        return mat[i][j];
    }
};


Matrix mul(Matrix ma,Matrix mb)
{
    Matrix mc;

    for (int i = 0; i < 2; i++)
    {
		for (int j = 0; j < 2; j++)
		{
			mc(i, j) = 0;
			for (int k = 0; k < 2; k++)
			{
                mc(i, j) = (mc(i, j) + ma(i, k) * mb(k, j)) % MOD;
			}
		}
	}

	return mc;
}


Matrix poww(Matrix ma,int n)
{
    Matrix ret;

    ret(0,0)=ret(1,1)=1;


    while(n!=0)
    {
        if(n&1)
        {
            ret=mul(ret,ma);
        }

        ma=mul(ma,ma);
        n>>=1;
    }


    return ret;
}




int main()
{

    freopen("Text/SUMSUMS.txt","r",stdin);

    int n,ct;

    scanf("%d %d",&n,&ct);

    VI data(n);
    i64 summ=0;

    for(int i=0;i<n;++i)
    {
        scanf("%d",&data[i]);
        summ=(summ+data[i])%MOD;
    }

    Matrix ma;
    ma(0,0)=(n-1)%MOD;
    ma(0,1)=summ;
    ma(1,0)=0;
    ma(1,1)=MOD-1;

    ma=poww(ma,ct);

    for(int i=0;i<n;++i)
    {
        i64 ans=(ma(0,1)+ma(1,1)*data[i])%MOD;
        printf("%lld\n",ans);
    }


    return 0;
}
