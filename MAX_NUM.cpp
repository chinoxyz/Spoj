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


#define MAXN 100007
char arr[MAXN];
VI ct[10];
int k;
int n;
int narr[MAXN];
int cpos[10];
int pos;
int dell,conss,leftt;

int main()
{
    freopen("Text/MAX_NUM.txt","r",stdin);

    int cases;

    cin>>cases;
    int i,j;
    int sz;

    while(cases--)
    {
        MSET(cpos,0);
        pos=-1;
        dell=0;
        conss=0;


        cin>>arr>>k;

        for(i=0;i<10;++i)
        {
            ct[i].clear();
        }

        n=0;


        for(i=0;arr[i];++i)
        {
            ct[arr[i]-'0'].PB(i);
            narr[i]=arr[i]-'0';
            ++n;
        }

        leftt=n-k;

        if(n<=k)
        {
            printf("\n");
            continue;
        }

        for(i=9;i>=0;--i)
        {
            sz=ct[i].size();

            while(sz>cpos[i] && ct[i][cpos[i]]<pos)
            {
                ++cpos[i];
            }

            if(sz<=cpos[i])
            {
                continue;
            }

            if(ct[i][cpos[i]]-dell-conss<=k)
            {
                pos=ct[i][cpos[i]];
                k-=ct[i][cpos[i]]-conss-dell;
                dell=ct[i][cpos[i]]-conss;
                ++cpos[i];
                ++conss;
                printf("%d",i);
                if(conss==leftt)
                {
                    break;
                }
                i=10;
            }
        }

        printf("\n");

    }


    return 0;
}
