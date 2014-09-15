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


#define MAXN 10003


int storage[MAXN];
bool is_possible;


bool reduce_this_to_zero_using_prev(int pos)
{
    int prevv=pos-1;
    storage[prevv]-=storage[pos];
    storage[pos]=0;

    return (storage[prevv]>=0);
}


int main()
{
    freopen("Text/NITK06.txt","r",stdin);

    int cases=0;
    int i,n;

    scanf("%d",&cases);

    while(cases--)
    {
        is_possible=true;

        scanf("%d",&n);

        REP(i,n)
        {
            scanf("%d",storage+i);
        }

        for(i=n-1;i>0;--i)
        {

            if(!reduce_this_to_zero_using_prev(i))
            {
                is_possible=false;
                break;
            }

        }

        if(storage[0]!=0)
        {
            is_possible=false;
        }

        if(is_possible)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }


    return 0;
}


