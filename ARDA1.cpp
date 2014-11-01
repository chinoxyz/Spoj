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

#define MAXN 2005

char arrm[MAXN][MAXN];
char arrn[MAXN][MAXN];
int n1,n2,m1,m2;

bool poss;



int main()
{
    freopen("Text/ARDA1.txt","r",stdin);

    scanf("%d %d",&n1,&n2);

    for(int i=0;i<n1;++i)
    {
        scanf("%s",&arrn[i]);
    }

    scanf("%d %d",&m1,&m2);

    for(int i=0;i<m1;++i)
    {
        scanf("%s",&arrm[i]);
    }

    VPII ans;

    int nx,ny,mx,my;


    for(int i=0;i<=m1-n1;++i)
    {
        for(int j=0;j<=m2-n2;++j)
        {
            if(arrm[i][j]==arrn[0][0])
            {
                //printf("%d %d\n",i,j);
                poss=true;
                mx=i;
                my=j;

                nx=0;
                ny=0;

                for(;nx<n1;++nx,++mx)
                {
                    for(ny=0,my=j;ny<n2;++ny,++my)
                    {
                        if(arrn[nx][ny]!=arrm[mx][my])
                        {
                            poss=false;
                            break;
                        }
                    }

                    if(!poss)
                    {
                        break;
                    }
                }

                if(poss)
                {
                    ans.PB(MP(i+1,j+1));
                }
            }
        }
    }

    if(ans.empty())
    {
        printf("NO MATCH FOUND...\n") ;
    }
    else
    {
        for(int i=0;i<ans.size();++i)
        {
            printf("(%d,%d)\n",ans[i].first,ans[i].second) ;
        }

    }




    return 0;
}
