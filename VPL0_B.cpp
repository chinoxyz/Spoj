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

#define MAXN 10003
#define MAXM 1003

VI arr[MAXM];
int n,m;

void MAIN()
{
    int cases;
    scanf("%d",&cases);
    int i,j,sz;
    int ti;

    for(int t=1;t<=cases;++t)
    {
        scanf("%d %d",&n,&m);

        for(i=0;i<n;++i)
        {
            scanf("%d",&ti);
            arr[ti/m].PB(ti%m);
        }

        printf("Scenario #%d:\n\n",t);

        for(i=0;i<MAXM;++i)
        {
            sz=arr[i].size();
            if(sz)
            {
                sort(arr[i].begin(),arr[i].end());

                printf("%d |",i);

                for(j=0;j<sz;++j)
                {
                    printf(" %d",arr[i][j]);
                }
                printf("\n\n");

                arr[i].clear();
            }

        }
    }

}


int main()
{
	freopen("Text/VPL0_B.txt","r",stdin);

	MAIN();

	return 0;
}
