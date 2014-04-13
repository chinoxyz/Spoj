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

#define maxxy 10000003
#define maxr 50002
#define maxq 200008
#define maxn 100002


struct point
{
    int x,y,val;
};

struct query
{
    int x,y,p;
};

bool cquery(const query &a,const query &b)
{
    return a.y<b.y;
}

bool cpoint(const point &a,const point &b)
{
    return a.y<b.y;
}

int n,r,mr;
point pts[maxn];
query queries[maxq];
int ans[maxq];
int tree[maxxy];

void update(int idx,int val)
{
    //printf("UPDATE\t%d\t%d\n",idx,val);
    if(idx<=0)
    {
        return;
    }
    while(idx<=maxxy)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(int idx)
{
    //printf("READ\t%d\n",idx);
    if(idx<=0)
    {
        return 0;
    }

    int sum=0;

    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

void solve()
{
    int i,j,pq=0,pp=0;

    while(pp<n && pq<mr)
    {
        //printf("DD\n");
        while(pp<n && pts[pp].y<=queries[pq].y)
        {
            update(pts[pp].x,pts[pp].val);
            ++pp;
        }

        while(pq<mr && queries[pq].y==queries[pq+1].y)
        {
            ans[queries[pq].p]=read(queries[pq].x);
            ++pq;
        }

        ans[queries[pq].p]=read(queries[pq].x);
        ++pq;
    }
}

int main()
{
    freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/CCOST.txt","r",stdin);
    int i,j,cases,x,y,val,aa,bb,cc,dd,x1,y1,x2,y2;
    scanf("%d",&cases);

    while(cases--)
    {
        memset(tree,0,sizeof(tree));

        scanf("%d",&n);
        for(i=0;i<n;++i)
        {
            scanf("%d %d %d",&x,&y,&val);
            ++x;
            ++y;
            pts[i].x=x;
            pts[i].y=y;
            pts[i].val=val;
        }

        sort(pts,pts+n,cpoint);

/*        for(i=0;i<n;++i)
        {
            printf("%d %d %d\n",pts[i].x,pts[i].y,pts[i].val);
        }
*/
        scanf("%d",&r);
        mr=4*r;

        for(i=0;i<r;++i)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            ++x1;
            ++y1;
            ++x2;
            ++y2;

            aa=4*i;
            bb=aa+1;
            cc=bb+1;
            dd=cc+1;

            queries[aa].x=x1-1;
            queries[aa].y=y1-1;
            queries[aa].p=aa;

            queries[bb].x=x2;
            queries[bb].y=y1-1;
            queries[bb].p=bb;

            queries[cc].x=x1-1;
            queries[cc].y=y2;
            queries[cc].p=cc;

            queries[dd].x=x2;
            queries[dd].y=y2;
            queries[dd].p=dd;
        }

        sort(queries,queries+mr,cquery);

        solve();

        for(i=0;i<r;++i)
        {
            aa=4*i;
            printf("%d\n",ans[aa]-ans[aa+1]-ans[aa+2]+ans[aa+3]);
            //printf("%d %d %d %d\n",ans[aa],ans[aa+1],ans[aa+2],ans[aa+3]);
        }
    }

    return 0;
}

