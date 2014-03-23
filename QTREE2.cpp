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

using namespace std;

#define i64 long long
#define maxn 10100
#define maxc 100000
#define maxlogn 15

char buff[10];
int n,logn;

int par[maxn];
int level[maxn];
vector<int> neigh[maxn];
vector<int> dist[maxn];
int lpar[maxn][maxlogn];
bitset<maxn> visited;
int pardist[maxn];

void setlpar(int node)
{
    int tnode=node;
    int i;
    lpar[node][0]=par[node];

    for(i=1;i<maxlogn;++i)
    {
        if(((1<<i)-1)>=level[node])
        {
            break;
        }

        lpar[node][i]=lpar[lpar[node][i-1]][i-1];
    }
}


void precomp(int node)
{
    if(n==1)
    {
        return;
    }
    visited.set(node);
    int i,j;

    for(i=0;i<neigh[node].size();++i)
    {
        if(!visited.test(neigh[node][i]))
        {
            par[neigh[node][i]]=node;
            pardist[neigh[node][i]]=dist[node][i];
            level[neigh[node][i]]=level[node]+1;
            setlpar(neigh[node][i]);
            precomp(neigh[node][i]);
        }
    }
}


int lca(int a,int b)
{
    int ret=1;
    int ldiff=0;
    int logldiff,i;
    if(level[a]>level[b])
    {
        ldiff=level[a]-level[b];
        logldiff=log2(ldiff);

        while(ldiff!=0)
        {
            a=lpar[a][logldiff];
            ldiff=level[a]-level[b];
            if(ldiff!=0)
            {
               logldiff=log2(ldiff);
            }
        }
    }
    else if(level[a]<level[b])
    {
        ldiff=level[b]-level[a];
        logldiff=log2(ldiff);

        while(ldiff!=0)
        {
            b=lpar[b][logldiff];

            ldiff=level[b]-level[a];
            if(ldiff!=0)
            {
               logldiff=log2(ldiff);
            }
        }
    }


    if(level[a]==0)
    {
        return a;
    }

    if(a==b)
    {
        return a;
    }

    logldiff=log2(level[a]);

    for(i=logldiff;i>=0;--i)
    {
        if(lpar[a][i]!=0 && lpar[a][i]!=lpar[b][i])
        {
            a=lpar[a][i];
            b=lpar[b][i];
        }
    }

    if(a!=1)
    {
        ret=par[a];
    }
    else
    {
        ret=a;
    }

    return ret;
}



int distt(int a,int b)
{
    if(n==1)
    {
        return 0;
    }

    int x=lca(a,b);
    int ret=0;
    while(a!=0 && a!=x)
    {
        ret+=pardist[a];
        a=par[a];
    }

    while(b!=0 && b!=x)
    {
        ret+=pardist[b];
        b=par[b];
    }


    return ret;
}


int kth(int a,int b,int k)
{
    if(n==1)
    {
        return 1;
    }

    if(k==1)
    {
        return a;
    }

    int ret;
    int x=lca(a,b);
    int ldiff,i;

    //if(k>(-(2*level[x]-level[a]-level[b]-1)))
    //{
    //    ret=-1;
    //}
    //else
    //{

        if(k<=level[a]-level[x]+1)
        {
            --k;
            ldiff=log2(k);
            for(i=ldiff;i>=0;--i)
            {
                if(k==0)
                {
                    break;
                }

                if(k>=(1<<i))
                {
                    a=lpar[a][i];
                    k=k-(1<<i);
                }
            }

            ret=a;
        }
        else
        {

            k=k-(level[a]-level[x]);
            k=level[b]-level[x]-k+2;

            --k;

            if(k==0)
            {
                return b;
            }

            ldiff=log2(k);
            for(i=ldiff;i>=0;--i)
            {
                if(k==0)
                {
                    break;
                }

                if(k>=(1<<i))
                {
                    b=lpar[b][i];
                    k=k-(1<<i);
                }
            }

            ret=b;
        }
    //}

    return ret;

}



int main()
{
    //freopen("C:/Users/MINTOO/Desktop/Programs/Codeblocks/Spoj/Text/QTREE2.txt","r",stdin);

    int cases,i,j,k,a,b;
    int c;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);

        memset(par,0,sizeof(par));
        memset(level,0,sizeof(level));
        memset(lpar,0,sizeof(lpar));
        memset(pardist,0,sizeof(pardist));


        for(i=1;i<=n;++i)
        {
           neigh[i].clear();
           dist[i].clear();
        }

        for(i=0;i<n-1;++i)
        {
            scanf("%d %d %d",&a,&b,&c);
            neigh[a].push_back(b);
            neigh[b].push_back(a);

            dist[a].push_back(c);
            dist[b].push_back(c);
        }

        visited.reset();
        precomp(1);


        while (scanf("%s",buff),buff[1] != 'O')
        {
            if(!strcmp(buff,"DIST"))
            {
                scanf("%d %d",&a,&b);
                printf("%d\n",distt(a,b));
            }
            else
            {
                scanf("%d %d %d",&a,&b,&k);
                printf("%d\n",kth(a,b,k));
            }
        }

        if(cases)
        {
            printf("\n");
        }
    }


    return 0;
}

