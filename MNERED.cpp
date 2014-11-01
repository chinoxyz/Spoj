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


#define MAXN 101
int arr[MAXN][MAXN];
int n,k;


int calc(int topp,int bottom,int column)
{
    int ret=0;

    for(int i=topp;i<=bottom;++i)
    {
        ret+=arr[i][column];
    }

    return ret;
}

void solve()
{
    int ret=k;

    int s1;
    int s2;
    int ti;
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            s1=j-i+1;
            if(k%s1)
            {
                continue;
            }

            s2=k/s1;
            if(s2>n)
            {
                continue;
            }

            ti=0;

            for(int l=0;l<s2;++l)
            {
                ti+=calc(i,j,l);
            }

            ret=min(ret,k-ti);

            for(int l=s2;l<n;++l)
            {
                ti-=calc(i,j,l-s2);
                ti+=calc(i,j,l);

                ret=min(ret,k-ti);
            }
        }
    }

    printf("%d\n",ret);
}

int main()
{
    freopen("Text/MNERED.txt","r",stdin);

    scanf("%d %d",&n,&k);
    int x,y;
    for(int i=0;i<k;++i)
    {
        scanf("%d %d",&x,&y);
        arr[x-1][y-1]=1;
    }

    solve();


    return 0;
}

