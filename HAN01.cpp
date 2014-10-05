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

VI arr[3];

int main()
{
    freopen("Text/HAN01.txt","r",stdin);

    int cases;
    int i,n,msb,curr,ct,pre,ti;
    i64 k;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %lld",&n,&k);
        //printf("%d\t%lld\n",n,k);
        for(i=0;i<3;++i)
        {
            arr[i].clear();
        }

        if(k&(1LL<<(n-1)))
        {
            msb=1;
            curr=2;
        }
        else
        {
            msb=0;
            curr=0;
        }

        arr[curr].PB(n);
        pre=msb;



        for(i=n-2;i>=0;--i)
        {
            ti=((k&(1LL<<i))>0LL);
            if(ti==pre)
            {
                arr[curr].PB(i+1);
            }
            else
            {
                pre=ti;
                ct=n-i;
                //printf("CCCCCCCCCTtttttttt\t%d\t%d\n",ct,i+1);

                if(ct&1)
                {
                    if(ti==1)
                    {
                        curr+=2;
                        curr%=3;
                    }
                    else
                    {
                        curr+=1;
                        curr%=3;
                    }

                }
                else
                {

                    if(ti==1)
                    {
                        curr+=1;
                        curr%=3;
                    }
                    else
                    {
                        curr+=2;
                        curr%=3;
                    }
                }

                arr[curr].PB(i+1);
            }

            //printf("%d\t%d\t%d\n",curr,i+1,ti);
        }


        printf("1: ");
        //printf("%d\n",arr[0].size()-1);
        for(i=0;i<(int)arr[0].size()-1;++i)
        {
            //printf("DD\n");
            printf("%d|",arr[0][i]);
        }

        if(arr[0].size()>0)
        {
            printf("%d",arr[0][i]);
        }
        printf("\n");

        printf("2: ");
        for(i=0;i<(int)arr[2].size()-1;++i)
        {
            //printf("DD\n");
            printf("%d|",arr[2][i]);
        }
        if(arr[2].size())
        {
            printf("%d",arr[2][i]);
        }
        printf("\n");

        printf("3: ");
        for(i=0;i<(int)arr[1].size()-1;++i)
        {
            //printf("DD\n");
            printf("%d|",arr[1][i]);
        }

        if(arr[1].size())
        {
            printf("%d",arr[1][i]);
        }
        printf("\n");
    }


    return 0;
}
