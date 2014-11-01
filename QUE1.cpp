#include <bits/stdc++.h>

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

const int MAXN=10003;
const int MAXT=MAXN<<2;

int n;
PII arr[MAXN];
int ans[MAXN];
int tree[MAXT];

void buildd(int nodee,int l,int r)
{
    if(l==r)
    {
        tree[nodee]=1;
        return;
    }

    int midd=(l+r)>>1;
    int lc=nodee<<1;
    int rc=lc+1;

    buildd(lc,l,midd);
    buildd(rc,midd+1,r);

    tree[nodee]=tree[lc]+tree[rc];
}

int findd(int nodee,int l,int r,int v)
{
    if(l==r)
    {
        return l;
    }

    int midd=(l+r)>>1;
    int lc=nodee<<1;
    int rc=lc+1;

    if(tree[lc]>v)
    {
        return findd(lc,l,midd,v);
    }

    return findd(rc,midd+1,r,v-tree[lc]);
}

void removee(int nodee,int l,int r,int v)
{
    if(l==r)
    {
        tree[nodee]=0;
        return;
    }

    int midd=(l+r)>>1;
    int lc=nodee<<1;
    int rc=lc+1;

    if(v<=midd)
    {
        removee(lc,l,midd,v);
    }
    else
    {
        removee(rc,midd+1,r,v);
    }

    tree[nodee]=tree[lc]+tree[rc];
}


int main()
{
    freopen("Text/QUE2.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",&arr[i].first);
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",&arr[i].second);
        }

        sort(arr,arr+n);
        //MSET(tree,0);

        buildd(1,0,n-1);

        for(int i=0;i<n;++i)
        {
            //printf("%d\t%d\n",arr[i].first,arr[i].second);
            int ti=findd(1,0,n-1,arr[i].second);

            removee(1,0,n-1,ti);

            ans[ti]=arr[i].first;
        }

        for(int i=0;i<n;++i)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }



    return 0;
}

