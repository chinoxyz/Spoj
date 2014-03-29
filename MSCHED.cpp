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

int n;
int ans=0,maxt;

bitset<10003> timee;

struct cow
{
    int g,d;
} ;

bool comp(const cow &a,const cow &b)
{
    if(a.g==b.g)
    {
        return a.d>b.d;
    }
    return a.g>b.g;
}

cow a[10003];

int tree[40009];

void build(int node,int l,int r)
{
    if(l>r)
    {
        return;
    }
    if(l==r)
    {
        tree[node]=1;
        return;
    }

    int midd=(l+r)/2;
    int ll=2*node+1;
    int rr=2*(node+1);

    build(ll,l,midd);
    build(rr,midd+1,r);
    tree[node]=tree[ll]+tree[rr];
}

int gett(int node,int l,int r,int pos)
{
    if(l>r)
    {
        return -1;
    }
    if(tree[node]==0)
    {
        return -1;
    }


    if(l==r && (tree[node]==0 || l>pos))
    {
        return -1;
    }

    if(l==r && tree[node]==1 && l<=pos)
    {
        //cout<<"RET\t"<<l<<endl;
        tree[node]=0;
        return l;
    }

    int midd=(l+r)/2;
    int ll=2*node+1;
    int rr=2*(node+1);

    if(pos<=midd && tree[ll]<=0)
    {
        return -1;
    }

    if(pos>midd && tree[rr]<=0)
    {
        int x=gett(ll,l,midd,pos);
        tree[node]=tree[ll]+tree[rr];
        return x;
    }

    if(pos<=midd)
    {
        int x=gett(ll,l,midd,pos);
        tree[node]=tree[ll]+tree[rr];
        return x;
    }
    else
    {
        int y=gett(rr,midd+1,r,pos);
        tree[node]=tree[ll]+tree[rr];
        if(y==-1)
        {
            y=gett(ll,l,midd,pos);
            tree[node]=tree[ll]+tree[rr];
        }
        return y;
    }
}

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/MSCHED.txt","r",stdin);

    int i,j,cases,t1,t2;

    scanf("%d",&n);
    ans=0;
    memset(a,0,sizeof(a));
    memset(tree,0,sizeof(tree));
    maxt=0;


    for(i=0;i<n;++i)
    {
        scanf("%d %d",&t1,&t2);
        --t2;
        a[i].g=t1;
        a[i].d=t2;
        if(t2>maxt)
        {
            maxt=t2;
        }
    }

    sort(a,a+n,comp);
    build(0,0,maxt);

/*    for(i=0;i<n;++i)
    {
        cout<<a[i].g<<"\t"<<a[i].d<<endl;
    }
*/
    for(i=0;i<n;++i)
    {
        if((t1=gett(0,0,maxt,a[i].d))!=-1)
        {
            ans+=a[i].g;

        }
        //cout<<"ANS\t"<<t1<<"\t"<<ans<<endl;
    }

    printf("%d\n",ans);
    //cout<<maxt<<endl;

    return 0;
}

