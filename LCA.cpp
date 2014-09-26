#include<cstdio>
#include<queue>
#include<vector>
#define debug printf("DEBUG: On Line #: %d\n",__LINE__);
using namespace std;
int main()
{
    freopen("Text/LCA.txt","r",stdin);

    vector<int> graph[1001];
    int z=0,t;
    scanf("%d",&t);
    while((z++)<t)
    {
        int n,i,j,k,q;
        scanf("%d",&n);

        for (i=0; i<n; i++)
            graph[i].clear();
        for (i=1; i<=n; i++)
        {
            int m,v;
            scanf("%d",&m);
            for (j=0; j<m; j++)
            {
                scanf("%d",&v);
                graph[v].push_back(i);
            }
        }
        scanf("%d",&q);
        printf("Case %d:\n",z);
        for (i=0; i<q; i++)
        {
            int v,w,mark[1001]= {0};
            scanf("%d%d",&v,&w);

            while(graph[v].size()!=0)
            {
                mark[v]=1;
                v=graph[v][0];
            }
            while(mark[w]==0 && graph[w].size()!=0)
            {
                w=graph[w][0];
            }
            printf("%d\n",w);
        }
    }
    return 0;
}
