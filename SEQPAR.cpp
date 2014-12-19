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


const int INF = 1 << 30;
#define MAXN 20000

struct Treap
{
	struct Node
	{
		int key;
		PII value, rangeValue;
		int priorityy;
		Node *ch[2];
		Node(int key, PII value) :
		key(key), value(value), priorityy(rand()) { ch[0] = ch[1] = 0; }
	} *root;

	Treap() : root(0) { }

	PII getRangeValue(Node *n)
	{
		return n ? n->rangeValue : PII(INF,-INF);
	}

	PII minMax(PII x, PII y)
	{
		return PII(min(x.first, y.first), max(x.second, y.second));
	}

	Node *update(Node *n)
	{
		if (n)
		{
			n->rangeValue = minMax(n->value, minMax(getRangeValue(n->ch[0]), getRangeValue(n->ch[1])));
		}
		return n;
	}

	Node *rotate(Node *n, int b)
	{
		Node *m = n->ch[b];
		n->ch[b] = m->ch[!b];
		m->ch[!b] = update(n);
		return update(m);
	}
	Node *insert(Node *n, int key, PII value)
	{
		if (!n)
		{
			return update(new Node(key, value));
		}

		int b = (n->key < key);
		n->ch[b] = insert(n->ch[b], key, value);

		return n->ch[b]->priorityy < n->priorityy ? rotate(n, b) : update(n);
	}

	void insert(int key, PII value)
	{
		root = insert(root, key, value);
	}

	PII rangeSum(Node *n, int key)
	{
		if (!n)
		{
			return getRangeValue(n);
		}
		if (n->key < key)
		{
			return rangeSum(n->ch[1], key);
		}

		return minMax(rangeSum(n->ch[0], key), minMax(n->value, getRangeValue(n->ch[1])));
	}
};

int arr[MAXN], summ[MAXN], n, k;

bool tryy(int m)
{
	PII p;
	Treap tree;
	tree.insert(0, make_pair(0, 0));

	for (int i = 0; i < n; ++i)
	{
		p = tree.rangeSum(tree.root, summ[i] - m);
		p.first += 1; p.second += 1;
		tree.insert(summ[i], p);
	}
	return p.first <= k && k <= p.second;
}

int solve()
{
	int l = -INF, r = +INF;
	int midd;
	while (l+1 < r)
	{
		midd = (r + l)>>1;

		if (tryy(midd))
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	return r;
}

int main()
{
	freopen("Text/SEQPAR.txt","r",stdin);

	int cases;
	scanf("%d", &cases);
	while (cases--)
	{
		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", arr+i);
		}

		summ[0] = arr[0];
		for (int i = 1; i < n; ++i)
		{
			summ[i] = summ[i-1] + arr[i];
		}

		printf("%d\n", solve());
	}
}
