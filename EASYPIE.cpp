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


typedef pair< string, int > psi;




int main()
{
    freopen("Text/EASYPIE.txt","r",stdin);

    int t, n, i, subtime, teamid, probid;
	int attt[10], timee[10], acce[10], tddd[64][10];
	map< string, int > mpp;
	map< string, int > :: iterator it;
	char team[8], prob[2], ver[2], solved[64][10];
	double atime, asub, acsub;

	scanf("%d", &t);
	while(t--) {

		mpp.clear();
		MSET(solved,0);
		MSET(tddd,0);
		MSET(timee,0);
		MSET(attt,0);
		MSET(acce,0);
		i = 0;

		scanf("%d", &n);
		while(n--) {
			scanf("%d %s %s %s", &subtime, team, prob, ver);

			it = mpp.find(team);
			if(it==mpp.end()) mpp.insert(psi(team, teamid = i++));
			else teamid = it->second;

			probid = prob[0]-'A';

			if(!solved[teamid][probid]) {
				tddd[teamid][probid]++;
				if(ver[0]=='A') {
					solved[teamid][probid] = 1;
					acce[probid]++;
					timee[probid] += subtime;
				}
			}
		}

		for(teamid = 0; teamid < i; teamid++)
			for(probid = 0; probid < 9; probid++)
				if(solved[teamid][probid])
					attt[probid] += tddd[teamid][probid];

		for(i = 0; i < 9; i++) {
			if(acce[i]) {
				acsub = acce[i];
				atime = timee[i]; atime /= acsub;
				asub = attt[i]; asub /= acsub;
				printf("%c %d %.2lf %.2lf\n", i+'A', acce[i], asub, atime);
			}
			else printf("%c 0\n", i+'A');
		}
	}
	return 0;


    return 0;
}
