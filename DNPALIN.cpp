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

bool checkk(char *str, int len)
{
	int ct = 0, i, j;
	for(i=0, j=len-1; i<j; i++, j--)
		if(str[i]!=str[j])
			ct++;
	if(ct==1 || (!ct && i==j)) return true;
	return false;
}


int main() {

	freopen("Text/DNPALIN.txt","r",stdin);

	char str[50], i, len;
	while(scanf("%s", str)==1)
	{
		if(!strcmp(str, "*END*")) break;
		len = strlen(str);
		for(i=1; i<len-1; i++)
			if(checkk(str, i) && checkk(&str[i], len-i))
				break;
		if(i<len-1) printf("%s is a double near palindrome.\n", str);
		else printf("%s is not a double near palindrome.\n", str);
	}


	return 0;
}
