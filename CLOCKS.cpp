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

#define MAXN 22
int arr[1<<MAXN];
int prevv[1<<MAXN];

VI decode(int numm)
{
    VI ret;

    for(int i=0;i<9;++i)
    {
        ret.PB(numm%4);
        numm/=4;
    }
    return ret;
}

int encode(VI v)
{
    int ret=0;
    int p=1;

    for(int i=0;i<9;++i)
    {
        ret+=v[i]*p;
        p*=4;
    }

    return ret;
}


queue<int> q;


int tarr[10][9]={
                {1,1,0,1,1,0,0,0,0},
                {1,1,0,1,1,0,0,0,0},
                {1,1,1,0,0,0,0,0,0},
                {0,1,1,0,1,1,0,0,0},
                {1,0,0,1,0,0,1,0,0},
                {0,1,0,1,1,1,0,1,0},
                {0,0,1,0,0,1,0,0,1},
                {0,0,0,1,1,0,1,1,0},
                {0,0,0,0,0,0,1,1,1},
                {0,0,0,0,1,1,0,1,1},
};

VI moves[10];

void insertt(int pos)
{
    for(int i=0;i<9;++i)
    {
        if(tarr[pos][i])
        {
            moves[pos].PB(i);
        }
    }
}

void init()
{
    for(int i=1;i<=9;++i)
    {
        insertt(i);
    }
}

VI tryy(int pos,VI v)
{
    for(int i=0;i<moves[pos].size();++i)
    {
        v[moves[pos][i]]=(v[moves[pos][i]]+3)%4;
    }

    return v;
}

void solve(int n)
{
    init();
    arr[0]=1;
    prevv[0]=0;
    q.push(0);
    VI v,v2;
    int c2,curr;
    int i;
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        v=decode(curr);
        //printf("DD\t%d\n",curr);

        for(i=1;i<=9;++i)
        {
            v2=tryy(i,v);
            c2=encode(v2);
            if(arr[c2])
            {
                continue;
            }

            arr[c2]=i;
            prevv[c2]=curr;
            if(c2==n)
            {
                return;
            }
            q.push(c2);
        }
    }
}



void MAIN()
{
    VI v;
    int ti;

    for(int i=0;i<9;++i)
    {
        scanf("%d",&ti);
        //printf("%d\n",ti);
        v.PB(ti);
    }

    int n=encode(v);
    if(!n)
    {
        printf("\n");
    }
    else
    {
        solve(n);
        VI v;
        while(n)
        {
            v.PB(arr[n]);
            n=prevv[n];
        }

        reverse(v.begin(),v.end());
        for(int i=0;i<v.size()-1;++i)
        {
            printf("%d ",v[i]);
        }
        printf("%d\n",v[v.size()-1]);
    }
}

int main ()
{
	freopen("Text/CLOCKS.txt","r",stdin);

    MAIN();

	return 0;
}
