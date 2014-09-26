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


int main(){

    freopen("Text/CSQUARE.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    i64 a,m,ans;
    char bc[255];
    i64 arr[255];
    int len;

    while(cases--)
    {
        scanf("%lld %s %lld",&a,bc,&m);
        string b(bc);
        a%=m;
        ans=1;
        len=b.size();
        MSET(arr,0);
        arr[0]=a;
        arr[1]=(a*a*a)%m;


        for(int i=2;i<len;++i)
        {
            arr[i]=(arr[i-1]*arr[i-1]*arr[i-1])%m;
        }

        for(int i=len-1,j=0;i>=0;--i,++j)
        {
            if(b[i]!='0')
            {
                ans=ans*(((i64)pow(arr[j],b[i]-'0'))%m);
                ans%=m;
            }

            //printf("ANS\t%lld\n",ans);
        }

        printf("%lld\n",ans);
    }


    return 0;
}
