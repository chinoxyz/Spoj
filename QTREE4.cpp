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

#define MAXN 100005
#define INF 999999999

int distt[MAXN],color[MAXN],sFather[MAXN],gp[MAXN],idx[MAXN],markk[MAXN];


class MY_PQ
{
public:

    struct data
    {
        int vall,node,mk;
        friend inline bool operator<(const data &a,const data &b)
        {
            return a.vall<b.vall;
        }
    };

    priority_queue<data> q;

    int top()
    {
        for(;!q.empty() && markk[q.top().node]!=q.top().mk;q.pop());

        return q.empty()? -INF :q.top().vall;
    }

    int nxt_top()
    {
        for(;!q.empty() && markk[q.top().node]!=q.top().mk;q.pop());

        if(q.empty())
        {
            return -INF;
        }

        data tmp=q.top();
        int ret=-INF;
        q.pop();

        for(;!q.empty() && markk[q.top().node]!=q.top().mk;q.pop());

        if(!q.empty())
        {
            ret=q.top().vall;
        }

        q.push(tmp);

        return ret;
    }

    void push(int vall,int node,int mk)
    {
        q.push((data){vall,node,mk});
    }
};

MY_PQ pq[MAXN];
priority_queue<PII > ans;


class SEG_TREE
{
public:

    struct NODE
    {
        int ml,mr,mx,l,r;

        NODE *lc,*rc;
    };

    typedef NODE* NODE_PTR;

    NODE_PTR head;

    void update(NODE_PTR &root)
    {
        root->ml=root->mr=pq[root->l].top();
        root->mx=-INF;

        root->mx=max(root->mx,pq[root->l].top()+pq[root->l].nxt_top());

        if(color[root->l])
        {
            root->mx=max(root->mx,pq[root->l].top());
            root->ml=max(root->ml,0);
            root->mr=max(root->mr,0);
            root->mx=max(root->mx,0);
        }
    }


    void build(NODE_PTR &root,int l,int r)
    {
        root->l=l;
        root->r=r;

        if(l==r)
        {
            update(root);
            return;
        }

        int midd=(l+r)>>1;

        root->lc=new(NODE);
        root->rc=new(NODE);

        build(root->lc,l,midd);
        build(root->rc,midd+1,r);

        root->ml=max(root->lc->ml,distt[midd+1]-distt[l]+root->rc->ml);
        root->mr=max(root->rc->mr,distt[r]-distt[midd]+root->lc->mr);
        root->mx=max(distt[midd+1]-distt[midd]+root->lc->mr+root->rc->ml,max(root->lc->mx,root->rc->mx));
    }


    void init(int l,int r)
    {
        head=new(NODE);
        build(head,l,r);
    }

    int ml()
    {
        return head->ml;
    }

    int mr()
    {
        return head->mr;
    }

    int mx()
    {
        return head->mx;
    }

    void modify(NODE_PTR &root,int p)
    {
        if(root->l==p && root->r==p)
        {
            update(root);
            return;
        }

        int midd=(root->l + root->r)>>1;
        if(p<=midd)
        {
            modify(root->lc,p);
        }
        else
        {
            modify(root->rc,p);
        }

        root->ml=max(root->lc->ml,distt[midd+1]-distt[root->l]+root->rc->ml);
        root->mr=max(root->rc->mr,distt[root->r]-distt[midd]+root->lc->mr);
        root->mx=max(distt[midd+1]-distt[midd]+root->lc->mr+root->rc->ml,max(root->lc->mx,root->rc->mx));
    }

    void modify(int l)
    {
        modify(head,l);
    }
};


class HL_DECOMPOSITION
{
public:

    struct EDGES
    {
        int nxt[MAXN<<1],to[MAXN<<1],vall[MAXN<<1],firstt[MAXN];
        int tot;

        void add_edge(int x,int y,int v)
        {
            ++tot;
            nxt[tot]=firstt[x];
            firstt[x]=tot;
            to[tot]=y;
            vall[tot]=v;
        }
    } e;


    struct data
    {
        int u,upper,pl,hl;
    };

    stack<data> s;
    SEG_TREE st[MAXN];

    int stCnt,tot;
    int father[MAXN],child_mx[MAXN],depth[MAXN],jump[MAXN],sz[MAXN],clr[MAXN],tail[MAXN];


    int N;


    void add_edge(int x,int y,int v)
    {
        e.add_edge(x,y,v);
    }


