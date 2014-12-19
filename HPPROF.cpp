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

#define MAXN 101

bool arr[MAXN][MAXN];



void MAIN()
{
    int cases;
    int ans;

    scanf("%d",&cases);
    int x,y;
    int i,j,k;
    int n;


    for(int t=1;t<=cases;++t)
    {
        MSET(arr,0);
        ans=0;
        scanf("%d",&n);

        for(i=0;i<n;++i)
        {
            scanf("%d %d",&x,&y);
            arr[x][y]=1;
        }

        for(k=0;k<n;++k)
        {
            for(i=0;i<n;++i)
            {
                for(j=0;j<n;++j)
                {
                    if(!arr[i][j])
                    {
                        if(arr[i][k] && arr[k][j])
                        {
                            arr[i][j]=1;
                            ++ans;
                        }
                    }
                }
            }
        }

        printf("Case #%d: %d\n",t,ans);
    }


}

int main()
{
	freopen("Text/TRANCLS.txt","r",stdin);

    MAIN();

	return 0;
}
