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

char buff[100006];
int len;
char b2[50];

int main()
{
    freopen("Text/RLE.txt","r",stdin);
    int j;

    while(gets(buff)!=NULL)
    {
        len=strlen(buff);
        string orig(buff);
        string ans="";

        for(int i=0;i<len;i=j)
        {
            j=i+1;

            while(j<len && orig[j]==orig[i])
            {
                ++j;
            }

            int l1=j-i;
            sprintf(b2,"%d",j-i);

            string two(b2);
            two+="!";
            two+=orig[i];


            int l2=two.length();

            if(l1<=l2)
            {
                ans+=orig.substr(i,j-i);
            }
            else
            {
                ans+=two;
            }
        }

        ans+="\0";

        printf("%s\n",ans.c_str());
    }

    return 0;
}
