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

int num[210],len,ans[500],alen;
int mp[]={0,1,2,5,9,8,6};


bool is_not_zero()
{
    for(int i=0;i<len;++i)
    {
        if(num[i])
        {
            return true;
        }
    }

    return false;
}


int main()
{
    freopen("Text/IGARB.txt","r",stdin);


    int cases,temp=0;
    char buff[210];
    cin>>cases;
    getchar();

    while(cases--)
    {
        MSET(num,0);
        MSET(ans,0);

        cin>>buff;
        len=strlen(buff);

        for(int i=0;i<len;++i)
        {
            num[i]=buff[i]-'0';
        }

        alen=0;
        temp=0;

        while(is_not_zero())
        {
            temp=0;

            for(int i=0;i<len;++i)
            {
                temp=temp*10+num[i];
                num[i]=temp/7;
                temp%=7;
            }
            ans[alen++]=temp;
        }

        for(int i=0;i<alen;++i)
        {
            printf("%d",mp[ans[i]]);
        }

        printf("\n");
    }



    return 0;
}
