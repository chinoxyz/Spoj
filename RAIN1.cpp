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

#define MAXN 40004

int xs[MAXN<<1];
int n;
int ans[MAXN];

struct pointt
{
    int x,y;
    pointt(int x=0,int y=0):x(x),y(y){}
    pointt operator-(pointt p)
    {
        return pointt(x-p.x,y-p.y);
    }

    i64 operator%(pointt p)
    {
        return 1LL*x*p.y-1LL*y*p.x;
    }
};

i64 cross(pointt a,pointt b,pointt c)
{
    return (a-b)%(c-b);
}


struct roof
{
    pointt a,b;
    int i;
    bool operator<(const roof &s) const
    {
        if(a.x>s.a.x)
        {
            return cross(s.a,a,s.b)<0;
        }

        return cross(a,s.a,b)>0;
    }
};

roof arr[MAXN];
map<int,int> id;
set<roof> s;
int receiver[MAXN];
VI tarr;
int summ[MAXN];
set<roof>::iterator sit;
int d,k;

int main()
{
    freopen("Text/RAIN1.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int i,j,lenn;
    int ti;

    while(cases--)
    {
        MSET(summ,0);
        s.clear();
        id.clear();
        tarr.clear();

        scanf("%d",&n);

        for(i=0;i<n;++i)
        {
            scanf("%d %d %d %d",&(arr[i].a.x),&(arr[i].a.y),&(arr[i].b.x),&(arr[i].b.y));
            arr[i].i=i;

            ti=i<<1;
            xs[ti]=arr[i].a.x;
            xs[ti+1]=arr[i].b.x;
        }

        ti=n<<1;

        sort(xs,xs+ti);

        lenn=unique(xs,xs+ti)-xs;

        for(i=0;i<lenn;++i)
        {
            id[xs[i]]=i;
        }

        vector<vector<PII > > layer(lenn);

        for(i=0;i<n;++i)
        {
            layer[id[arr[i].a.x]].PB(PII(1,i));
            layer[id[arr[i].b.x]].PB(PII(-1,i));
        }

        for(i=0;i<lenn;++i)
        {
            if(i && !s.empty())
            {
                ans[s.rbegin()->i]+=xs[i]-xs[i-1];
            }

            for(j=0;j<layer[i].size();++j)
            {
                if(layer[i][j].first==1)
                {
                    s.insert(arr[layer[i][j].second]);
                }
            }

            for(j=0;j<layer[i].size();++j)
            {
                d=layer[i][j].first;
                k=layer[i][j].second;

                if((d==1 && arr[k].a.y<arr[k].b.y) || (d==-1 && arr[k].b.y<arr[k].a.y))
                {
                    sit=s.lower_bound(arr[k]);
                    if(sit!=s.begin())
                    {
                        receiver[k]=(--sit)->i;
                    }
                    else
                    {
                        receiver[k]=-1;
                    }
                }
            }

            for(j=0;j<layer[i].size();++j)
            {
                if(layer[i][j].first==-1)
                {
                    s.erase(arr[layer[i][j].second]);
                }
            }
        }

        for(i=0;i<n;++i)
        {
            if(receiver[i]!=-1)
            {
                ++summ[receiver[i]];
            }
        }

        for(i=0;i<n;++i)
        {
            if(!summ[i])
            {
                tarr.PB(i);
            }
        }

        for(i=0;i<n;++i)
        {
            j=tarr[i];
            if(receiver[j]==-1)
            {
                continue;
            }

            ans[receiver[j]]+=ans[j];
            --summ[receiver[j]];
            if(!summ[receiver[j]])
            {
                tarr.PB(receiver[j]);
            }
        }


        for(i=0;i<n;++i)
        {
            printf("%d\n",ans[i]);
            ans[i]=0;
        }
    }

    return 0;
}
