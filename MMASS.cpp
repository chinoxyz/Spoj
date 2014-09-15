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

char buff[105];
int len;
string formula;

int get_weight(char c)
{
    if(c=='H')
    {
        return 1;
    }

    if(c=='C')
    {
        return 12;
    }

    if(c=='O')
    {
        return 16;
    }

}

int pos=0;
int countt()
{
    int result=0;

    while(true)
    {
        if(pos>=len || formula[pos]==')')
        {
            ++pos;
            return result;
        }

        if(formula[pos]=='(')
        {
            ++pos;
            int tt=countt();
            if(formula[pos]>='0' && formula[pos]<='9')
            {
                result+=tt*(formula[pos]-'0');
                ++pos;
            }
            else
            {
                result+=tt;
            }

            continue;
            //return result;
        }

        if((pos+1)<len && (formula[pos+1]>='0' && formula[pos+1]<='9') )
        {

            result+=(get_weight(formula[pos])*(formula[pos+1]-'0'));
            ++pos;
        }
        else
        {
            result+=get_weight(formula[pos]);
        }

        ++pos;
    }

    return result;
}

int main()
{
    freopen("Text/MMASS.txt","r",stdin);

    scanf("%s",buff);
    string ts(buff);
    formula="("+ts+")1";
    //printf("%s\n",formula.c_str());
    len=formula.size();
    printf("%d\n",countt());

    return 0;
}


