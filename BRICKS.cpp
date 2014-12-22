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

#define MAXN 100005
const i64 MODD=1LL<<32;
#define MAXM 33
int n,m;
int arr1[MAXN],arr2[MAXN];
char buff1[MAXN],buff2[MAXN];

int mp[MAXM][MAXM];
VI ct[MAXM];
bool poss;
VI::iterator it;
i64 ans;
int tree[MAXN];
int pos[MAXM];
int pickk[MAXN];
int vis[MAXN];


void init()
{
    poss=1;
    MSET(mp,0);
    for(int i=0;i<MAXM;++i)
    {
        ct[i].clear();
    }
    ans=0;
    MSET(tree,0);
    MSET(pos,0);
    MSET(pickk,0);
    MSET(vis,0);
}

int read(int idx)
{
    int ret=0;

    while(idx>0)
    {
        ret+=tree[idx];
        idx-=(idx&-idx);
    }

    return ret;
}

void update(int idx,int val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}


void dell(int pos)
{
    int gp=arr1[pos];

    it=lower_bound(ct[gp].begin(),ct[gp].end(),pos);
    ct[gp].erase(it);
}

void checkk(int curr,int l,int r)
{
    for(int i=0;i<MAXM;++i)
    {
        if(ct[i].size()==0)
        {
            continue;
        }

        it=lower_bound(ct[i].begin(),ct[i].end(),l);

        if(it==ct[i].end())
        {
            continue;
        }

        if(*it<=r)
        {
            if(mp[i][curr]==0)
            {
                poss=0;
                return;
            }
        }
    }
}

void solve()
{
    int i;
    int ti,l,r;
    int curr;

    for(i=1;i<=n;++i)
    {
        if(pickk[i]<=i)
        {
            ti=read(n)-read(pickk[i]);
            if(ti!=i-pickk[i])
            {
                l=i-ti;
                r=pickk[i]-1;
                curr=arr1[pickk[i]];
                checkk(curr,l,r);
                if(!poss)
                {
                    return;
                }

                ans+=r-l+1;
            }
        }
        else
        {
            ti=read(n)-read(pickk[i]);
            ans+=pickk[i]-i+ti;

            ti=read(n)-read(i-1);
            l=i-ti;
            r=pickk[i]-1;
            curr=arr1[pickk[i]];

            checkk(curr,l,r);
            if(!poss)
            {
                return;
            }

        }


        dell(pickk[i]);
        vis[pickk[i]]=1;
        update(pickk[i],1);
    }
}



void MAIN()
{
    int cases;
    scanf("%d",&cases);
    int i;

    while(cases--)
    {
        init();
        scanf("%s %s",buff1,buff2);
        n=strlen(buff1);

        for(i=0;i<n;++i)
        {
            arr1[i+1]=buff1[i]-'a';
            arr2[i+1]=buff2[i]-'a';
            ct[arr1[i+1]].PB(i+1);
        }

        for(i=1;i<=n;++i)
        {
            if(pos[arr2[i]]>=ct[arr2[i]].size())
            {
                poss=0;
                break;
            }

            pickk[i]=ct[arr2[i]][pos[arr2[i]]];

            ++pos[arr2[i]];
        }

        scanf("%d",&m);

        for(i=0;i<m;++i)
        {
            scanf("%s",buff1);
            mp[buff1[0]-'a'][buff1[1]-'a']=1;
            mp[buff1[1]-'a'][buff1[0]-'a']=1;
        }


        if(poss)
        {
            solve();
        }


        if(!poss)
        {
            ans=-1;
        }

        printf("%lld\n",ans);
    }
}


int main() {

	freopen("Text/BRICKS.txt","r",stdin);

    MAIN();

	return 0;
}
