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



int main()
{
    freopen("Text/CUTSQRS.txt","r",stdin);

    int cases,x,y;
    int tot,winn,losee;
    bool fl;

    scanf("%d",&cases);
    int ct;
    int ti;

    while(cases--)
    {
        scanf("%d %d",&x,&y);

        if(x==y)
        {
            printf("7\n");
            continue;
        }

        tot=winn=losee=0;
        fl=1;

        while(x!=0)
        {
            ct=y/x;
            if(fl)
            {
                if(ct==1)
                {
                    losee^=1;
                }
                else
                {
                    fl=0;
                }
            }

            tot+=ct-1;

            ti=x;
            x=y%x;
            y=ti;
        }

        winn=tot-1;

        tot=(tot*log10(2))+1;
        winn=(winn*log10(2))+1;

        printf("%d\n",tot+winn+5+losee);
    }


    return 0;
}
