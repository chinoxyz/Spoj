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


#define MAXN 44
char arr[MAXN];
char ret[MAXN];
int n;
int ct;



void solve()
{
    ct=0;
    if(strcmp(arr,"0")==0)
    {
        ret[0]='0';
        return;
    }
    if(n==1)
    {
        ret[0]='1';
        return;
    }

    int st;
    int summ=0;
    if(arr[0]<'9')
    {
        st=1;
        summ=arr[0]-'0';
    }
    else
    {
        st=0;
    }

    ct=1;

    while(st<n)
    {
        summ*=10;
        summ+=arr[st]-'0';
        ret[ct]=(summ/9)+'0';
        summ%=9;
        ++ct;
        ++st;
    }

    if(summ)
    {
        --ct;
        while(ct>=1 && ret[ct]=='9')
        {
            ret[ct]='0';
            --ct;
        }
        if(ct)
        {
            ret[ct]+=1;
            ct=1;
        }
        else
        {
            ret[ct]='1';
            ct=0;
        }
    }
    else
    {
        ct=1;
    }
}

int main()
{
    freopen("Text/MINNUM.txt","r",stdin);


    while(true)
    {
        MSET(ret,0);
        ct=0;
        scanf("%s",arr);
        if(strcmp(arr,"-1")==0)
        {
            break;
        }
        n=strlen(arr);

        solve();

        printf("%s\n",ret+ct);

    }


    return 0;
}
