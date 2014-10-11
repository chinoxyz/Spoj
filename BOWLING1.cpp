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

#define MAXN 32

int scores[MAXN];
int n,ans;
char buff[9999];



int main()
{
    freopen("Text/BOWLING1.txt","r",stdin);


    int cases;

    scanf("%d\n",&cases);
    bool strikee,spare;
    int turns,pos=0;


    while(cases--)
    {
        turns=0;
        pos=0;
        strikee=spare=false;
        ans=0;
        gets(buff);
        stringstream ss(buff);

        n=0;

        while(ss>>scores[n])
        {
            ++n;
        }

        while(true)
        {
            strikee=spare=false;
            //printf("%d\t%d\n",cases,scores[i]);

            ++turns;

            if(turns==10)
            {
                for(int j=pos;j<n;++j)
                {
                    ans+=scores[j];
                }
                break;
            }

            if(scores[pos]==10)
            {
                strikee=true;
                for(int j=0;j<3 && pos+j<n;++j)
                {
                    ans+=scores[pos+j];
                }
                ++pos;
            }
            else if(scores[pos]+scores[pos+1]==10)
            {
                spare=true;
                for(int j=0;j<3 && pos+j<n;++j)
                {
                    ans+=scores[pos+j];
                }
                ++pos;
                ++pos;
            }
            else
            {
                for(int j=0;j<2 && pos+j<n;++j)
                {
                    ans+=scores[pos+j];
                }
                ++pos;
                ++pos;
            }
        }

        printf("%d\n",ans);



    }

    return 0;
}
