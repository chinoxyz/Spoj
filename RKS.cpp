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


#define MAXN 1001
int arr[MAXN];
int b[MAXN];
set<int> st;
int ct=0;
int n,c;
PII cc[MAXN];
map<int,int> mp;


int main()
{
    freopen("Text/RKS.txt","r",stdin);

    scanf("%d %d",&n,&c);

    for(int i=0;i<n;++i)
    {
        scanf("%d",arr+i);
        //printf("%d\n",arr[i]);
        if(!mp[arr[i]])
        {
            b[++ct]=arr[i];
            mp[arr[i]]=ct;
        }

        --cc[mp[arr[i]]].first;
        cc[mp[arr[i]]].second=mp[arr[i]];
    }

    sort(cc+1,cc+ct+1);

    int ss=0;
    for(int i=1;i<=ct;++i)
    {
        for(int j=0;j<(-cc[i].first);++j)
        {
            if(ss)
            {
                printf(" ");
            }
            printf("%d",b[cc[i].second]);
            ++ss;
        }
    }
    printf("\n");


    return 0;
}

