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

#define MAXN 30003

char arr[MAXN];
char ans[MAXN];

int n;

int main()
{
    freopen("Text/LWAR.txt","r",stdin);
    int cases,i,j;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%s",arr);
        n=strlen(arr);
        ans[n]=0;
        i=0;

        while(i<n)
        {
            if(arr[i]=='1')
            {
                if(i+1<n)
                {
                    if(arr[i+1]=='1')
                    {
                        ans[i]=arr[i];
                        ans[i+1]='0';

                        for(j=i+2;j<n;++j)
                        {
                            ans[j]='1'-arr[j]+'0';
                        }
                        break;
                    }
                    else
                    {
                        ans[i]=arr[i];
                        ans[i+1]='1';
                        i+=2;
                    }
                }
                else
                {
                    ans[i]=arr[i];
                    ++i;
                }
            }
            else
            {
                for(j=i;j<n;++j)
                {
                    ans[j]=arr[j];
                }
                break;
            }
        }

        printf("%s\n",ans);
    }



    return 0;
}
