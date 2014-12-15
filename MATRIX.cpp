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


#define MAXN 205
#define INF 99999999

int arr[MAXN][MAXN];
int summ[MAXN][MAXN];



int main()
{
    freopen("Text/MATRIX.txt","r",stdin);

    int cases;

    int n,m;
    int mx,mct;

    scanf("%d",&cases);
    int i,j,k,l;
    int ti;
    int r,y,crect,coll,edges;
    int trii,repp,w;

    while(cases--)
    {
        mx=-INF;
        mct=0;

        scanf("%d %d",&m,&n);

        for(i=0;i<m;++i)
        {
            for(j=0;j<n;++j)
            {
                scanf("%d",&arr[i][j]);
                if(!arr[i][j])
                {
                    arr[i][j]=-1;
                }
            }
        }

        for(i=0;i<n;++i)
        {
            summ[i][0]=0;
            for(j=0;j<m;++j)
            {
                ti=arr[j][i];
                summ[i][j]=j==0?ti:summ[i][j-1]+ti;
            }
        }


        for(i=0;i<m;++i)
        {
            for(j=i;j<m;++j)
            {
                trii=0;
                repp=0;

                for(k=0;k<n;++k)
                {
                    r=0;
					y=0;
					w = repp;
                    coll=summ[k][j]-(i==0?0:summ[k][i-1]);
                    edges=arr[j][k]+arr[i][k];

                    if(i==j)
                    {
                        edges=arr[j][k];
                    }

                    crect = trii + coll;

                    if((trii + edges) == coll && k != 0)
					{
						++w;
					}

                    if((trii + edges) < coll || k == 0)
                    {
                        trii = coll;
                        w = 0;
                    }
                    else
                    {
                        trii += edges;
                    }

                    if(crect == coll && k != 0)
                    {
                         r=1;
                    }

                    if(crect >= coll && k != 0)
                    {
                        y = 1;
                    }

                    if(crect < coll)
                    {
                        crect = coll;
                    }

                    if(crect > mx)
                    {
                        mx = crect;
                        mct = 1 + r;
                        if(y)
                        {
                            mct += repp;
                        }
                    }
                    else if(crect == mx)
                    {
                        mct++;
                        mct += r;
                        if(y)
                        {
                            mct += repp;
                        }
                    }
                    repp = w;

                }
            }
        }

        printf("%d %d\n",mx,mct);

    }



    return 0;
}
