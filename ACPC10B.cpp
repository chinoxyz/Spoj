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

map<i64,int> one;
i64 aone[]={4,20,42, 145, 89, 58, 37, 16};

vector<i64> a1;
vector<i64> a2;

i64 summ(i64 x)
{
    i64  ret=0;
    i64 td;

    while(x!=0)
    {
        td=x%10;
        ret+=td*td;
        x/=10;
    }

    return ret;
}

int main() {

	freopen("Text/ACPC10B.txt","r",stdin);

	i64 x,y,mx,mn,ax,ay;
	int l1,l2;

	for(int i=0;i<8;++i)
    {
        one[aone[i]]=i+1;
    }

    while(true)
    {
        scanf("%lld %lld",&x,&y);

        if(x==0 && y==0)
        {
            break;
        }
        ax=x;
        ay=y;

        a1.clear();
        a2.clear();

        a1.PB(x);
        a2.PB(y);

        while(one[x]==0 && x!=1)
        {
            x=summ(x);
            a1.PB(x);
        }

        while(one[y]==0 && y!=1)
        {
            y=summ(y);
            a2.PB(y);
        }

        printf("%lld %lld ",ax,ay);


        if(x==1 && y!=1 || x!=1 && y==1)
        {
            printf("0\n");
        }
        else if(x==y)
        {
            l1=a1.size();
            l2=a2.size();
            --l1;
            --l2;

            while(l1>=0 && l2>=0 && a1[l1]==a2[l2])
            {
                --l1;
                --l2;
            }

            printf("%d\n",l1+l2+4);
        }
        else
        {
            l1=a1.size();
            l2=a2.size();

            mx=max(one[x],one[y]);
            mn=min(one[x],one[y]);
            printf("%d\n",l1+l2+min(mx-mn,8-mx+mn));

        }


    }



	return 0;
}
