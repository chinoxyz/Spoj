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

i64 mul_res[4][4];
i64 unit_mat[4][4];
i64 leftt_mat[4][4];
i64 rightt_mat[4][4];
i64 many[4][4];
i64 ret[4][4];
i64 n,m;


void mult_mat(i64 a[4][4],i64 b[4][4])
{
    MSET(mul_res,0);

    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            for(int k=0;k<4;++k)
            {
                mul_res[i][j]+=((a[i][k]*b[k][j])%m);
                mul_res[i][j]%=m;
            }
        }
    }
}


i64 solve()
{
    memcpy(ret,unit_mat,sizeof(unit_mat));
    memcpy(many,leftt_mat,sizeof(leftt_mat));

    while(n>0)
    {
        if(n&1)
        {
            mult_mat(ret,many);
            memcpy(ret,mul_res,sizeof(ret));
        }
        n>>=1;

        mult_mat(many,many);
        memcpy(many,mul_res,sizeof(many));
    }

    mult_mat(ret,rightt_mat);

    return mul_res[0][0];
}


int main()
{
    freopen("Text/FIBTWIST.txt","r",stdin);

    int cases;
    scanf("%d",&cases);

    unit_mat[0][0]=1;
    unit_mat[0][1]=0;
    unit_mat[0][2]=0;
    unit_mat[0][3]=0;

    unit_mat[1][0]=0;
    unit_mat[1][1]=1;
    unit_mat[1][2]=0;
    unit_mat[1][3]=0;

    unit_mat[2][0]=0;
    unit_mat[2][1]=0;
    unit_mat[2][2]=1;
    unit_mat[2][3]=0;

    unit_mat[3][0]=0;
    unit_mat[3][1]=0;
    unit_mat[3][2]=0;
    unit_mat[3][3]=1;









    leftt_mat[0][0]=1;
    leftt_mat[0][1]=1;
    leftt_mat[0][2]=1;
    leftt_mat[0][3]=0;

    leftt_mat[1][0]=1;
    leftt_mat[1][1]=0;
    leftt_mat[1][2]=0;
    leftt_mat[1][3]=0;

    leftt_mat[2][0]=0;
    leftt_mat[2][1]=0;
    leftt_mat[2][2]=1;
    leftt_mat[2][3]=1;

    leftt_mat[3][0]=0;
    leftt_mat[3][1]=0;
    leftt_mat[3][2]=0;
    leftt_mat[3][3]=1;








    rightt_mat[0][0]=1;
    rightt_mat[0][1]=0;
    rightt_mat[0][2]=0;
    rightt_mat[0][3]=0;

    rightt_mat[1][0]=0;
    rightt_mat[1][1]=0;
    rightt_mat[1][2]=0;
    rightt_mat[1][3]=0;

    rightt_mat[2][0]=1;
    rightt_mat[2][1]=0;
    rightt_mat[2][2]=0;
    rightt_mat[2][3]=0;

    rightt_mat[3][0]=1;
    rightt_mat[3][1]=0;
    rightt_mat[3][2]=0;
    rightt_mat[3][3]=0;

    while(cases--)
    {
        scanf("%lld %lld",&n,&m);
        if(n<=1)
        {
            printf("%d\n",n);
        }
        else
        {
            --n;
            printf("%lld\n",solve());

        }
    }



    return 0;
}


