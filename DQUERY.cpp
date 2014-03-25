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

#define maxn 30001
#define maxq 200001
#define maxx 1000001

struct quer
{
    int num,l,r;
};

bool compp(const quer &a,const quer &b)
{
    if(a.r<b.r)
    {
        return true;
    }

    if(a.r>b.r)
    {
        return false;
    }

    if(a.l<b.l)
    {
        return true;
    }

    if(a.l>b.l)
    {
        return false;
    }

    return (a.num<b.num);
}

int n,l,r,tree[maxn],ans[maxq],ab[maxn],q;
int curr[maxx],cl,cr,cp,lastt=0;

bitset<maxn> a;

quer queries[maxq];

void update(int pos,int num)
{
    while(pos<=n)
    {
        tree[pos]+=num;
        pos+=(pos&(-pos));
    }
}

int read(int left,int right)
{
    int sum=0;

    while(right>0)
    {
        sum+=tree[right];
        right-=right&(-right);
    }

    --left;

    while(left>0)
    {
        sum-=tree[left];
        left-=left&(-left);
    }

    return sum;
}


void setans()
{
    int i,j;
    int end=1;

    for(i=1;i<=n;++i)
    {
        if(!curr[ab[i]])
        {
            curr[ab[i]]=i;
            a.set(i);
            update(i,1);
        }
        else
        {
            update(curr[ab[i]],-1);
            a.reset(curr[ab[i]]);
            curr[ab[i]]=i;
            a.set(i);
            update(i,1);
        }

        if(i==queries[end].r)
        {
            while(end<=q && queries[end].r==i)
            {
                ans[queries[end].num]=read(queries[end].l,queries[end].r);
                ++end;
            }
        }
    }



}

int main()
{
    //freopen("C:/Users/MINTOO/Desktop/Programs/Codeblocks/Spoj/Text/DQUERY.txt","r",stdin);

    int i,j,temp;
    scanf("%d",&n);

    for(i=1;i<=n;++i)
    {
        scanf("%d",&temp);
        ab[i]=temp;
    }

    //build();
    scanf("%d",&q);

    for(i=1;i<=q;++i)
    {
        scanf("%d %d",&l,&r);
        queries[i].l=l;
        queries[i].num=i;
        queries[i].r=r;
    }

    sort(queries+1,queries+q+1,compp);

    setans();

    for(i=1;i<=q;++i)
    {
        printf("%d\n",ans[i]);
    }

    return 0;
}

