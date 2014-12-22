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

#define MAXN 1000008

int q,p,f,a,b;
char buff[222];
int n;
i64 tree[MAXN];

i64 read(int idx)
{
    i64 ret=0;

    while(idx)
    {
        ret+=tree[idx];
        idx-=(idx&-idx);
    }

    return ret;
}

void update(int idx,i64 v)
{
    while(idx<=n)
    {
        tree[idx]+=v;
        idx+=(idx&-idx);
    }
}

void MAIN()
{
    scanf("%d %d",&n,&q);

    while(q--)
    {
        scanf("%s %d %d",buff,&a,&b);
        //printf("%s %d %d\n",buff,a,b);

        if(buff[0]=='f')
        {
            printf("%lld\n",read(b)-read(a-1));
        }
        else
        {
            update(a,b);
        }
    }
}

int main() {

	freopen("Text/AKVQLD03.txt","r",stdin);

    MAIN();

	return 0;
}
