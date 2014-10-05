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


#define MAXH 50
#define MAXW 250

char board[MAXH][MAXW];




int main()
{
    freopen("Text/QCJ1.txt","r",stdin);

    int i = 0, h, w = 0, prevv=-2, tot=0, steps=0, len;
	VPII walk;
	while(gets(board[i])) i++;
	h = i-1;
	len = strlen(board[i-1]);
	while(w<len)
	{
		if(board[h][w]=='/')
		{
			if(prevv!=1)
			{
				walk.push_back(pair<char,int>(prevv,steps));
				steps = 0;
			}
			steps++;
			prevv = 1;
			w++;
			tot++;
		}
		else if(board[h][w]=='_')
		{
			if(prevv!=0)
			{
				walk.push_back(pair<char,int>(prevv,steps));
				steps = 0;
			}
			steps++;
			prevv = 0;
			w++;
			tot++;
		}
		else if(board[h][w]=='\\')
		{
			if(prevv!=-1)
			{
				walk.push_back(pair<char,int>(prevv,steps));
				steps = 0;
			}
			steps++;
			prevv = -1;
			w++;
			tot++;
		}
		else
		{
			if(prevv==-1)
			{
				if(h == i) break;
				else h++;
			}
			else if(prevv==0)
			{
				h++;
			}
			else if(prevv==1)
			{
				h--;
			}
		}
	}
	walk.push_back(pair<char,int>(prevv,steps));
	printf("Total Walk Distance = %d\n", tot);
	for(i=0; i<walk.size(); i++)
	{
		if(walk[i].first==-1) printf("Down %d steps\n", walk[i].second);
		else if(walk[i].first==0) printf("Walk %d steps\n", walk[i].second);
		else if(walk[i].first==1) printf("Up %d steps\n", walk[i].second);
	}

    return 0;
}
