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



int main() {

	freopen("Text/EDGE.txt","r",stdin);

	char strr[250];

	  int x, y;
	  int i;
	  char dirr;

	  while(scanf("%s", strr) != EOF) {
		x = 310;
		y = 420;
		dirr = 'r';

		printf("300 420 moveto\n");
		printf("310 420 lineto\n");
		for(i = 0; i < strlen(strr); ++i)
		{
		  if(strr[i] == 'A')
		  {
			switch(dirr)
			{
				case 'r': dirr = 'd'; y -= 10; break;
				case 'l': dirr = 't'; y += 10; break;
				case 't': dirr = 'r'; x += 10; break;
				case 'd': dirr = 'l'; x -= 10;	break;
			}
		  }
		  else if(strr[i] == 'V')
		  {
			switch(dirr)
			{
				case 'r': dirr = 't'; y += 10; break;
				case 'l': dirr = 'd'; y -= 10; break;
				case 't': dirr = 'l'; x -= 10; break;
				case 'd': dirr = 'r'; x += 10; break;

			}
		  }

		  printf("%d %d lineto\n", x, y);
		}

		printf("stroke\n");
		printf("showpage\n");
	  }

	return 0;
}
