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


#define MAXV 5003

VI adjacency[MAXV];
int no_vert,no_edge;
int indexx[MAXV],low_link[MAXV],on_stack[MAXV],component[MAXV];
int idx,num_components;

stack<int> st;

bool invalid_component[MAXV];

void tarjan(int u)
{
    int v,i;

    indexx[u]=low_link[u]=idx++;
    st.push(u);
    on_stack[u]=1;

    for(i=0;i<adjacency[u].size();++i)
    {
        v=adjacency[u][i];
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
            v=st.top();
            st.pop();
            on_stack[v]=0;
            component[v]=num_components;
        }
        while(u!=v);
    }

}

void findSCC()
{
    num_components=0;
    idx=0;
    MSET(indexx,-1);
    MSET(on_stack,0);
    MSET(low_link,0x7f);
    MSET(invalid_component,0);

    for(int i=1;i<=no_vert;++i)
    {
        if(indexx[i]==-1)
        {
            tarjan(i);
        }
    }
}

int main()
{
    freopen("Text/BOTTOM.txt","r",stdin);
    int st,en;

    while(true)
    {

        //scanf("%d",&no_vert);
        cin>>no_vert;
        //cout<<no_vert<<endl;


        if(no_vert==0)
        {
            break;
        }

        //scanf("%d",&no_edge);
        cin>>no_edge;
        //printf("EDGES\t%d\n",no_edge);

        for(int i=0;i<=no_vert;++i)
        {
            adjacency[i].clear();
        }

        for(int i=0;i<no_edge;++i)
        {
            //scanf("%d %d",&st,&en);
            cin>>st>>en;
            //printf("%d\t%d\n",st,en);
            adjacency[st].PB(en);
        }

        findSCC();

        for(int i=1;i<=no_vert;++i)
        {
            for(int j=0;j<adjacency[i].size();++j)
            {
                if(component[i]!=component[adjacency[i][j]])
                {
                    invalid_component[component[i]]=true;
                }
            }
        }

        int ct=0;
        //printf("DD\n");
        for(int i=1;i<=no_vert;++i)
        {
            if(!invalid_component[component[i]])
            {
                if(ct==0)
                {
                    printf("%d",i);
                }
                else
                {
                    printf(" %d",i);
                }
                ++ct;
            }
        }

        printf("\n");
    }
    return 0;
}


