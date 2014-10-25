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

#define MAXN 28

char arr[MAXN];
int ct[MAXN];
bool vis[MAXN];

int main()
{
    freopen("Text/LEONARDO.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    bool poss;
    int j;
    int summ;

    while(cases--)
    {
        MSET(vis,0);
        MSET(ct,0);
        scanf("%s",arr);

        for(int i=0;i<26;++i)
        {
            if(vis[i])
            {
                continue;
            }

            j=i;
            summ=0;

            do
            {
                vis[j]=1;
                j=arr[j]-'A';
                ++summ;
            }
            while(i!=j);

            ++ct[summ];
        }

        poss=true;

        for(int i=2;i<26;i+=2)
        {
            if(ct[i]&1)
            {
                poss=false;
                break;
            }
        }

        if(poss)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }


    return 0;
}