    void get_weight()
    {
        int q[MAXN],p1=0,p2=0;
        q[0]=1;

        for(;p1<=p2;++p1)
        {
            int u=q[p1];

            for(int pos=e.firstt[u];pos;pos=e.nxt[pos])
            {
                int v=e.to[pos];

                if(v!=father[u])
                {
                    father[v]=u;
                    q[++p2]=v;
                }
            }

            ++sz[u];
        }

        for(int i=N-1;i;--i)
        {
            int u=q[i];

            sz[father[u]]+=sz[u];

            if(sz[u]>sz[child_mx[father[u]]])
            {
                child_mx[father[u]]=u;
            }
        }
    }


    void create_hl(int u,int upper,int pl)
    {
        int curr[MAXN],vis[MAXN]={0};

        s.push((data){1,0,0,0});

        for(int i=1;i<=N;++i)
        {
            curr[i]=e.firstt[i];
        }

        while(!s.empty())
        {
            int u=s.top().u,upper=s.top().upper,pl=s.top().pl,hl=s.top().hl;
            s.pop();

            if(!hl)
            {
                depth[u]=pl;

                jump[u]=upper?upper:u;

                if(upper)
                {
                    gp[u]=gp[upper];
                }
                else
                {
                    gp[u]=++stCnt;
                }

                idx[u]=++tot;
                distt[tot]=pl;
                color[tot]=clr[u];
                sFather[tot]=idx[father[u]];
                tail[gp[u]]=tot;
                s.push((data){u,upper,pl,1});

                for(int pos=e.firstt[u];pos;pos=e.nxt[pos])
                {
                    int v=e.to[pos];

                    if(v!=father[u] && child_mx[u]==v)
                    {
                        s.push((data){v,jump[u],pl+e.vall[pos],0});
                        break;
                    }
                }
            }
            else if(hl==1)
            {
                if(!curr[u])
                {
                    if(!upper)
                    {
                        s.push((data){u,upper,pl,2});
                    }

                    continue;
                }

                s.push((data){u,upper,pl,1});


                for(;curr[u];curr[u]=e.nxt[curr[u]])
                {
                    int pos=curr[u];
                    int v=e.to[pos];

                    if(v!=father[u] && child_mx[u]!=v)
                    {
                        if(vis[v])
                        {
                            pq[idx[u]].push(st[gp[v]].ml()+e.vall[pos],v,0);
                            curr[u]=e.nxt[curr[u]];
                            break;
                        }
                        else
                        {
                            s.push((data){v,0,pl+e.vall[pos],0});
                            vis[v]=1;
                            break;
                        }
                    }
                }
            }

            else
            {
                st[gp[u]].init(idx[u],tail[gp[u]]);
                ans.push(PII(st[gp[u]].mx(),gp[u]));
            }
        }
    }



    void init()
    {
        for(int i=1;i<=N;++i)
        {
            clr[i]=1;
        }

        get_weight();
        create_hl(1,0,0);
    }


    void modify(int now)
    {
        clr[now]^=1;
        color[idx[now]]^=1;

        for(;now;now=father[now])
        {
            st[gp[now]].modify(idx[now]);
            now=jump[now];

            if(now!=1)
            {
                pq[idx[father[now]]].push(st[gp[now]].ml()+depth[now]-depth[father[now]],now,++markk[now]);
            }

            ans.push(PII(st[gp[now]].mx(),gp[now]));
        }
    }



    void print_mx()
    {
        for(;st[ans.top().second].mx()!=ans.top().first;ans.pop());

        if(ans.top().first<0)
        {
            printf("They have disappeared.\n");
        }
        else
        {
            printf("%d\n",ans.top().first);
        }
    }

} tree;

int main()
{
    freopen("Text/QTREE4.txt","r",stdin);

    int M;
    int x,y,v;

    scanf("%d",&tree.N);

    for(int i=1;i<tree.N;++i)
    {
        scanf("%d %d %d",&x,&y,&v);
        tree.add_edge(x,y,v);
        tree.add_edge(y,x,v);
    }

    scanf("%d",&M);
    tree.init();

    char buff[4];
    int ti;

    for(int i=1;i<=M;++i)
    {
        scanf("%s",buff);

        if(buff[0]=='A')
        {
            tree.print_mx();
        }
        else
        {
            scanf("%d",&ti);
            tree.modify(ti);
        }
    }


    return 0;
}
