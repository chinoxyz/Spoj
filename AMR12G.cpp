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


#define MAXN 52

char arr[MAXN][MAXN];
int ct[MAXN];

int main(){

    freopen("Text/AMR12G.txt","r",stdin);

    int n,m,cases,k;

    scanf("%d",&cases);

    while(cases--)
    {
        MSET(ct,0);

        scanf("%d %d %d",&n,&m,&k);

        for(int i=0;i<n;++i)
        {
            scanf("%s",&arr[i]);

            for(int j=0;j<m;++j)
            {
                if(arr[i][j]=='*')
                {
                    ++ct[i];
                }
            }
        }

        sort(ct,ct+n);

        for(int i=0;i<n && k>0;++i)
        {
            if(2*ct[i]<m)
            {
                ct[i]=m-ct[i];
                --k;
            }
            else
            {
                break;
            }
        }

        sort(ct,ct+n);

        if(k&1)
        {
            ct[0]=m-ct[0];
        }

        int ans=0;

        for(int i=0;i<n;++i)
        {
            ans+=ct[i];
        }

        printf("%d\n",ans);
    }


    return 0;
}


