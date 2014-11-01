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


#define MAXN 999999

char buff[5][MAXN];
int mlen;
map<string,int> mp;
string arr[10];

void pree()
{


    arr[0]=" _ | ||_|";
    arr[1]="     |  |";
    arr[2]=" _  _||_ ";
    arr[3]=" _  _| _|";
    arr[4]="   |_|  |";
    arr[5]=" _ |_  _|";
    arr[6]=" _ |_ |_|";
    arr[7]=" _   |  |";
    arr[8]=" _ |_||_|";
    arr[9]=" _ |_|  |";

    for(int i=0;i<10;++i)
    {
        mp[arr[i]]=i+1;
    }
}


void solve()
{
    string ti;
    int tlen;

    for(int i=0;i<mlen;i+=3)
    {
        ti="";
        for(int j=0;j<3;++j)
        {
            tlen=strlen(buff[j]);
            for(int k=0;k<3;++k)
            {
                if(i+k>=tlen)
                {
                    ti+=' ';
                }
                else
                {
                    ti+=buff[j][i+k];
                }
            }
        }

        //cout<<ti<<endl;

        printf("%d",mp[ti]-1);
    }

    printf("\n");
}

int main()
{
    freopen("Text/DIGNUM.txt","r",stdin);

    pree();

    while(gets(buff[0]))
    {
        for(int i=1;i<3;++i)
        {
            gets(buff[i]);
        }
        mlen=0;

        for(int i=0;i<3;++i)
        {
            //printf("%s\n",buff[i]);
            //mlen=max(mlen,strlen(buff[i]));
            int tii=strlen(buff[i]);
            mlen=max(mlen,tii);
           // cout<<strlen(buff[i])<<endl;
            //mlen=max(mlen,mlen);
        }

        solve();
    }



    return 0;
}
