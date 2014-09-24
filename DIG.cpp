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
    int num_cases;
    u64 mod_by = (24LL)*1000000007LL;
    cin >> num_cases;

    u64 n;
    u64 answer;
    for(int i = 0; i < num_cases; i++) {
        cin >> n;
        u64 x = (n*(n-1)) % (mod_by);
        u64 y = (x*(n-2)) % (mod_by);
        u64 z = (y*(n-3)) % (mod_by);
        answer = z / 24LL;
        cout << answer << endl;
    }

    return 0;
}
