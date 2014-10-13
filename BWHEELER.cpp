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

#define MAXN 1005

char arr[MAXN];
char sortedd[MAXN];
int mp[MAXN];
int k;
int len;
int cts[26];

void sortt()
{
    for(int i=0;i<len;++i)
    {
        ++cts[arr[i]-'a'];
    }
    int ln=0;
    for(int i=0;i<26;++i)
    {
        while(cts[i])
        {
            --cts[i];

            sortedd[ln++]=i+'a';
        }
    }
    sortedd[ln]=0;
}

void mapp()
{
    int j;
    for(int i=0;i<len;++i)
    {
        if(!i || sortedd[i]!=sortedd[i-1])
        {
            j=0;
        }
        else
        {
            ++j;
        }

        while(sortedd[i]!=arr[j])
        {
            ++j;
        }
        mp[i]=j;
    }
}


int main()
{
    freopen("Text/BWHEELER.txt","r",stdin);

    while(true)
    {
        scanf("%d",&k);
        if(k==0)
        {
            break;
        }
        --k;
        scanf("%s",arr);
        len=strlen(arr);

        sortt();
        mapp();


        int i;

        for(i=0,k=mp[k];i<len;++i,k=mp[k])
        {

            printf("%c",arr[k]);
        }
        printf("\n");
    }



    return 0;
}
