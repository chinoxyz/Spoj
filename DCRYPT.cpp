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

#define MAXL 100006


int main() {

    freopen("Text/DCRYPT.txt","r",stdin);

    int cases,k,len,i;
    char str[MAXL];

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&k);
        scanf("%s",str);
        len=strlen(str);

        if(k<26)
        {
            REP(i,len)
            {
                if(str[i]=='.')
                {
                    str[i]=' ';
                }
                else
                {
                    if(islower(str[i]))
                    {
                        int x=str[i]-'a';
                        x+=k;
                        x%=26;
                        str[i]=x+'a';
                    }
                    else
                    {
                        int x=str[i]-'A';
                        x+=k;
                        x%=26;
                        str[i]=x+'A';
                    }
                }
            }
        }
        else
        {
            REP(i,len)
            {
                if(str[i]=='.')
                {
                    str[i]=' ';
                }
                else
                {
                    if(islower(str[i]))
                    {
                        int x=str[i]-'a';
                        x+=k;
                        x%=26;
                        str[i]=x+'A';
                    }
                    else
                    {
                        int x=str[i]-'A';
                        x+=k;
                        x%=26;
                        str[i]=x+'a';
                    }
                }
            }
        }

        printf("%s\n",str);
    }

    return 0;
}
