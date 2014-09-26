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

#define MAXL 9999999

u64 ans=0;
char buff[MAXL];
u64 ct[26];
u64 tot=0;
int len;

u64 fact(int n)
{
    u64 ret=1;

    for(int i=2;i<=n;++i)
    {
        ret*=i;
    }

    return ret;
}

int main(){

    freopen("Text/YODA.txt","r",stdin);

    while(gets(buff)!=NULL)
    {
        //cout<<buff<<endl;
        tot=0;
        MSET(ct,0);
        len=strlen(buff);

        for(int i=0;i<len;++i)
        {
            if(buff[i]>='a' && buff[i]<='z')
            {
                ++tot;
                ++ct[buff[i]-'a'];
            }
            else if(buff[i]>='A' && buff[i]<='Z')
            {
                ++tot;
                ++ct[buff[i]-'A'];
            }
        }

        if(tot==0)
        {
            printf("1\n");
        }
        else
        {
            int ctd=0;
            u64 cte=0;

            for(int i=0;i<26;++i)
            {
                if(ct[i]&1)
                {
                    ++ctd;
                    cte+=ct[i];
                }
                else
                {
                    cte+=ct[i];
                }
            }

            if(ctd>1)
            {
                printf("0\n");
            }
            else
            {
                cte/=2;
                u64 ans=fact(cte);

                for(int i=0;i<26;++i)
                {
                    if(ct[i]>0)
                    {
                        ans/=fact(ct[i]/2);
                    }
                }
                printf("%llu\n",ans);
            }
        }
    }

    return 0;
}




