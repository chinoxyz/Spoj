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






#define MOD 1000000007


i64 orig[2][2]={    {1,1},
                    {1,0}
                };

i64 res[2][2];

i64 unit[2][2]={    {1,0},
                    {0,1}
                };



void multt(i64 a[2][2], i64 b[2][2]) {
	i64 temp[2][2] = {0};

	int i, j, k;

	for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            for(k = 0; k < 2; k++)
            {
				temp[i][j] += a[i][k] * b[k][j];
				temp[i][j] %= MOD;
			}
        }

    }


	memcpy(a, temp,sizeof(temp));
}





void calc(i64 n)
{
    if(n==0)
    {
        memcpy(res,unit,sizeof(unit));
        return;
    }

    if(n&1)
    {
        calc(n-1);
        multt(res,orig);
        return;
    }

    calc(n>>1);
    multt(res,res);
}

int main()
{

    freopen("Text/FLIB.txt","r",stdin);

    int cases;
    i64 n,ret;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld",&n);
        n<<=1;

        calc(n);
        //printf("%lld\n",n);

        ret=(res[0][0]*res[0][1])%MOD;

        printf("%lld\n",ret);
    }

    return 0;
}
