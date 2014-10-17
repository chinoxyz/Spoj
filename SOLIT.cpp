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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64


#define MAXN 9



set<PII >::iterator it,it2;

struct data
{
    set<PII > arr;
    data(int *a)
    {
        for(int i=0;i<4;++i)
        {
            arr.insert(MP(a[2*i],a[2*i+1]));
        }
    }

    data(set<PII > barr)
    {
        set<PII >::iterator it;
        it=barr.begin();

        for(int i=0;i<4;++i)
        {
            arr.insert(*it);
            ++it;
        }
    }

};

data *st,*en;
int a[MAXN];

bool vis[MAXN][MAXN][MAXN][MAXN][MAXN][MAXN][MAXN][MAXN];

int dx[]={-1,0,1,0,-2,0,2,0};
int dy[]={0,1,0,-1,0,2,0,-2};
bool poss;


inline bool is_vis(data *x)
{
    int arr[8];

    it=x->arr.begin();
    for(int i=0;i<4;++i)
    {
        arr[2*i]=it->first;
        arr[2*i+1]=it->second;
        ++it;
    }
    return vis[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]][arr[5]][arr[6]][arr[7]];
}

inline void set_vis(data *x)
{
    int arr[8];

    it=x->arr.begin();
    for(int i=0;i<4;++i)
    {
        arr[2*i]=it->first;
        arr[2*i+1]=it->second;
        ++it;
    }

    vis[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]][arr[5]][arr[6]][arr[7]]=1;
}

inline bool is_en(data *x)
{
    bool ret=true;
    it=x->arr.begin();
    it2=en->arr.begin();

    for(int i=0;i<4;++i)
    {
        if(it->first!=it2->first || it->second!=it2->second)
        {
            ret=false;
            break;
        }
        ++it;
        ++it2;
    }

    return ret;
}

inline bool is_valid(int x,int y,data *a)
{
    if(x<=1 || y<=1 || x>8 || y>8)
    {
        return false;
    }

    it=a->arr.begin();

    for(int i=0;i<4;++i)
    {
        if(it->first==x && it->second==y)
        {
            return false;
        }
        ++it;
    }

    return true;
}



inline void solve()
{
    poss=false;
    MSET(vis,0);

    queue<pair<int, data * > > q;
    q.push(MP(0,st));
    data *td,*ti;

    int nx,ny,distt;
    int i,j;
    set<PII >::iterator it,it2;

    while(!q.empty())
    {
        distt=q.front().first;
        td=q.front().second;
        q.pop();

        if(is_en(td))
        {
            poss=true;
            break;
        }

        if(distt>=8)
        {
            continue;
        }

        if(is_vis(td))
        {
            continue;
        }



        set_vis(td);


        it=td->arr.begin();

        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
            {
                nx=it->first+dx[j];
                ny=it->second+dy[j];

                if(is_valid(nx,ny,td))
                {
                    ti=new data(td->arr);
                    it2=ti->arr.find(MP(it->first,it->second));
                    ti->arr.erase(it2);
                    ti->arr.insert(MP(nx,ny));
                    q.push(MP(distt+1,ti));
                }
                else
                {
                    nx=it->first+dx[j+4];
                    ny=it->second+dy[j+4];

                    if(is_valid(nx,ny,td))
                    {
                        ti=new data(td->arr);
                        it2=ti->arr.find(MP(it->first,it->second));
                        ti->arr.erase(it2);
                        ti->arr.insert(MP(nx,ny));
                        q.push(MP(distt+1,ti));
                    }
                }
            }
            ++it;
        }
    }

    if(poss)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}


int main()
{
    freopen("Text/SOLIT.txt","r",stdin);
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        for(int i=0;i<8;++i)
        {
            scanf("%d",a+i);
        }

        st=new data(a);

        for(int i=0;i<8;++i)
        {
            scanf("%d",a+i);
        }

        en=new data(a);
        //print_node(en);

        solve();
    }
    return 0;
}
