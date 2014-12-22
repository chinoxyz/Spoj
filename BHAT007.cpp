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

#define MAXN 111


char num1[MAXN], num2[MAXN];
int ans1[MAXN], ans2[MAXN], lenn1, lenn2;

void addd(int base, int *ans, int &k)
{
	int i, j, a, b, carry;
	for(i = lenn1-1, j = lenn2-1, carry = k = 0; i >= 0 || j >= 0 || carry; --i, --j, ++k)
	{
		a = i >= 0 ? num1[i]-'0' : 0;
		b = j >= 0 ? num2[j]-'0' : 0;
		ans[k] = (a + b + carry) % base;
		carry = (a + b + carry) / base;
	}

	while(k--)
	{
		if(ans[k])
		{
			break;
		}
	}
}

int main() {

	freopen("Text/BHAT007.txt","r",stdin);

	int cases, base1, base2, al1, al2;
	cin>>cases;

	while(cases--)
	{
		cin>>num1>>num2>>base1>>base2;
		lenn1 = strlen(num1);
		lenn2 = strlen(num2);
		addd(base1, ans1, al1);
		addd(base2, ans2, al2);
		if(al1 == al2 && !memcmp(ans1, ans2, al1*sizeof(int)))
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
