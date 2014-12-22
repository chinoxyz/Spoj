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
#include <cassert>
#include<cmath>


using namespace std;


#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

using namespace std;


map<string,int> Haab;
map<int,string> Tzolkin;

void pree()
{
	Haab["pop"] = 0; Haab["xul"] = 5; Haab["zac"] = 10;
	Haab["no"] = 1; Haab["yoxkin"] = 6; Haab["ceh"] = 11;
	Haab["zip"] = 2; Haab["mol"] = 7; Haab["mac"] = 12;
	Haab["zotz"] = 3; Haab["chen"] = 8; Haab["kankin"] = 13;
	Haab["tzec"] = 4; Haab["yax"] = 9; Haab["muan"] = 14;
	Haab["koyab"] = 16; Haab["uayet"] = 18;
	Haab["pax"] = 15; Haab["cumhu"] = 17;

	Tzolkin[0]="imix";Tzolkin[5]="cimi";Tzolkin[10]="chuen";Tzolkin[15]="cib";
	Tzolkin[1]="ik";Tzolkin[6]="manik";Tzolkin[11]="eb";Tzolkin[16]="caban";
	Tzolkin[2]="akbal";Tzolkin[7]="lamat";Tzolkin[12]="ben";Tzolkin[17]="eznab";
	Tzolkin[3]="kan";Tzolkin[8]="muluk";Tzolkin[13]="ix";Tzolkin[18]="canac";
	Tzolkin[4]="chicchan";Tzolkin[9]="ok";Tzolkin[14]="mem";Tzolkin[19]="ahau";
}

int main ()
{
	freopen("Text/MAYCA.txt","r",stdin);

    pree();
	int cases;
	scanf("%d",&cases);

	string sDay, month;
	int day, year;
	int numOfDays;

	printf("%d\n",cases);

	for (int i=0;i<cases;++i)
	{
		numOfDays=0;
		cin >> sDay >> month >> year;

		if (sDay.size() == 3)
        {
            day = 10*(sDay[0]-'0') + sDay[1]-'0';
        }
		else
        {
            day = sDay[0]-'0';
        }
		numOfDays = day + Haab[month]*20 + year*365;

		cout << numOfDays%13+1 << " " << Tzolkin[numOfDays%20] << " " << numOfDays/260 << endl;
	}
}
