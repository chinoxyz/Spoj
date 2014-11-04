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

const int MAXN=1001;
const int MAXNS=MAXN*MAXN;

int arr[MAXN][MAXN];
int n;
int tarrs[MAXN/2][MAXN<<2];
int tarrd[MAXN/2][MAXN<<2];
bool poss;
int destt[MAXN][MAXN];

void checkk(int pos,int ct)
{



    int st=-1;
    for(int i=0;i<ct;++i)
    {
        if(tarrs[pos][i]==tarrd[pos][0])
        {
            st=i;
            break;
        }
    }

    if(st==-1)
    {
        poss=false;
        return;
    }

    for(int i=0;i<ct;++i)
    {
        if(tarrd[pos][i]!=tarrs[pos][(st+i)%ct])
        {
            poss=false;
            return;
        }
    }
}

void solve()
{
    if(n==1)
    {
        if(arr[0][0]!=1)
        {
            poss=false;
        }

        return;
    }

    int nb2=n/2;
    int mx=0;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            destt[i][j]=++mx;
        }
    }

    if(n&1)
    {
        if(arr[nb2][nb2]!=destt[nb2][nb2])
        {
            poss=false;
            return;
        }
    }

    for(int i=0;i<nb2;++i)
    {
        int ct=0;
        int st=0;
        int l=n-i*2;

        for(int j=i;j<i+l;++j)
        {
            tarrs[i][ct]=arr[i][j];
            tarrd[i][ct++]=destt[i][j];
        }

        for(int j=i+1;j<i+l;++j)
        {
            tarrs[i][ct]=arr[j][i+l-1];
            tarrd[i][ct++]=destt[j][i+l-1];
        }

        for(int j=i+l-2;j>=i;--j)
        {
            tarrs[i][ct]=arr[i+l-1][j];
            tarrd[i][ct++]=destt[i+l-1][j];
        }

        for(int j=i+l-2;j>i;--j)
        {
            tarrs[i][ct]=arr[j][i];
            tarrd[i][ct++]=destt[j][i];
        }

        checkk(i,ct);
        if(!poss)
        {
            return;
        }
    }


}


int main()
{
    freopen("Text/ANARC07C.txt","r",stdin);

    int cases=0;

    while(++cases)
    {
        scanf("%d",&n);

        if(n==0)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        poss=true;

        solve();

        if(poss)
        {
            printf("%d. YES\n",cases);
        }
        else
        {
            printf("%d. NO\n",cases);
        }
    }



    return 0;
}

