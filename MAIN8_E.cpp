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

#define MAXN 20005
#define MAXM 33
#define INF 99999999

char a[MAXN],b[MAXN];

VI arr[MAXM];
int prevv[MAXM];

int ans;
int la,lb;
int st,en;

void init()
{
    for(int i=0;i<MAXM;++i)
    {
        arr[i].clear();
    }
    ans=INF;
}

bool tryy(int l,int pos)
{
    if(pos>=lb)
    {
        en=l;
        return 1;
    }

    VI::iterator it;
    it=upper_bound(arr[b[pos]-'a'].begin(),arr[b[pos]-'a'].end(),l);

    if(it!=arr[b[pos]-'a'].end())
    {
        return tryy(*it,pos+1);
    }

    return 0;
}

void solve()
{
    la=strlen(a);
    lb=strlen(b);

    for(int i=0;i<la;++i)
    {
        arr[a[i]-'a'].PB(i);
    }

    for(int i=0;i<arr[b[0]-'a'].size();++i)
    {
        en=INF;
        st=arr[b[0]-'a'][i];
        tryy(st,1);
        if(en<INF)
        {
            ans=min(ans,en-st+1);
        }
    }
}

void MAIN()
{
    int cases;
    scanf("%d",&cases);

    while(cases--)
    {
        init();
        scanf("%s %s",a,b);

        solve();
        if(ans==INF)
        {
            ans=-1;
        }

        printf("%d\n",ans);
    }

}


int main() {

	freopen("Text/MAIN8_E.txt","r",stdin);

    MAIN();

	return 0;
}
