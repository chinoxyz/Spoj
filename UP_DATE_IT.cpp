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
#include <string>
#include <set>
#include <queue>

using namespace std;
#define i64 long long

#define maxn 10002

int u,q,x,y,val,n;

int tree[maxn];

int read(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=tree[idx];
        idx-=idx&-idx;
    }

    return ret;
}

int update(int idx,int val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=idx&-idx;
    }
}

int main()
{
    //printf("DD");

    //freopen("C:/Users/Deepak/Desktop/Deepak/Programs/Spoj/Text/UPDATEIT.txt","r",stdin);
    int cases,i,j;

    scanf("%d",&cases);
    //printf("%d\n",cases);

    while(cases--)
    {
       memset(tree,0,sizeof(tree));
       scanf("%d %d",&n,&u);
       for(i=0;i<u;++i)
       {
           scanf("%d %d %d",&x,&y,&val);
           //printf("%d %d %d\n",x,y,val);
           ++x;
           ++y;
           update(x,val);
           update(y+1,-val);
       }

       scanf("%d",&q);
       for(i=0;i<q;++i)
       {
           scanf("%d",&x);
           ++x;
           printf("%d\n",read(x));
       }
    }
    return 0;
}

