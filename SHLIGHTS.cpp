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

#define MAXN 100005

char arr[MAXN];

int main()
{
    freopen("Text/SHLIGHTS.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    bool fl;
    int b;
    int ans,ct,lenn;
    int i;
    int ti;

    while(cases--)
    {
        b=ans=ct=0;
        ti=0;
        scanf("%s",arr);
        lenn=strlen(arr);
        i=0;

        while(i<lenn && arr[i]=='B')
        {
            ++ti;
            ++i;
        }


        while(i<lenn)
        {
            if(arr[i]=='B')
            {
                ++b;
                ans=max(ans,i-ti+1-b+ct);
                ++ct;
            }
            else
            {
                if(ct)
                {
                    --ct;
                }
            }

            ++i;
        }

        printf("%d\n",ans);
    }


    return 0;
}
