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


#define MULL 31


const int N = 300000 << 1;

i64 poww[N];

char arr[N];

void init()
{
	poww[0] = 1;
	for (int i = 1; i < N; i++)
	{
		poww[i] = poww[i - 1] * MULL;
	}
}


struct Splay
{

	struct Node
	{
		Node* ch[2], *parr;
		i64 hashh;
		char val;
		int sz;

		void init(char v, Node* f, Node* x)
		{
			parr = f;
			val = v;
			hashh = v - 'a' + 1;
			sz = 1;
			ch[1] = ch[0] = x;
		}
	}storee[N];

	Node* null, *root, *nxt;

	void init(int n)
	{
		null = new Node;
		null->sz = 0;
		null->ch[0] = null->ch[1] = null;
		null->parr = null;
		null->hashh = 0;
		null->val = 0;

		nxt = storee;
		nxt->init(0, null, null);
		root = nxt++;

		nxt->init(0, root, null);
		root->ch[1] = nxt++;

		for (int i = 1; i <= n; i++)
		{
			insertt(i, arr[i - 1]);
		}
	}

	void pull_up(Node* curr)
	{
		curr->sz = curr->ch[0]->sz + curr->ch[1]->sz + 1;
		curr->hashh = curr->ch[1]->hashh + (curr->val - 'a' + 1) * poww[curr->ch[1]->sz] + curr->ch[0]->hashh * poww[curr->ch[1]->sz + 1];
	}

	void rotatee(Node *x, int d)
	{
		Node *y = x->parr;

		y->ch[d ^ 1] = x->ch[d];
		if (x->ch[d] != null) x->ch[d]->parr = y;
		x->parr = y->parr;

		if (y->parr != null)
		{
			if (y->parr->ch[0] == y)
			{
				y->parr->ch[0] = x;
			}
			else
			{
				y->parr->ch[1] = x;
			}
		}
		x->ch[d] = y, y->parr = x;
		pull_up(y);
		if (y == root)
		{
			root = x;
		}
	}

	void splay(Node *x, Node *f)
	{
		for (; x->parr != f; )
		{
			if (x->parr->parr == f)
			{
				if (x->parr->ch[0] == x)
				{
					rotatee(x, 1);
				}
				else
				{
					rotatee(x, 0);
				}
			}
			else
			{
				Node *y = x->parr, *z = y->parr;
				if (z->ch[0] == y)
				{
					if (y->ch[0] == x)
					{
						rotatee(y, 1);
						rotatee(x, 1);
					}
					else
					{
						rotatee(x, 0);
						rotatee(x, 1);
					}
				}
				else
				{
					if (y->ch[1] == x)
					{
						rotatee(y, 0);
						rotatee(x, 0);
					}
					else
					{
						rotatee(x, 1);
						rotatee(x, 0);
					}
				}
			}
		}
		pull_up(x);
		if (f == null)
		{
			root = x;
		}
	}

	void insertt(int p, char c)
	{
		movee(p, null);
		movee(p + 1, root);
		nxt->init(c, root->ch[1], null);
		root->ch[1]->ch[0] = nxt++;
		splay(root->ch[1]->ch[0], null);
	}

	void replacee(int p, char c)
	{
		movee(p - 1, null);
		movee(p + 1, root);
		Node* t = root->ch[1]->ch[0];
		t->val = c;
		t->hashh = c - 'a' + 1;
		splay(t, null);
	}

	i64 get_hash(int p1, int p2)
	{
		movee(p1 - 1, null);
		movee(p2 + 1, root);
		return root->ch[1]->ch[0]->hashh;
	}

	void movee(int k, Node *f)
	{
		Node *x = root;
		while(x != null)
		{
			int tmp = x->ch[0]->sz + 1;
			if(k == tmp)
			{
				break;
			}
			else if(k > tmp)
			{
				k -= tmp, x= x->ch[1];
			}
			else
			{
				x = x->ch[0];
			}
		}

		splay(x, f);
	}

	int lcp(int p1, int p2)
	{
		int L = 1, R = root->sz - max(p1, p2);
		int midd = L + R >> 1;

		while (L <= R)
		{
			midd = L + R >> 1;

			if (get_hash(p1, p1 + midd - 1) == get_hash(p2, p2 + midd - 1))
			{
				L = midd + 1;
			}
			else
			{
				R = midd - 1;
			}
		}
		return R;
    }

}tree;

int main()
{
	freopen("Text/STRLCP.txt","r",stdin);

	int n, m, p1, p2, c, flag;
	int test;
	scanf("%d", &test);
	char s[3], op[3];
	init();
	while (test--)
	{
		scanf("%s%d", arr, &m);
		n = strlen(arr);
		tree.init(n);
		for (int i = 0; i < m; i++)
		{
			scanf("%s", op);
			if (op[0] == 'I')
			{
				scanf("%d%s", &p1, s);
				p1++;
				tree.insertt(p1, s[0]);
			}
			else if (op[0] == 'R')
			{
				scanf("%d%s", &p1, s);
				p1++;
				tree.replacee(p1, s[0]);
			}
			else if (op[0] == 'Q')
			{
				scanf("%d%d", &p1, &p2);
				p1++, p2++;
				printf("%d\n", tree.lcp(p1, p2));
			}
		}
	}
	return 0;
}
