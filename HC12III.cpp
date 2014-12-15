#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define i64 long long
#define MSET(x,y) memset((x),(y),sizeof(x))
#define VI vector<int>
#define PII pair< int,int >


#define MAXW 40002
#define MAXN 1000002

PII arr[MAXN];
map<int,int> mp;
map<int,int>::iterator mit;
set<int> s;
set<int>::iterator sit1,sit2,sit3;
int curr;
int n;
int h,q,w,p;
i64 ans;


int upperbound(int v)
{
    int st=0;
    int en=n;
    int midd;

    while(st<en)
    {

        midd=(st+en)>>1;
        if(arr[midd].first<=v)
        {
            st=midd+1;
        }
        else
        {
            en=midd;
        }
    }

    //printf("UUUU\t%d\t%d\n",st,en);

    return st;
}


int lowerbound(int v)
{
    int st=0;
    int en=n;
    int midd;

    while(st<en)
    {
        //printf("LLLL\t%d\t%d\n",st,en);
        midd=(st+en)>>1;
        if(arr[midd].first<v)
        {
            st=midd+1;
        }
        else
        {
            en=midd;
        }
    }

    return st;
}

int calc(int x,int y)
{
    return y-x-q;
}

void insertt(int v)
{
    int x,y;
    int ti;
    mit=mp.find(v);

    if(mit==mp.end())
    {
        s.insert(v);
        sit1=sit2=sit3=s.find(v);
        --sit1;
        ++sit3;
        x=(sit2==s.begin())?-1:*sit1;
        y=(sit3==s.end())?h:*sit3;
        ti=calc(x,y);
        if(ti>0)
        {
            curr-=ti;
        }

        ti=calc(x,v);
        if(ti>0)
        {
            curr+=ti;
        }

        ti=calc(v,y);
        if(ti>0)
        {
            curr+=ti;
        }
    }

    ++mp[v];
}


void deletee(int v)
{
    int x,y;
    int ti;
    mit=mp.find(v);

    if(mp[v]==1)
    {
        sit1=sit2=sit3=s.find(v);
        --sit1;
        ++sit3;
        x=(sit2==s.begin())?-1:*sit1;
        y=(sit3==s.end())?h:*sit3;
        ti=calc(x,y);
        if(ti>0)
        {
            curr+=ti;
        }

        ti=calc(x,v);
        if(ti>0)
        {
            curr-=ti;
        }

        ti=calc(v,y);
        if(ti>0)
        {
            curr-=ti;
        }
        s.erase(sit2);
        mp.erase(mit);
    }
    else
    {
        --mp[v];
    }
}






void solve()
{
    mp.clear();
    s.clear();
    int pos;
    int st,en;

    curr=h-q+1;
    pos=upperbound(p-1);

    for(int i=0;i<pos;++i)
    {
        insertt(arr[i].second);
    }

    for(int i=0;i<=w-p;++i)
    {

        ans+=curr;

        st=lowerbound(i);
        en=upperbound(i);

        for(int j=st;j<en;++j)
        {
            deletee(arr[j].second);
        }


        st=lowerbound(i+p);
        en=upperbound(i+p);

        for(int j=st;j<en;++j)
        {

            insertt(arr[j].second);
        }


    }


}


int main()
{
    freopen("Text/HC12III.txt","r",stdin);
    int x,y;
    int a,b,c,d;
    int i;
    int cases;
    scanf("%d",&cases);
    for(int t=1;t<=cases;++t)
    {
        ans=0;

        scanf("%d %d %d %d %d %d %d %d %d %d %d",&w,&h,&p,&q,&n,&x,&y,&a,&b,&c,&d);

        arr[0].first=x;
        arr[0].second=y;
        for(i=1;i<n;++i)
        {
            arr[i].first=(arr[i-1].first*a+arr[i-1].second*b+1)%w;
            arr[i].second=(arr[i-1].first*c+arr[i-1].second*d+1)%h;
        }
        sort(arr,arr+n);
        solve();
        printf("Case #%d: %lld\n",t,ans);
    }
    return 0;
}
