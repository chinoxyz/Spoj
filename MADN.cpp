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
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
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


#define MAXN 333

map<char,int> vowels;
vector<pair<int,char> > v;
vector<pair<int,char> > c;
int n;

multiset<char> ansc,ansv;
map<char,int> cost;
multiset<char>::iterator sit1,sit2;

void pree()
{
    vowels['A']=1;
    vowels['E']=1;
    vowels['I']=1;
    vowels['O']=1;
    vowels['U']=1;

    for(char i='A';i<='Z';++i)
    {
        if(vowels[i])
        {
            v.PB(MP(((i-'A')%9)+1,i));
        }
        else
        {
            c.PB(MP(((i-'A')%9)+1,i));
        }
        cost[i]=((i-'A')%9)+1;
    }

    sort(v.begin(),v.end());
    sort(c.begin(),c.end());
}



void MAIN()
{
    int cases;
    pree();

    scanf("%d",&cases);
    int tn,cct,vct;
    int i,j;

    for(int t=1;t<=cases;++t)
    {
        ansc.clear();
        ansv.clear();
        scanf("%d",&n);
        cct=n/2;
        vct=n-cct;
        tn=n;

        for(i=0;i<v.size();++i)
        {
            for(j=0;j<min(21,vct);++j)
            {
                //printf("%c\n",v[i].second);
                ansv.insert(v[i].second);
            }
            vct-=j;
        }

        for(i=0;i<c.size();++i)
        {
            for(j=0;j<min(5,cct);++j)
            {
                //printf("%c\n",c[i].second);
                ansc.insert(c[i].second);
            }
            cct-=j;
        }

        printf("Case %d: ",t);

        sit1=ansv.begin();
        sit2=ansc.begin();

        //printf("%d\t%d\n",anv.size())

        for(i=0;i<n;++i)
        {
            if(i&1)
            {
                printf("%c",*sit2);
                ++sit2;
            }
            else
            {
                printf("%c",*sit1);
                ++sit1;
            }
        }


        printf("\n");
    }
}

int main()
{
	freopen("Text/MADN.txt","r",stdin);

    MAIN();

	return 0;
}

