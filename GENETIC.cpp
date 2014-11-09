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


#define MAXN 5003
char arr[MAXN];
char ti[]={'N','O','P'};


inline bool validd(int pos)
{
    int i,j,midd;
    int lenn;
    for(i=pos-1;i>=0;i-=2)
    {
        midd=((i+pos)>>1);
        lenn=midd-i;

        for(j=0;j<=lenn;++j)
        {
            if(arr[i+j]!=arr[midd+1+j])
            {
                break;
            }
        }
        if(j>lenn)
        {
            return false;
        }
    }

    return true;
}


inline bool solve(int pos)
{
    //printf("DD\t%d\n",pos);
    if(pos>=MAXN)
    {
        return true;
    }

    for(int i=0;i<3;++i)
    {
        arr[pos]=ti[i];
        if(validd(pos))
        {
            if(solve(pos+1))
            {
                return true;
            }
        }
    }

    return false;
}


int main()
{
    freopen("Text/GENETIC.txt","r",stdin);
    solve(0);
    int n;
    char tc;


    while(true)
    {
        scanf("%d",&n);
        if(!n)
        {
            break;
        }

        tc=arr[n];
        arr[n]=0;
        printf("%s\n",arr);
        arr[n]=tc;
    }



    return 0;
}
