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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 100000
int n;
double k,pos,ltime,lpos;
double ans=0;


void MAIN()
{
    int cases;
    int ans;

    //scanf("%d",&cases);
    cin>>cases;
    double x;
    double tp,tt;
    int i;
    double diff;


    for(int t=1;t<=cases;++t)
    {
        ans=0;
        //scanf("%f %d",&k,&n);
        cin>>k>>n;
        //scanf("%f",&lpos);
        cin>>lpos;
        ltime=0;

        for(i=1;i<n;++i)
        {
            //scanf("%f",&x);
            cin>>x;
            if(x<=lpos)
            {
                tp=lpos+k;
                tp=min(tp,x+ltime);
                lpos=max(lpos,tp);
                ltime=ltime;
            }
            else
            {
                tp=x-ltime;
                if(tp-lpos<=k)
                {
                    lpos=min(x+ltime,lpos+k);
                }
                else
                {
                    diff=tp-lpos-k;
                    tt=ltime+diff/2.0;
                    lpos=x-tt;
                    ltime=tt;
                }
            }
        }

        printf("%.3f\n",ltime);
    }


}

int main()
{
	freopen("Text/GLASNICI.txt","r",stdin);

    MAIN();

	return 0;
}

