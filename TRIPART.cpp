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


#define EPS 1e-8

struct Triangle
{
	LD l1;
	LD l2;
	Triangle(){}
	Triangle(LD a,LD b,LD c)
	{
		if (a>b)
		{
			swap(a,b);
		}
		if (b>c)
		{
			swap(b,c);
		}
		if (a>b)
		{
			swap(a,b);
		}
		l1=b/a;
		l2=c/a;
	}
};

bool equall(LD x,LD y)
{
	return (x>=y && x-y<EPS || y>=x && y-x<EPS);
}

bool beloww(LD x,LD y)
{
	return !equall(x,y)&&x<y;
}

bool operator<(Triangle t1,Triangle t2)
{
	if (beloww(t1.l1,t2.l1))
	{
		return true;
	}
	else if (equall(t1.l1,t2.l1))
	{
		if (beloww(t1.l2,t2.l2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}
int main()
{
	freopen("Text/TRIPART.txt","r",stdin);

	int cases;
	scanf("%d",&cases);
	LD a,b,c;
	set<Triangle> coll;
	Triangle T;
	LD cos1,cos2;

	while (cases--)
	{
		coll.clear();
		stack<Triangle> st;
		scanf("%Lf %Lf %Lf",&a,&b,&c);
		st.push(Triangle(a,b,c));

		while (!st.empty())
		{
			T=st.top();
			st.pop();
			if (coll.find(T)!=coll.end())
			{
				continue;
			}
			else
			{
				coll.insert(T);
			}
			cos1=(1.0L+T.l2*T.l2-T.l1*T.l1)/(2.0L*T.l2);
			cos2=(T.l1*T.l1+T.l2*T.l2-1.0L)/(2.0L*T.l1*T.l2);
			st.push(Triangle(1.0L,T.l2/2.0L,sqrt(1.0L+T.l2*T.l2/4.0L-T.l2*cos1)));
			st.push(Triangle(T.l1,T.l2/2.0L,sqrt(T.l1*T.l1+T.l2*T.l2/4.0L-T.l1*T.l2*cos2)));
		}
		printf("%d\n",coll.size());
	}
	return 0;
}
