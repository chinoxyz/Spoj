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







int main()
{
    freopen("Text/MINMOVE.txt","r",stdin);

    char str[100001];
    scanf("%s",str);

    int len=strlen(str);
    int best_start=0,candidate_start=1,matching_len=0;

    while(candidate_start<len && best_start+matching_len+1<len)
    {
        if(str[best_start+matching_len]==str[(candidate_start+matching_len)%len])
        {
            ++matching_len;
        }
        else if(str[best_start+matching_len]<str[(candidate_start+matching_len)%len])
        {
            candidate_start=candidate_start+matching_len+1;
            matching_len=0;
        }
        else
        {
            best_start=max(best_start+matching_len+1,candidate_start);
            candidate_start=best_start+1;
            matching_len=0;
        }
    }

    printf("%d\n",best_start);

    return 0;
}
