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


#define MAXX 502
#define INF 999999999

int arr[MAXX][MAXX],req[MAXX][MAXX];
int num_rows,num_cols;

void solve()
{
    req[num_rows][num_cols]=1;

    for(int i=num_rows;i>=1;--i)
    {
        for(int j=num_cols;j>=1;--j)
        {
            //printf("DD\n");
            if(i==num_rows && j==num_cols)
            {
                continue;
            }

            if(i<num_rows)
            {
                int x=req[i+1][j]-arr[i][j];

                if(x<=0)
                {
                    x=1;
                }

                req[i][j]=min(req[i][j],x);
            }

            if(j<num_cols)
            {
                int x=req[i][j+1]-arr[i][j];

                if(x<=0)
                {
                    x=1;
                }

                req[i][j]=min(req[i][j],x);
            }
        }
    }

    printf("%d\n",req[1][1]);
}

int main()
{
    freopen("Text/AMR11A.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&num_rows,&num_cols);

        for(int i=1;i<=num_rows;++i)
        {
            for(int j=1;j<=num_cols;++j)
            {
                scanf("%d",&arr[i][j]);
                req[i][j]=INF;
            }
        }

        solve();
    }





    return 0;
}


