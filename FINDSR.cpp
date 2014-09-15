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


#define MAXL 100005

int str_len;
int kmp_arr[MAXL];
char str[MAXL];

void kmp_preprocess()
{
    int i=0;
    int j=-1;
    kmp_arr[i]=j;

    while(i<str_len)
    {
        while(j>=0 && str[i]!=str[j])
        {
            j=kmp_arr[j];
        }

        ++i;
        ++j;
        kmp_arr[i]=j;
    }
}


int main()
{
    freopen("Text/FINDSR.txt","r",stdin);


    while(true)
    {
        //MSET(kmp_arr,0);
        //scanf("%s",str);
        cin>>str;
        if(strcmp(str,"*")==0)
        {
            break;
        }

        //string str(buff);
        str_len=strlen(str);
        kmp_preprocess();

        if(kmp_arr[str_len]==0 || ((str_len)%(str_len-kmp_arr[str_len])))
        {
            printf("1\n");
        }
        else
        {
            printf("%d\n",((str_len)/(str_len-kmp_arr[str_len])));
        }
    }

    return 0;
}


