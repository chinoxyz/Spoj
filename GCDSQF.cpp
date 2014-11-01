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

#define MAXN 1004
char a[MAXN];
char b[MAXN];
int la,lb;
char ans[MAXN];


int main()
{
    freopen("Text/GCDSQF.txt","r",stdin);

    int mx;

    int cases;
    int mn;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%s %s",a,b);
        la=strlen(a);
        lb=strlen(b);
        mn=min(la,lb);
        mx=-1;

        for(int i=0;i<mn;++i)
        {
            ans[i]='0'+(a[i]>'0' && b[i]>'0');
            if(ans[i]=='1')
            {
                mx=i;
            }
        }
        ans[mx+1]=0;


        if(mx==-1)
        {
            printf("relatively prime\n");
        }
        else
        {
            printf("%s\n",ans);
        }
    }


    return 0;
}

