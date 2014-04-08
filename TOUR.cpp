#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <bitset>
#include<string>
#include <set>

using namespace std;
#define i64 long long

#define pii pair< int,int >
#define piii pair< pii,int >
#define ff first.first
#define fs first.second

#define EPS 1e-9

#define maxn 1002

int n,scc,ind,rea;
bitset<maxn> onstack;
bitset<maxn> reachable;
int indexx[maxn],lowlink[maxn],sccnum[maxn];
vector<int> adj[maxn];
vector<int> comps[maxn];
vector<int> cc;
stack<int> st;

void conn(int node)
{
    //printf("%d\n",node);
    int i,j,temp;

    indexx[node]=ind;
    lowlink[node]=ind;
    ++ind;
    st.push(node);
    onstack.set(node);

    for(i=0;i<adj[node].size();++i)
    {
        if(indexx[adj[node][i]]==0)
        {
            conn(adj[node][i]);
            lowlink[node]=min(lowlink[node],lowlink[adj[node][i]]);
        }
        else if(onstack.test(adj[node][i]))
        {
            lowlink[node]=min(lowlink[node],indexx[adj[node][i]]);
        }
    }

    if(lowlink[node]==indexx[node])
    {
        temp=st.top();

        while(temp!=node)
        {
            comps[scc].push_back(temp);
            sccnum[temp]=scc;
            st.pop();
            onstack.reset(temp);
            temp=st.top();
        }

        comps[scc].push_back(temp);
        sccnum[temp]=scc;
        st.pop();
        onstack.reset(temp);
        ++scc;
    }
}

void tarjan()
{
    int i,j;
    for(i=1;i<=n;++i)
    {
        if(indexx[i]==0)
        {
            conn(i);
        }
    }
}

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/TOUR.txt","r",stdin);
    int i,j,cases,x,y,k;

    scanf("%d",&cases);

    while(cases--)
    {
        while(!st.empty())
        {
            st.pop();
        }
        memset(indexx,0,sizeof(indexx));
        memset(lowlink,0,sizeof(lowlink));
        memset(sccnum,0,sizeof(sccnum));
        onstack.reset();
        reachable.reset();
        cc.clear();
        scc=0;
        ind=1;
        rea=0;

        scanf("%d",&n);
        for(i=1;i<=n;++i)
        {
            adj[i].clear();
            comps[i].clear();
        }

        for(i=1;i<=n;++i)
        {
            scanf("%d",&x);

            for(j=1;j<=x;++j)
            {
                scanf("%d",&y);
                adj[y].push_back(i);
            }
        }

        tarjan();

        if(scc==1)
        {
            printf("%d\n",n);
        }
        else
        {
            cc.push_back(scc-1);
            reachable.set(cc[0]);

            for(i=0;i<cc.size();++i)
            {
                for(j=0;j<comps[cc[i]].size();++j)
                {
                    for(k=0;k<adj[comps[cc[i]][j]].size();++k)
                    {
                        if(!reachable.test(sccnum[adj[comps[cc[i]][j]][k]]))
                        {
                            reachable.set(sccnum[adj[comps[cc[i]][j]][k]]);
                            cc.push_back(sccnum[adj[comps[cc[i]][j]][k]]);
                        }
                    }
                }
            }

            //printf("SCCCCCC%d\n",scc);

/*            for(i=0;i<scc;++i)
            {
                for(j=0;j<comps[i].size();++j)
                {
                    printf("CC%d ",comps[i][j]);
                }

                printf("\n");
            }
*/
            if(cc.size()==scc)
            {
                printf("%d\n",comps[scc-1].size());
            }
            else
            {
                printf("0\n");
            }
        }

    }


    return 0;
}

