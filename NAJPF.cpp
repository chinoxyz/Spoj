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

#define MAXN 1000006

char s[MAXN],p[MAXN];
VI ans;
int arr[MAXN];
int ls,lp;

void kmp_preprocess()
{
    int i=0,j=-1;
    arr[i]=j;

    while(i<lp)
    {
        while(j>=0 && p[i]!=p[j])
        {
            j=arr[j];
        }
        ++i;
        ++j;
        arr[i]=j;
    }

}

void kmp_search()
{
    int i=0,j=0;

    while(i<ls)
    {
        while(j>=0 && s[i]!=p[j])
        {
            j=arr[j];
        }
        ++i;
        ++j;
        if(j==lp)
        {
            ans.PB(i-j+1);
            j=arr[j];
        }
    }
}


int main()
{
    freopen("Text/NAJPF.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {

        ans.clear();
        scanf("%s %s",s,p);

        ls=strlen(s);
        lp=strlen(p);

        MSET(arr,0);

        kmp_preprocess();

        kmp_search();




        if(ans.size())
        {
            printf("%d\n",ans.size());
            printf("%d",ans[0]);
            for(int i=1;i<ans.size();++i)
            {
                printf(" %d",ans[i]);
            }
            printf("\n");
        }
        else
        {
            printf("Not Found\n");
        }
        printf("\n");
    }



    return 0;
}
