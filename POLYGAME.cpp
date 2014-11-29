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

int arr0[3],arr1[3];

int main()
{
    freopen("Text/POLYGAME.txt","r",stdin);

    int cases,n;

    scanf("%d",&cases);
    bool poss;

    while(cases--)
    {
        poss=0;
        scanf("%d",&n);
        scanf("%d %d %d",&arr0[0],&arr0[1],&arr0[2]);

        for(int i=0;i<n-3;++i)
        {
            scanf("%d %d %d",&arr1[0],&arr1[1],&arr1[2]);
        }

        sort(&arr0[0],&arr0[3]);

        arr1[0]=arr0[1]-arr0[0]-1;
        arr1[1]=arr0[2]-arr0[1]-1;
        arr1[2]=arr0[0]-arr0[2]+n-1;

        sort(&arr1[0],&arr1[3]);

        if( (arr1[0]==0 && arr1[1]==0) || (arr1[0]+arr1[1]+arr1[2])&1 )
        {
            poss=1;
        }

        if(poss)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }




    return 0;
}
