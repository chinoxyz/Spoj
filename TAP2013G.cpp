#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>


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



int main()
{
    freopen("Text/TAP2013G.txt","r",stdin);

    int n;
    int j=0,c=0,i;
	scanf("%d",&n);
	int a[100005],b[100005];

	for(i=0;i<n;++i)
	{
        scanf("%d",&a[i]);
	}

	 for(i=0;i<n;++i)
	 {
        scanf("%d",&b[i]);
	 }

	sort(a,a+n);
	sort(b,b+n);

    i=0,j=0;
	while(i<n&&j<n)
    {
		if(a[i]<b[j])
		{
			 c++;
			 i++;
			 j++;
        }
		else
		{
            j++;
		}
    }
   printf("%d",c);
}
