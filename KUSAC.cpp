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

int n,m;

int gcd(int a,int b)
{
    if(!b)
    {
        return a;
    }

    return gcd(b,a%b);
}

void MAIN()
{
    scanf("%d %d",&n,&m);
    printf("%d\n",m-gcd(n,m));
}


int main() {

	freopen("Text/KUSAC.txt","r",stdin);

    MAIN();

	return 0;
}
