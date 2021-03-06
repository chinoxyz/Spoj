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

    freopen("Text/OFORTUNE.txt","r",stdin);

    double rate;
    int principal,n,op_charge,num_years,p,ans,flag,in,cum,curr;

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&principal,&num_years,&n);
        ans=0;

        for(int i=0;i<n;++i)
        {
            p=principal;
            scanf("%d %lf %d",&flag,&rate,&op_charge);
            in=cum=0;

            if(flag==0)
            {
                for(int j=0;j<num_years;++j)
                {
                    cum+=(int)(p*rate);
                    p-=op_charge;
                }
                curr=cum+p;
            }
            else
            {
                for(int j=0;j<num_years;++j)
                {
                    in=(int)(p*rate);
                    p=p+in-op_charge;
                }
                curr=p;
            }

            ans=max(ans,curr);;
        }

        printf("%d\n",ans);
    }
    return 0;
}
