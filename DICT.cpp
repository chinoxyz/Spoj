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

#define MAXN 25005
#define MAXC 26
VI ans;
set<string> als;
int n;
int m;
int rn;

string tarr[MAXN];

struct trie
{
    VI arr;
    trie *nxt[MAXC];
    bool sorted;
};

trie *root;

inline void init(trie * &ti)
{
    ti=new trie;
    for(int i=0;i<MAXC;++i)
    {
        ti->nxt[i]=NULL;
    }
    ti->sorted=false;

    ti->arr.clear();
}


inline bool cmp(const int x,const int y)
{
    return tarr[x]<tarr[y];
}

inline void insertt(string s,int pos)
{
    trie *prs=root;
    trie *ti;

    int lenn=s.length();
    int ch;
    --lenn;

    for(int i=0;i<lenn;++i)
    {
        ch=s[i]-'a';

        if(prs->nxt[ch]==NULL)
        {
            init(ti);
            prs->nxt[ch]=ti;
        }
        prs=prs->nxt[ch];

        //if(i<lenn-1)
        {
            prs->arr.PB(pos);
        }
    }
}


inline void solve(string s)
{
    trie *ti;
    int lenn=s.size();
    ti=root;
    int ch;

    for(int i=0;i<lenn;++i)
    {
        ch=s[i]-'a';
        if(ch<0 || ch>=MAXC)
        {
            return;
        }
        ti=ti->nxt[ch];
        if(!ti)
        {
            return;
        }
    }

    if(ti)
    {
        if(!ti->sorted)
        {
            sort(ti->arr.begin(),ti->arr.end(),cmp);
            ti->sorted=true;
        }

        ans=ti->arr;
    }
}





int main()
{
    freopen("Text/DICT.txt","r",stdin);

    scanf("%d",&n);
    rn=0;
    string s;

    init(root);
    als.clear();

    for(int i=0;i<n;++i)
    {
        cin>>s;
        if(als.find(s)==als.end())
        {
            als.insert(s);
            insertt(s,rn);
            tarr[rn]=s;
            ++rn;
        }
    }

    scanf("%d",&m);

    for(int i=1;i<=m;++i)
    {
        ans.clear();
        cin>>s;
        solve(s);

        printf("Case #%d:\n",i);
        if(ans.size()==0)
        {
            printf("No match.\n");
        }
        else
        {
            for(int j=0;j<ans.size();++j)
            {
                cout<<tarr[ans[j]]<<endl;
            }
        }

    }





    return 0;
}
