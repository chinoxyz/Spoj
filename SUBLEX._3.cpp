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


#define N 200015

struct SAM
{
    SAM *pre,*son[26];
    int len,cnt;
} *root,*tail,que[N],*b[N];


char str[N/2];
int son[N][26],cnt[N];
int tot=0;
int c[N];
char ch[N][26];


void add_char(int c)
{


    SAM *p=tail,*np=&que[tot++];
    np->len=tail->len+1;

    while(p && p->son[c]==NULL)
    {
        p->son[c]=np;
        p=p->pre;
    }

    if(p==NULL)
    {
        np->pre=root;
    }
    else
    {
        SAM *q=p->son[c];

        if(q->len==p->len+1)
        {
            np->pre=q;
        }
        else
        {
            SAM *nq=&que[tot++];
            *nq=*q;
            nq->len=p->len+1;
            np->pre=q->pre=nq;

            while(p && p->son[c]==q)
            {
                p->son[c]=nq;
                p=p->pre;
            }
        }
    }

    tail=np;
}


void solve(int k)
{
    int l=0;
    int curr=0;

    while(k)
    {
        for(int i=0;i<cnt[curr];++i)
        {
            if(k>que[son[curr][i]].cnt)
            {
                k-=que[son[curr][i]].cnt;
            }
            else
            {
                str[l++]=ch[curr][i];
                curr=son[curr][i];
                --k;
                break;

            }
        }
    }

    str[l]='\0';

    puts(str);
}


int main()
{
    freopen("Text/SUBLEX.txt","r",stdin);

    root=tail=&que[tot++];
    scanf("%s",str);
    int l=strlen(str);

    for(int i=0;str[i];i++) add_char(str[i]-'a');
    for(int i=0;i<tot;i++) c[que[i].len]++;
    for(int i=1;i<tot;i++) c[i]+=c[i-1];
    for(int i=0;i<tot;i++) b[--c[que[i].len]]=&que[i];
    for(int i=0;i<tot;i++) que[i].cnt=1;
    for(int i=tot-1;i>=0;i--)
    {
        SAM *p=b[i];
        for(int j=0;j<26;j++)
        {
            if(p->son[j])
            {
                int u=p-que,v=p->son[j]-que;
                son[u][cnt[u]]=v;
                ch[u][cnt[u]++]=j+'a';
                p->cnt+=p->son[j]->cnt;
            }
        }
    }
    int q,k;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&k);
        solve(k);
    }



    return 0;
}


