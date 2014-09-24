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

#define MAXN 5002

const i64 INF=999999999999999999LL;

struct data
{
    int pos;
    i64 c,s,b;
};


data arr[MAXN];

int a1[MAXN];
int a2[MAXN];
int a3[MAXN];


bool sortc(int a,int b)
{
    return arr[a].c>arr[b].c;
}

bool sorts(int a,int b)
{
    return arr[a].s>arr[b].s;
}

bool sortb(int a,int b)
{
    return arr[a].b>arr[b].b;
}

int n;
i64 allc,alls,allb;


int main()
{
    freopen("Text/CANDY2.txt","r",stdin);

    i64 x,y,z;
    allc=alls=allb=0;

    int p1,p2,p3;
    i64 minn=INF,ti;

    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%lld %lld %lld",&x,&y,&z);
        //printf("%lld\t%lld\t%lld\n",x,y,z);
        allc+=x;
        alls+=y;
        allb+=z;
        a1[i]=a2[i]=a3[i]=i;
        arr[i].pos=i;
        arr[i].c=x;
        arr[i].s=y;
        arr[i].b=z;
    }

    sort(a1,a1+n,sortc);
    sort(a2,a2+n,sorts);
    sort(a3,a3+n,sortb);


    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(a1[i]==a2[j])
            {
                continue;
            }

            for(int k=0;k<3;++k)
            {
                if(a1[i]==a3[k] || a2[j]==a3[k])
                {
                    continue;
                }

                ti=allc+alls+allb-arr[a1[i]].c-arr[a2[j]].s-arr[a3[k]].b;

                if(minn>ti)
                {
                    //printf("DD\n");
                    minn=ti;
                    p1=a1[i];
                    p2=a2[j];
                    p3=a3[k];
                }
            }
        }
    }

    printf("%d\n%d\n%d\n",p1,p2,p3);

    return 0;
}
