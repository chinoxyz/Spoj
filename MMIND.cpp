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
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
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


#define MAXM 111
#define MAXP 22
#define MAXC 111

int arr[MAXM][MAXP];
int black[MAXM],white[MAXM];
int summ[MAXM][MAXC];


int ans[MAXP];

int p,c,m;


bool solve(int pos)
{
    for(int i=0;i<m;++i)
    {
        if(black[i]<0 || white[i]<0 || black[i]>p-pos || white[i]>p-pos)
        {
            return 0;
        }
    }

    if(pos==p)
    {
        return 1;
    }
    for(int i=0;i<c;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(arr[j][pos]==i)
            {
                --black[j];
            }

            if(summ[j][i]-- > 0)
            {
                --white[j];
            }
        }

        ans[pos]=i+1;
        if(solve(pos+1))
        {
            return 1;
        }


        for(int j=0;j<m;++j)
        {
            if(arr[j][pos]==i)
            {
                ++black[j];
            }

            if(++summ[j][i]> 0)
            {
                ++white[j];
            }
        }
    }

    return 0;
}

void MAIN()
{
    int cases;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&p,&c,&m);
        MSET(summ,0);

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<p;++j)
            {
                scanf("%d",&arr[i][j]);
                --arr[i][j];
                ++summ[i][arr[i][j]];
            }

            scanf("%d %d",black+i,white+i);
            white[i]+=black[i];
        }



        if(!solve(0))
        {
            printf("You are cheating!\n");
        }
        else
        {
            for(int i=0;i<p-1;++i)
            {
                printf("%d ",ans[i]);
            }
            printf("%d\n",ans[p-1]);
        }
    }
}

int main()
{
	freopen("Text/MMIND.txt","r",stdin);

    MAIN();

	return 0;
}

