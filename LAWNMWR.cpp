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

#define MAXN 1009

#define MAXW 100
#define MAXH 75
const double EPS=1e-8;

int nx,ny;
double w;

double arr[MAXN];
bool poss;

void solve(int n,double r)
{
    double l=0;

    sort(arr,arr+n);
    double x,y;

    for(int i=0;i<n;++i)
    {
        x=arr[i]-w/2.0;
        y=arr[i]+w/2.0;

        if(x>l)
        {
            return;
        }

        l=max(l,y);
    }

    if(l>=r)
    {
        poss=1;
    }
}

void MAIN()
{
    int i;
    while(true)
    {
        cin>>nx>>ny>>w;
        if(nx==0 && ny==0 && w==0)
        {
            break;
        }
        poss=0;

        for(i=0;i<nx;++i)
        {
            cin>>arr[i];
        }

        solve(nx,75);

        for(i=0;i<ny;++i)
        {
            cin>>arr[i];
        }

        if(poss)
        {
            poss=0;
            solve(ny,100);
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

}


int main()
{
	freopen("Text/LAWNMWR.txt","r",stdin);

	MAIN();

	return 0;
}
