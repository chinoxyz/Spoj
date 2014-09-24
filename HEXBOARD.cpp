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


int main()
{
    freopen("Text/HEXBOARD.txt","r",stdin);

    int n;

    while(true)
    {
        scanf("%d",&n);

        if(n==-1)
        {
            break;
        }

        //if(n>1)
        {
            int sp=(n<<1)-1;
            for(int i=0;i<sp;++i)
            {
                printf(" ");
            }
            printf("_\n");


            for(int i=1;i<n;++i)
            {
                sp-=2;

                for(int j=0;j<sp;++j)
                {
                    printf(" ");
                }
                printf("_/");

                for(int j=1;j<i;++j)
                {
                    printf(" \\_/");
                }

                printf(" \\_\n");
            }

            for(int i=1;i<=(n<<1);++i)
            {
                if(i&1)
                {
                    printf("/");

                    for(int j=1;j<n;++j)
                    {
                        printf(" \\_/");
                    }
                    printf(" \\");
                    printf("\n");
                }
                else
                {
                    for(int j=1;j<n;++j)
                    {
                        printf("\\_/ ");
                    }
                    printf("\\_/");
                    printf("\n");
                }
            }

            sp=0;

            for(int i=1;i<n;++i)
            {
                sp+=2;

                for(int j=0;j<sp;++j)
                {
                    printf(" ");
                }

                for(int j=1;j<n-i;++j)
                {
                    printf("\\_/ ");
                }
                printf("\\_/\n");
            }
        }



        printf("***\n");
    }

    return 0;
}
