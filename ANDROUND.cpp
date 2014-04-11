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

#define maxn 22002
#define maxt 4*maxn

int tree[maxt];
int a[maxn];
int x,y,n,k;

void buildd(int node,int ll,int rr)
{
    if(ll>rr)
    {
        return;
    }
    if(ll==rr)
    {
        tree[node]=a[ll];
        return;
    }
    int midd=(ll+rr)/2;
    int l=2*node+1;
    int r=l+1;
    buildd(l,ll,midd);
    buildd(r,midd+1,rr);
    tree[node]=tree[l]&tree[r];
}

int query(int node,int ll,int rr)
{
    if(ll>rr || ll>y || rr<x)
    {
        return -1;
    }

    if(ll>=x && rr<=y)
    {
        return tree[node];
    }

    int midd=(ll+rr)/2;
    int l=2*node+1;
    int r=l+1;
    int p=query(l,ll,midd);
    int q=query(r,midd+1,rr);
    return p&q;
}

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/ANDROUND.txt","r",stdin);
    int i,j,cases,res;

    scanf("%d",&cases);

    while(cases--)
    {
        res=-1;
        memset(tree,0,sizeof(tree));
        scanf("%d %d",&n,&k);
        for(i=0;i<n;++i)
        {
            scanf("%d",a+i);
        }
        buildd(0,0,n-1);

        if(k>=(n/2))
        {
            printf("%d",tree[0]);
            for(i=1;i<n;++i)
            {
                printf(" %d",tree[0]);
            }
            printf("\n");
        }
        else
        {
            //res&=a[0];
            x=0;
            y=k;
            res&=query(0,0,n-1);

            x=n-k;
            y=n-1;
            res&=query(0,0,n-1);
            printf("%d",res);

            for(i=1;i<n;++i)
            {
                res=-1;
                //res&=a[i];
                if(i-k<0)
                {
                    x=n+i-k;
                    y=n-1;
                    res&=query(0,0,n-1);
                    x=0;
                    y=i+k;
                    res&=query(0,0,n-1);
                }
                else if(i+k>=n)
                {
                    x=i-k;
                    y=n-1;
                    res&=query(0,0,n-1);
                    x=0;
                    y=i+k-n;
                    res&=query(0,0,n-1);
                }
                else
                {
                    x=i-k;
                    y=i+k;
                    res&=query(0,0,n-1);
                }

                printf(" %d",res);
            }

            printf("\n");
        }
    }

    return 0;
}

