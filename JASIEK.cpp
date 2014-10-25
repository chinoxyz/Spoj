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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXN 20005
int moves[MAXN],np,ns;
struct pointt
{
    int x,y;
};

pointt arr[MAXN];


void solve()
{
    int x=1,y=1,prevv=moves[ns-1];
    int i;

    for(i=0,np=0;i<ns;++i)
    {
        switch(moves[i]+4*prevv)
        {
        case 0:
            y+=2;
            break;

        case 1:
            arr[np].x=x+1;
            arr[np].y=y+1;
            ++np;
            x-=2;
            break;

        case 2:
            arr[np].x=x+1;
            arr[np].y=y+1;
            ++np;
            arr[np].x=x-1;
            arr[np].y=y+1;
            ++np;
            y-=2;
            break;

        case 3:
            arr[np].x=x+1;
            arr[np].y=y-1;
            ++np;
            x+=2;
            break;

        case 4:
            arr[np].x=x+1;
            arr[np].y=y+1;
            ++np;
            y+=2;
            break;

        case 5:
            x-=2;
            break;

        case 6:
            arr[np].x=x-1;
            arr[np].y=y+1;
            ++np;
            y-=2;
            break;

        case 7:
            arr[np].x=x-1;
            arr[np].y=y+1;
            ++np;
            arr[np].x=x-1;
            arr[np].y=y-1;
            ++np;
            x+=2;
            break;

        case 8:
            arr[np].x=x-1;
            arr[np].y=y-1;
            ++np;
            arr[np].x=x+1;
            arr[np].y=y-1;
            ++np;
            y+=2;
            break;

        case 9:
            arr[np].x=x-1;
            arr[np].y=y+1;
            ++np;
            x-=2;
            break;

        case 10:
            y-=2;
            break;

        case 11:
            arr[np].x=x-1;
            arr[np].y=y-1;
            ++np;
            x+=2;
            break;

        case 12:
            arr[np].x=x+1;
            arr[np].y=y-1;
            ++np;
            y+=2;
            break;

        case 13:
            arr[np].x=x+1;
            arr[np].y=y-1;
            ++np;
            arr[np].x=x+1;
            arr[np].y=y+1;
            ++np;
            x-=2;
            break;

        case 14:
            arr[np].x=x-1;
            arr[np].y=y-1;
            ++np;
            y-=2;
            break;

        case 15:
            x+=2;
            break;
        }

        prevv=moves[i];
    }
}

int areaa()
{
    if(!ns)
    {
        return 1;
    }
    int ret=0;
    arr[np]=arr[0];

    for(int i=0;i<np;++i)
    {
        ret+=arr[i].x*arr[i+1].y-arr[i+1].x*arr[i].y;
    }

    ret=abs(ret);

    return ret/8;
}


int main()
{
    freopen("Text/JASIEK.txt","r",stdin);

    char buff[6];

    while(scanf("%s",buff)==1)
    {
        ns=0;

        while(scanf("%s",buff)==1 && buff[0]!='K')
        {
            switch(buff[0])
            {
            case 'N':
                moves[ns]=0;
                break;

            case 'W':
                moves[ns]=1;
                break;

            case 'S':
                moves[ns]=2;
                break;

            case 'E':
                moves[ns]=3;
                break;
            }

            ++ns;
        }

        solve();

        printf("%d\n",areaa());
    }

    return 0;
}
