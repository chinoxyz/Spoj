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

#define MAXK 1005

int n, k;
int arr[MAXK];
int row_src[MAXK], row_destt[MAXK];
int col_src[MAXK], col_destt[MAXK];

void row_rotate( int r, int diff ,int pos)
{
	for( int i = pos; i < k; ++i )
	{
		if( row_src[i] == r )
		{
			col_src[i] = (col_src[i] + diff) % n;
		}
	}
}
void col_rotate( int c, int diff,int pos )
{
	for( int i = pos; i < k; ++i )
	{
		if( col_src[i] == c )
		{
			row_src[i] = (row_src[i] + diff) % n;
		}
	}
}

int main( void )
{
   freopen("Text/TABLIC.txt","r",stdin);

   scanf( "%d%d", &n, &k );
   for( int i = 0; i < k; ++i )
   {
      scanf( "%d%d%d",arr+i,row_destt+i,col_destt+i);
      --arr[i];
      --row_destt[i];
      --col_destt[i];
      row_src[i] = arr[i] / n;
      col_src[i] = arr[i] % n;
   }

   for( int i = 0; i < k; ++i )
   {
      int col_diff = (col_destt[i] - col_src[i]+n)%n;
      int row_diff = (row_destt[i] - row_src[i]+n)%n;

      row_rotate( row_src[i], col_diff ,i);
      col_rotate( col_src[i], row_diff ,i);

      printf( "%d\n", col_diff + row_diff );
   }

   return 0;
}
