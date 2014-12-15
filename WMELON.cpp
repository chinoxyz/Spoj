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

#define MAXN 1005
#define INF 99999999

PIPII points[MAXN];
int ys[MAXN];
int arr[MAXN];
int ret;
int mnx,mxx;
int n;
int k;


void solve(int downn,int upp)
{
    int h=ys[upp]-ys[downn];
    int st,en;
    st=mnx;
    en=mnx;

    int summ=arr[mnx];

    //printf("%d\t%d\n",mnx,mxx);
    //printf("%d\n",summ);

    while(en<=mxx)
    {
        //printf("%d\n",summ);
        if(summ>=k)
        {
            ret=min(ret,h*(en-st));
            summ-=arr[st++];
        }
        else
        {
            summ+=arr[++en];
        }
    }
}



int main()
{
    freopen("Text/WMELON.txt","r",stdin);

    int cases;
    int i,j,l;
    int lenn;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&k);
        mxx=0;
        mnx=INF;
        ret=INF;

        for(int i=0;i<n;++i)
        {
            scanf("%d %d %d",&points[i].first,&points[i].second.first,&points[i].second.second);
            ys[i]=points[i].second.first;
            mnx=min(points[i].first,mnx);
            mxx=max(points[i].first,mxx);
        }


        if(mnx==mxx)
        {
            printf("0\n");
            continue;
        }

        sort(ys,ys+n);
        lenn=unique(ys,ys+n)-ys;

        if(lenn==1)
        {
            printf("0\n");
            continue;
        }

        for(i=0;i<lenn;++i)
        {
            for(j=i+1;j<lenn;++j)
            {
                MSET(arr,0);

                for(l=0;l<n;++l)
                {
                    if(points[l].second.first>=ys[i] && points[l].second.first<=ys[j])
                    {
                        arr[points[l].first]+=points[l].second.second;
                    }
                }

                solve(i,j);
            }
        }

        printf("%d\n",ret);
    }


    return 0;
}
