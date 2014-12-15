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

#define MAXN 10000001
#define MAXM 20009


int arr[MAXM];
int n;
int lenn;
bool poss;
int ret;
//bool vis[MAXN];
bool *vis;

int main()
{
    freopen("Text/SAMER08K.txt","r",stdin);

    int st,alenn,j,x;
    int i;

    while(true)
    {
        ret=-1;
        scanf("%d",&n);

        if(!n)
        {
            break;
        }

        lenn=0;
        //MSET(vis,0);
        vis=new bool[MAXN];


        for(i=0;i<n;++i)
        {
            scanf("%d",arr+i);
            lenn+=arr[i];
            vis[lenn]=1;
            //printf("%d\n",lenn);
        }

        poss=0;

        for(i=n;i>=3;--i)
        {
            if(lenn%i)
            {
                continue;
            }

            st=0;
            alenn=lenn/i;
            poss=0;

            for(x=0;st<=alenn;++x)
            {

                poss=1;

                for(j=st;poss && j<lenn;j+=alenn)
                {
                    poss&=vis[j];
                }

                if(poss)
                {
                    ret=n-i;
                    break;
                }

                st+=arr[x];
            }

            if(poss)
            {
                break;
            }
        }

        free(vis);

        printf("%d\n",ret);
    }


    return 0;
}
