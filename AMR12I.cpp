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

#define MAXN 20006

char arr[MAXN];

int main()
{
    freopen("Text/AMR12I.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int n,k;

    while(cases--)
    {
        scanf("%d %d",&n,&k);
        scanf("%s",arr);

        int fr=1;

        int ans=0;
        bool poss=false;

        for(int i=1;i<n;++i)
        {
            if(arr[i]==arr[i-1])
            {
                ++fr;
            }
            else
            {
                if(fr>=k)
                {
                    poss=true;
                }

                ans+=ceil((double)fr/k);
                fr=1;
            }
        }

        if(fr>=k)
            {
                poss=true;
            }

            ans+=ceil((double)fr/k);

            if(!poss)
            {
                ans=-1;
            }

            printf("%d\n",ans);
    }






    return 0;
}
