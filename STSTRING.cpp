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

string a,b;
char arr[7];
int ct[7];


void fn(int pos)
{
    ++ct[pos-1];
    if(pos==7)
    {
        return;
    }

    for(char i='A';i<='J';++i)
    {
        if(abs(arr[pos-1]-i)<=1)
        {
            continue;
        }
        arr[pos]=i;
        fn(pos+1);
    }
}


void pree()
{
    arr[0]='d';

    fn(1);
}


int dfs(int pos,int l,int fl)
{
    if(pos>l)
    {
        arr[l+1]='\0';
        string s(arr+1);

        //cout<<s<<",";

        if(fl==2)
        {
            if(s>a && s<b)
            {

                return 1;
            }
        }
        else if(fl==0)
        {
            if(s>a)
            {

                return 1;
            }
        }
        else
        {
            if(s<b)
            {

                return 1;
            }
        }


        return 0;
    }
    int ret=0;
    for(char i='A';i<='J';++i)
    {
        if(abs(arr[pos-1]-i)<=1)
        {
            continue;
        }
        arr[pos]=i;
        ret+=dfs(pos+1,l,fl);
    }

    return ret;
}

int calc(int l,int fl)
{
    MSET(arr,0);
    arr[0]='d';

    int ret=0;

    ret+=dfs(1,l,fl);


    return ret;
}

int solve()
{
    int l1=a.size();
    int l2=b.size();
    int ret=0;

    if(l1==l2)
    {
        ret+=calc(l1,2);
    }
    else
    {
        for(int i=l1+1;i<l2;++i)
        {
            ret+=ct[i];
        }

        ret+=calc(l1,0);
        ret+=calc(l2,1);
    }

    return ret;
}

int main()
{
    freopen("Text/STSTRING.txt","r",stdin);

    pree();

    while(cin>>a)
    {
        cin>>b;

        printf("%d\n",solve());
    }


    return 0;
}

