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


#define MAXN 105

char arr[MAXN];
int bb,cc;
VI bc,cb;

int main()
{
    freopen("Text/DOMINO1.txt","r",stdin);

    int n;

    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%s",arr);
        int lenn=strlen(arr);

        if(arr[0]=='B')
        {
            if(arr[lenn-1]=='B')
            {
                bb-=lenn;
            }
            else
            {
                bc.PB(-lenn);
            }
        }
        else
        {
            if(arr[lenn-1]=='C')
            {
                cc-=lenn;
            }
            else
            {
                cb.PB(-lenn);
            }
        }
    }

    int ret=0;

    ret=min(bb,cc);
    int s1,s2;
    s1=bc.size();
    s2=cb.size();
    sort(bc.begin(),bc.end());
    sort(cb.begin(),cb.end());

    if(s1 || s2)
    {
        int mn=min(s1,s2);
        int ti=0;

        for(int i=0;i<mn;++i)
        {
            ti+=bc[i]+cb[i];
        }

        if(s1<s2)
        {
            ti+=cb[s1];
        }
        else if(s1>s2)
        {
            ti+=bc[s2];
        }

        ret=bb+cc+ti;
    }

    ret=-ret;

    printf("%d\n",ret);



    return 0;
}

