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

#define MAXN 32005
char arr[MAXN];
int n;
int pos=0;

PII solve()
{
    PII ret;
    ++pos;
    int val,ao;
    if(arr[pos]=='(')
    {
        PII tp1=solve();
        ao=tp1.second^1;
        val=tp1.first;

        if(arr[pos]=='(')
        {
            PII tp3=solve();

            if(tp3.first)
            {
                if(ao)
                {
                    val|=1;
                }
                else
                {
                    val&=1;
                }
            }
            else
            {
                if(ao)
                {
                    val|=0;
                }
                else
                {
                    val&=0;
                }
            }
            ++pos;
            ret.first=val;
            ret.second=ao;
        }
        else
        {
            if(arr[pos]=='T')
            {
                if(ao)
                {
                    val|=1;
                }
                else
                {
                    val&=1;
                }
            }
            else
            {
                if(ao)
                {
                    val|=0;
                }
                else
                {
                    val&=0;
                }
            }
            ++pos;

            ret.first=val;
            ret.second=ao;
        }
    }
    else
    {
        if(arr[pos]=='T')
        {
            val=1;
        }
        else
        {
            val=0;
        }
        ++pos;
        if(arr[pos]=='(')
        {
            PII tp2=solve();
            ao=tp2.second^1;

            if(tp2.first)
            {
                if(ao)
                {
                    val|=1;
                }
                else
                {
                    val&=1;
                }
            }
            else
            {
                if(ao)
                {
                    val|=0;
                }
                else
                {
                    val&=0;
                }
            }
            ++pos;
            ret.first=val;
            ret.second=ao;


        }
        else
        {
            if(arr[pos]=='T')
            {
                val&=1;
            }
            else
            {
                val=0;
            }
            ++pos;
            ao=0;
            ret.first=val;
            ret.second=ao;
        }
    }

    if(pos<n && arr[pos]==')')
    {
        ++pos;
    }

    return ret;
}


int main()
{
    freopen("Text/ACPC10C.txt","r",stdin);

    int cases=0;

    while(true)
    {
        pos=0;
        ++cases;
        scanf("%s",arr);
        if(strcmp(arr,"()")==0)
        {
            break;
        }
        n=strlen(arr);

        PII ans=solve();

        printf("%d. ",cases);

        if(ans.first)
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }


    return 0;
}
