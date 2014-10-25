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

#define MAXN 103
#define MAXC 1003
#define MAXR 10003

int arr[MAXN][MAXN];
int arr_rev[MAXN][MAXN];
map<string,int> mp;
string str1,str2,str3;
VI cars;
int distt[MAXN];
int distt_rev[MAXN];
int st;
bool vis[MAXN],vis_rev[MAXN];

int  n,c,r;

int parsee(string s)
{
    int len=s.size();
    int ret=0;

    for(int i=2;i<len-2;++i)
    {
        ret=ret*10+s[i]-'0';
    }

    return ret;
}

void min_distt(int gr[MAXN][MAXN],int di[MAXN],bool vv[MAXN])
{


    priority_queue<PII > pq;

    distt[st]=0;
    pq.push(MP(0,1));
    int lenn,u;

    while(!pq.empty())
    {
        lenn=-pq.top().first;
        u=pq.top().second;
        pq.pop();
        //printf("%d\n",lenn);

        if(vv[u])
        {
            continue;
        }

        vv[u]=true;
        di[u]=lenn;

        for(int i=2;i<=n;++i)
        {
            if(vv[i])
            {
                continue;
            }

            if(gr[u][i]!=-1)
            {
                pq.push(MP(-(lenn+gr[u][i]),i));
            }
        }
    }
}




int solve()
{
    MSET(distt,0x7f);
    MSET(vis,0);

    MSET(distt_rev,0x7f);
    MSET(vis_rev,0);

    int ret=0;

    min_distt(arr,distt,vis);
    min_distt(arr_rev,distt_rev,vis_rev);

    for(int i=0;i<c;++i)
    {
        ret+=distt[cars[i]]+distt_rev[cars[i]];
    }

    return ret;
}


int main()
{
    freopen("Text/ANARC08F.txt","r",stdin);
    int cases=0;
    int ct,ti,u,v;

    while(true)
    {
        ++cases;
        //scanf("%d %d %d",&n,&c,&r);
        cin>>n>>c>>r;
        if(n+c+r==0)
        {
            break;
        }

        ct=0;
        st=1;
        mp.clear();
        MSET(arr,-1);
        MSET(arr_rev,-1);
        cars.clear();

        for(int i=1;i<=c+1;++i)
        {
            cin>>str1;
            if(!mp[str1])
            {
                mp[str1]=++ct;
            }

            if(i>1)
            {
                cars.PB(mp[str1]);
            }
        }

        for(int i=0;i<r;++i)
        {
            cin>>str1>>str2>>str3;
            ti=parsee(str2);

            if(!mp[str1])
            {
                mp[str1]=++ct;
            }

            if(!mp[str3])
            {
                mp[str3]=++ct;
            }
            u=mp[str1];
            v=mp[str3];

            if(str2[0]=='-')
            {
                if(arr[u][v]==-1)
                {
                    arr[u][v]=ti;
                    arr_rev[v][u]=ti;
                }
                else
                {
                    arr[u][v]=min(arr[u][v],ti);
                    arr_rev[v][u]=min(arr_rev[v][u],ti);
                }
            }
            else if(str2[str2.size()-1]=='-')
            {
                if(arr[v][u]==-1)
                {
                    arr[v][u]=ti;
                    arr_rev[u][v]=ti;
                }
                else
                {
                    arr[v][u]=min(arr[v][u],ti);
                    arr_rev[u][v]=min(arr_rev[u][v],ti);
                }
            }
            else
            {
                if(arr[u][v]==-1)
                {
                    arr[u][v]=ti;
                    arr_rev[v][u]=ti;
                }
                else
                {
                    arr[u][v]=min(arr[u][v],ti);
                    arr_rev[v][u]=min(arr_rev[v][u],ti);
                }


                if(arr[v][u]==-1)
                {
                    arr[v][u]=ti;
                    arr_rev[u][v]=ti;
                }
                else
                {
                    arr[v][u]=min(arr[v][u],ti);
                    arr_rev[u][v]=min(arr_rev[u][v],ti);
                }
            }
            //printf("%d\t%d\t%d\n",u,v,ti);
        }

        printf("%d. %d\n",cases,solve());

    }


    return 0;
}
