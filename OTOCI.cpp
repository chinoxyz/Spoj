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

#define MAXN 30010
#define MAXQ 300010


char querr[MAXQ][33];
int n,m,arr[MAXN],parentt[MAXN],bitt[MAXN<<3],x[MAXQ],y[MAXQ];
int q[MAXN],depthh[MAXN],prevv[MAXN],sz[MAXN],ct,idx[MAXN],nxt[MAXN],groupp[MAXN];
int en,st;

struct node
{
    int v;
    node *nxt;
};

node *first_edge[MAXN];
node buff[MAXN<<2];
node *tot=buff;


int findd(int u)
{
    int ret= ((parentt[u]==u)?u:(parentt[u]=findd(parentt[u])));

     //printf("FA\t%d\n",ret);

    return ret;
}


int query(int xx,int yy)
{
    int ret;
    ret=0;

    while(groupp[xx]!=groupp[yy])
    {
        int &ti=depthh[groupp[xx]]>depthh[groupp[yy]]?xx:yy;

        for(int i=idx[ti];i;i-=(i&-i))
        {
            ret+=bitt[i];
        }

        for(int i=idx[groupp[ti]]-1;i;i-=(i&-i))
        {
            ret-=bitt[i];
        }

        ti=prevv[groupp[ti]];
    }

    if(idx[xx]>idx[yy])
    {
        swap(xx,yy);
    }

    for(int i=idx[yy];i;i-=(i&-i))
    {
        ret+=bitt[i];
    }

    for(int i=idx[xx]-1;i;i-=(i&-i))
    {
        ret-=bitt[i];
    }

    //printf("Q\t%d\n",ret);

    return ret;
}


int main()
{
    freopen("Text/OTOCI.txt","r",stdin);

    st=en=0;

    scanf("%d",&n);
    int p1,p2,ti;

    for(int i=1;i<=n;++i)
    {
        scanf("%d",arr+i);
        parentt[i]=i;
    }

    scanf("%d",&m);


    for(int i=1;i<=m;++i)
    {
        scanf("%s",&querr[i]);
        scanf("%d %d",x+i,y+i);

        //printf("%s\t%d\t%d\n",querr[i],x[i],y[i]);


        if(querr[i][0]=='b' && findd(x[i])!=findd(y[i]))
        {
            ++tot;
            tot->v=x[i];
            tot->nxt=first_edge[y[i]];
            first_edge[y[i]]=tot;

            ++tot;
            tot->v=y[i];
            tot->nxt=first_edge[x[i]];
            first_edge[x[i]]=tot;

            parentt[findd(x[i])]=findd(y[i]);
        }
    }

    for(int i=1;i<=n;++i)
    {
        if(!depthh[i])
        {
            for(q[en++]=i,depthh[i]=1;st<en;++st)
            {
                for(node *curr=first_edge[q[st]];curr;curr=curr->nxt)
                {
                    if(depthh[curr->v])
                    {
                        continue;
                    }
                    depthh[curr->v]=depthh[q[st]]+1;
                    prevv[curr->v]=q[st];
                    q[en++]=curr->v;
                }
            }
        }
    }

    for(int i=en-1;i>=0;--i)
    {
        sz[prevv[q[i]]]+= (++sz[q[i]]);

        if(!nxt[prevv[q[i]]] || sz[q[i]]>sz[nxt[prevv[q[i]]]])
        {
            nxt[prevv[q[i]]]=q[i];
        }
    }

    for(int i=0;i<en;++i)
    {
        if(groupp[q[i]])
        {
            continue;
        }

        for(int j=q[i];j;j=nxt[j])
        {
            for(int k=(idx[j]=++ct);k<=n;k+=(k&-k))
            {
                bitt[k]+=arr[j];
            }

            groupp[j]=q[i];
        }
    }

    for(int i=1;i<=n;++i)
    {
        parentt[i]=i;
    }



    for(int i=1;i<=m;++i)
    {
        if(querr[i][0]=='b')
        {

            if(findd(x[i])!=findd(y[i]))
            {
                printf("yes\n");
                parentt[findd(x[i])]=findd(y[i]);
            }
            else
            {
                printf("no\n");
            }
        }

        if(querr[i][0]=='e')
        {


            if(findd(x[i])!=findd(y[i]))
            {
                printf("impossible\n");
            }
            else
            {
                printf("%d\n",query(x[i],y[i]));
            }
        }

        if(querr[i][0]=='p')
        {
            //ti=y[i]-arr[x[i]];
            for(int j=idx[x[i]];j<=n;j+=(j&-j))
            {
                bitt[j]+=y[i]-arr[x[i]];
            }
            arr[x[i]]=y[i];
        }
    }



    return 0;
}

