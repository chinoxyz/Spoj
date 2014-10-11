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


#define MAXN 1000005

char buff[MAXN];
int len;

int main()
{
    freopen("Text/PALIN.txt","r",stdin);

    int cases,middl,middr,stx,sty;

    scanf("%d\n",&cases);
    string orig,ans;

    while(cases--)
    {
        cin>>orig;
        len=orig.size();
        ans=orig;

        middl=len/2;
        middr=middl;
        if(len%2==0)
        {
            --middl;
        }

        for(int i=0;i<=middl;++i)
        {
            ans[len-1-i]=ans[i];
        }

        while(ans.size()<=len && ans<=orig)
        {
            stx=middl;
            sty=middr;

            while(ans[stx]=='9' && stx>=0 && sty<ans.size())
            {
                ans[stx]=ans[sty]='0';
                --stx;
                ++sty;
            }

            if(stx<0)
            {
                ans="1"+ans;
                ans[ans.size()-1]='1';
            }
            else
            {
                ++ans[stx];
                if(stx!=sty)
                {
                    ++ans[sty];
                }
            }
        }

        cout<<ans<<endl;

    }


    return 0;
}
