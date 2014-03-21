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
int ans,l;
char a[200];

struct node
{
    int ct,st,en;
    struct node *ll;
    struct node *rr;
};


int gcd(int x,int y)
{
    int temp;

    if(x>y)
    {
        temp=x;
        x=y;
        y=temp;
    }

    while(x>0)
    {
        temp=y%x;
        y=x;
        x=temp;
    }

    return y;
}


int lcm(int x,int y)
{
    return (x*y)/gcd(x,y);
}

node *left(int st);
node *right(int st);

node *left(int st)
{
    node *nn=new node();
    nn->ct=1;
    nn->st=st;
    if(a[st+1]==']')
    {
        nn->ct=2;
        nn->en=st+1;
        nn->ll=NULL;
        nn->rr=NULL;
    }
    else
    {
        nn->ll=left(st+1);
        nn->rr=right(nn->ll->en+1);
        nn->ct=2*lcm(nn->ll->ct,nn->rr->ct);
        nn->en=nn->rr->en+1;
    }

    return nn;
}

node *right(int st)
{
    node *nn=new node();

    if(a[st]==']')
    {
        nn->ct=2;
        nn->st=st-1;
        nn->en=st-1;
        nn->ll=NULL;
        nn->rr=NULL;
    }
    else if(a[st+1]==']')
    {
        nn->ct=2;
        nn->st=st;
        nn->en=st+1;
        nn->ll=NULL;
        nn->rr=NULL;
    }
    else
    {
        nn->ct=1;
        nn->st=st;
        nn->ll=left(st+1);
        nn->rr=right(nn->ll->en+1);
        nn->ct=2*lcm(nn->ll->ct,nn->rr->ct);
        nn->en=nn->rr->en+1;
    }

    return nn;
}


void root()
{
    l=strlen(a);
    //cout<<a<<endl;
    if(l==0)
    {
        ans=1;
    }
    else if(l==2)
    {
        ans=2;
    }
    else
    {
        node *root=new node();
        root->ct=1;
        root->st=0;
        root->en=l-1;
        root->ll=left(1);
        root->rr=right(root->ll->en+1);
        root->ct=2*lcm(root->ll->ct,root->rr->ct);
        ans=root->ct;
    }
}

int main()
{
    //freopen("C:/Users/MINTOO/Desktop/Programs/Codeblocks/Spoj/Text/GNY07F.txt","r",stdin);

    int cases,i,j,k;
    //scanf("%d",&cases);
    cases=atoi(gets(a));

    for(k=1;k<=cases;++k)
    {
        ans=0;
        //scanf("%s",a);
        //cin>>a;
        gets(a);
        root();
        printf("%d %d\n",k,ans);
    }

    return 0;
}

