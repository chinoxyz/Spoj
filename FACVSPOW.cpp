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

#define MAXX 1000001

int arr[MAXX];

int main()
{

    freopen("Text/FACVSPOW.txt","r",stdin);


    int cases,num;
    double rightt,leftt,td;

    arr[1]=2;
    rightt=log(2.0);


    for(int i=2,j=2;i<MAXX;++i)
    {
        td=log((double)i);

        for(++j;;++j)
        {
            leftt=j*td;
            rightt+=log((double)j);

            if(leftt<rightt)
            {
                arr[i]=j;
                break;
            }
        }
    }

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&num);
        printf("%d\n",arr[num]);
    }



    return 0;
}
