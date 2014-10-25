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

#define MAXN 100006
#define MAXM 200009

int n,m;

int on_stack[MAXN],indexx[MAXN],low_link[MAXN],componentt[MAXN];
int csz[MAXN];
int idx,num_components;
VI gr[MAXN];
stack<int> st;
bool candd[MAXN];


void tarjan(int u)
{
    int v,i;

    indexx[u]=low_link[u]=idx++;
    st.push(u);

    on_stack[u]=1;

    for(i=0;i<gr[u].size();++i)
    {
        v=gr[u][i];

        if(indexx[v]==-1)
        {
            tarjan(v);
            low_link[u]=min(low_link[u],low_link[v]);
        }
        else if(on_stack[v])
        {
            low_link[u]=min(low_link[u],indexx[v]);
        }
    }

    if(low_link[u]==indexx[u])
    {
        ++num_components;
        do
        {
            ++csz[num_components];
            v=st.top();
            st.pop();
            on_stack[v]=0;
            componentt[v]=num_components;
        }
        while(u!=v);
    }
}


void findSCC()
{
    num_components=idx=0;
    MSET(indexx,-1);
    MSET(low_link,0x7f);

    for(int i=1;i<=n;++i)
    {
        if(indexx[i]==-1)
        {
            tarjan(i);
        }
    }


}




int main()
{
    freopen("Text/CAPCITY.txt","r",stdin);

    scanf("%d %d",&n,&m);
    int x,y,ans;

    for(int i=0;i<m;++i)
    {
        scanf("%d %d",&x,&y);
        gr[x].PB(y);
    }

    findSCC();



    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<gr[i].size();++j)
        {
            if(componentt[i]!=componentt[gr[i][j]])
            {
                candd[componentt[i]]=true;
            }
        }
    }

    for(int i=1;i<=num_components;++i)
    {
        if(!candd[i])
        {
            ans=i;
            break;
        }
    }

    //printf("DD\t%d\n",ans);

    printf("%d\n",csz[ans]);



    for(int i=1;i<=n;++i)
    {
        if(componentt[i]==ans)
        {
            printf("%d ",i);
        }
    }

    printf("\n");

    return 0;
}
