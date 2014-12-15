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

#define MAXN 1<<18
#define INF 0x7f7f7f7f
char buff[2];

struct Treap
{
    int key,priority,maxx,sz;
    Treap *lc,*rc;

    void pullUp()
    {
        sz=1+lc->sz+rc->sz;
        maxx=max(key,max(lc->maxx,rc->maxx));
    }
};

Treap arr[MAXN];
Treap *root,*nil,*nxt=arr;

void pree()
{
    nxt->lc=nxt->rc=nil;
    nxt->key=nxt->maxx=-INF;
    nxt->sz=0;
    nxt->priority=-1;
    root=nil=nxt;
    ++nxt;
}


inline Treap *rotateR(Treap *p,Treap *c)
{
    p->lc=c->rc;
    c->rc=p;
    p->pullUp();
    c->pullUp();
    return c;
}

inline Treap *rotateL(Treap *p,Treap *c)
{
    p->rc=c->lc;
    c->lc=p;
    p->pullUp();
    c->pullUp();
    return c;
}


inline int query(Treap *node,int nl,int nr,int l,int r)
{
    if(node==nil || nl>=r || nr<=l)
    {
        return -INF;
    }

    if(l<=nl && nr<=r)
    {
        return node->maxx;
    }

    int ret=-INF;

    ret=max(ret,max(query(node->lc,nl,nl+node->lc->sz,l,r),query(node->rc,nl+node->lc->sz+1,nr,l,r)));

    if(nl+node->lc->sz>=l && nl+node->lc->sz<r)
    {
        ret=max(ret,node->key);
    }

    return ret;
}


inline Treap *insertt(Treap *node,int pos,int key)
{
    if(node==nil)
    {
        nxt->lc=nxt->rc=nil;
        nxt->key=nxt->maxx=key;
        nxt->sz=1;
        nxt->priority=rand();
        return nxt++;
    }

    if(node->lc->sz>=pos)
    {
        node->lc=insertt(node->lc,pos,key);
        if(node->lc->priority > node->priority)
        {
            node=rotateR(node,node->lc);
        }
    }
    else
    {
        node->rc=insertt(node->rc,pos-node->lc->sz-1,key);

        if(node->rc->priority > node->priority)
        {
            node=rotateL(node,node->rc);
        }
    }

    node->pullUp();
    return  node;
}



int main()
{
    freopen("Text/QMAX3VN.txt","r",stdin);

    pree();
    int x,y,n;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%s %d %d",buff,&x,&y);

        if(buff[0]=='A')
        {
			root=insertt(root,y-1,x);
        }
        else
        {
            printf("%d\n",query(root,0,root->sz,x-1,y));
        }
    }

    return 0;
}
