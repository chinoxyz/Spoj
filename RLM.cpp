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


    i64 str_to_i64(char *str)
    {
        i64 ret=0;
        int x,y;
        int i,len=strlen(str);

        for(i=0;i<len;i+=2)
        {
            x=str[i]-'0';
            y=str[i+1]-'0';

            while(x--)
            {
                ret=ret*10+y;
            }
        }

        return ret;
    }


    void calc_store(i64 num1,i64 num2,char *op,char *ret)
    {
        int k=0,cnt;
        i64 r;

        char tstr[25],v;

        switch(op[0])
        {
            case '+': r = num1 + num2; break;
            case '-': r = num1 - num2; break;
            case '*': r = num1 * num2; break;
            case '/': r = num1 / num2; break;
        }

        sprintf(tstr,"%lld",r);

        for(int i=0,j;tstr[i];i=j)
        {
            v=tstr[i];
            for(j=i,cnt=0;j<i+9 && tstr[j] && v==tstr[j];j++,cnt++);
            ret[k++]=cnt+'0';
            ret[k++]=v;
        }

        if(!k)
        {
            strcpy(ret,"10");
            k+=2;
        }

        ret[k]=0;
    }

int main()
{
    freopen("Text/RLM.txt","r",stdin);

    char num1[25], num2[25], op[2], ret[50];
	i64 n1, n2;
	while(scanf("%s %s %s", num1, op, num2)==3) {
		n1 = str_to_i64(num1);
		n2 = str_to_i64(num2);
		calc_store(n1, n2, op, ret);
		printf("%s %s %s = %s\n", num1, op, num2, ret);
	}


    return 0;
}



