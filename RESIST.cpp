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

#define MAXN 111
const double EPS = 1e-9;
const double INF = 1e19;

double resistancee[MAXN][MAXN],equations[MAXN][MAXN],currentt[MAXN];


void gauss_elimination(int n)
{
    int i,j,k;
    double ti;

    for(i=0;i<n;++i)
    {
        for(k=i,j=i+1;j<n;++j)
        {
            if(fabs(equations[j][i])>fabs(equations[k][i]))
            {
                k=j;
            }
        }

        if(i!=k)
        {
            for(j=i;j<n;++j)
            {
                swap(equations[i][j],equations[k][j]);
            }

            swap(currentt[i],currentt[k]);
        }

        for(k=i,ti=equations[i][i];k<n;++k)
        {
            equations[i][k]/=ti;
        }
        currentt[i]/=ti;

        for(j=i+1;j<n;++j)
        {
            if(fabs(equations[j][i])<EPS)
            {
                continue;
            }

            for(k=i,ti=equations[j][i];k<n;++k)
            {
                equations[j][k]-=equations[i][k]*ti;
            }

            currentt[j]-=currentt[i]*ti;
        }
    }

    for(i=n-1;i>=0;--i)
    {
        if(fabs(equations[i][i])<EPS)
        {
            continue;
        }

        for(j=i+1;j<n;++j)
        {
            currentt[i]-=currentt[j]*equations[i][j];
        }

        //printf("%f\n",currentt[i]);
        //cout<<currentt[i]<<endl;

    }
}

int main()
{
    freopen("Text/RESIST.txt","r",stdin);

    int n,m,i,j,x,y,z;

    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
            {
                resistancee[i][j]=INF;
                equations[i][j]=0.0;
            }

            currentt[i]=0.0;
        }

        for(i=0;i<m;++i)
        {
            scanf("%d %d %d",&x,&y,&z);
            //printf("%d\t%d\t%d\n",x,y,z);
            --x;
            --y;
            resistancee[x][y]=1.0/(1.0/resistancee[x][y]+1.0/z);
            resistancee[y][x]=1.0/(1.0/resistancee[y][x]+1.0/z);
            //cout<<resistancee[x][y]<<endl;
        }

        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
            {
                equations[i][j]-=1.0/resistancee[i][j];
                equations[i][i]+=1.0/resistancee[j][i];
            }
        }



        currentt[0]=1.0;

        gauss_elimination(n-1);

        printf("%.2f\n",fabs(currentt[0])+EPS);
        //cout<<fabs(currentt[0])+EPS<<endl;
    }



    return 0;
}

