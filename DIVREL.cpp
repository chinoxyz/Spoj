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

#define MAXN 256

VI adj[MAXN];
bool vis[MAXN];
int leftt[MAXN], rightt[MAXN];
int arr[MAXN], consumed[MAXN], ans[MAXN];

bool dfs(int u)
{
	if(vis[u])
	{
		return 0;
	}
	vis[u] = 1;
	int lenn = adj[u].size(), i, v;
	for(i=0; i<lenn; i++)
    {
		v = adj[u][i];
		if(consumed[v])
		{
		    continue;
		}
		if(rightt[v]==-1)
        {
			rightt[v] = u;
            leftt[u] = v;
			return 1;
		}
	}
	for(i=0; i<lenn; i++)
    {
		v = adj[u][i];
		if(consumed[v])
		{
		    continue;
		}

		if(dfs(rightt[v]))
        {
			rightt[v] = u;
            leftt[u] = v;
			return 1;
		}
	}
	return 0;
}

int bipartite_matching(int n)
{
	int i, ret = 0;
	bool fl;
	MSET(leftt,-1);
	MSET(rightt,-1);
	do
    {
		fl = 1;
		MSET(vis,0);
		for(i=0; i<n; i++)
		{
			if(consumed[i])
			{
			    continue;
			}
			if(leftt[i]==-1 && dfs(i))
            {
				fl = 0;
			}
		}
	} while(!fl);

	for(i=0; i<n; i++)
    {
		if(consumed[i])
		{
		    continue;
		}
		ret += (leftt[i]!=-1);
	}
	return ret;
}

int main() {

	freopen("Text/DIVREL.txt","r",stdin);

	int n, i, j, mc, nc, sz, ct, out;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
    {
        scanf("%d",arr+i);
    }
	sort(arr, arr+n);

	n = unique(arr, arr+n) - arr;
	for(i = 0; i < n; i++)
    {
		for(j = i+1; j < n; j++)
		{
			if(arr[j]%arr[i]==0)
			{
				adj[i].PB(j);
			}
		}
	}

	mc = n - bipartite_matching(n);

	for(i = ct = out = 0; i < n && ct < mc; i++)
    {
		if(consumed[i])
        {
            continue;
        }
		sz = adj[i].size();
		for(j = 0; j < sz; j++)
		{
			if(!consumed[adj[i][j]])
			{
			    out++;
			}
			consumed[adj[i][j]]++;
		}
		nc = n - out - bipartite_matching(n);
		if(mc == nc)
        {
            ans[ct++] = i;
        }
		else
        {
			for(j = 0; j < sz; j++)
			{
				consumed[adj[i][j]]--;
				if(!consumed[adj[i][j]])
				{
				    out--;
				}
			}
		}
	}

	printf("%d\n", mc);
	printf("%d", arr[ans[0]]);
	for(i = 1; i < mc; i++)
    {
        printf(" %d", arr[ans[i]]);
    }
	printf("\n");

	return 0;
}
