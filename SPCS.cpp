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


#define MAXL 100005

char s[MAXL];

int main()
{
    freopen("Text/SPCS.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    bool poss;
    int st,en,len;
    while(cases--)
    {
        poss=true;
        scanf("%s",s);
        len=strlen(s);
        st=0;
        en=len-1;

        while(st<en)
        {
            while((st+1)<en && s[st+1]==s[st])
            {
                ++st;
            }

            while(en-1>st && s[en-1]==s[en])
            {
                --en;
            }

            if(s[st]!=s[en])
            {
                poss=false;
                break;
            }
            ++st;
            --en;
        }

        if(poss)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }





    return 0;
}
