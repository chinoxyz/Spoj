#include<bits/stdc++.h>
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

#define MAXN 10004
#define MAXM 100005
int e;
int to[MAXM],nxt[MAXM],firstt[MAXN];
int indeg[MAXN];
int n,m;
bool recheck,missing;
int ans[MAXN];
set<int> s[2];
set<int>::iterator sit;
int src,destt;
int ct;

inline void add_edge(int x,int y)
{
    ++indeg[y];
    to[e]=y;
    nxt[e]=firstt[x];
    firstt[x]=e++;
}


inline void solve()
{
    s[0].clear();
    s[1].clear();
    ct=0;
    src=0;
    destt=1;
    int i;


    for(i=1;i<=n;++i)
    {
        if(indeg[i]==0)
        {
            ++ct;
            ans[ct]=i;
            s[0].insert(i);
        }
    }


    if(s[0].size()==0)
    {
        recheck=1;
    }
    else
    {
        if(s[0].size()>1)
        {
            missing=1;
        }

        while(true)
        {
            if(s[src].size()==0)
            {
                break;
            }

            if(s[src].size()>1)
            {
                missing=1;
            }

            s[destt].clear();

            sit=s[src].begin();

            for(;sit!=s[src].end();++sit)
            {
                for(i=firstt[*sit];i!=-1;i=nxt[i])
                {
                    --indeg[to[i]];
                    if(indeg[to[i]]==0)
                    {
                        ++ct;
                        ans[ct]=to[i];
                        s[destt].insert(to[i]);
                    }
                }
            }
            swap(src,destt);

        }
    }

    if(ct<n)
    {
        recheck=1;
    }

}

void MAIN()
{
    int cases;
    int x,y,i;
    scanf("%d",&cases);

    while(cases--)
    {
        recheck=missing=0;
        e=0;
        MSET(firstt,-1);
        //MSET(ans,0);
        MSET(indeg,0);
        scanf("%d %d",&n,&m);

        for(i=0;i<m;++i)
        {
            scanf("%d %d",&x,&y);
            add_edge(x,y);
        }

        solve();

        if(recheck)
        {
            printf("recheck hints\n");
        }
        else if(missing)
        {
            printf("missing hints\n");
        }
        else
        {
            printf("%d",ans[1]);
            for(i=2;i<=n;++i)
            {
                printf(" %d",ans[i]);
            }
            printf("\n");
        }
    }
}

int main() {

	freopen("Text/GCPC11C.txt","r",stdin);

    MAIN();

	return 0;
}
