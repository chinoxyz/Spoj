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
#define u64 unsigned i64

#define MAX 101
#define MAXN 100003

bool src[MAX*MAX],dest[MAX*MAX];
int n;
int arr[MAXN];


void solve()
{
    MSET(src,0);
    MSET(dest,0);


    int ti;
    bool poss=false;

    for(int i=0;i<n;++i)
    {
        src[0]=true;
        for(int j=0;j<MAX*MAX;++j)
        {
            if(src[j])
            {
                ti=j+arr[i];
                if(ti>=MAX*MAX)
                {
                    break;
                }

                if(dest[ti])
                {
                    poss=true;
                    break;
                }

                dest[ti]=true;
            }
        }

        if(poss)
        {
            break;
        }

        memcpy(src,dest,sizeof(src));
        //MSET(dest,0);
    }

    if(poss)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

int main(){

    freopen("Text/TUG.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
        }

        if(n>=MAX)
        {
            printf("YES\n");
        }
        else
        {
            solve();
        }
    }

    return 0;
}




