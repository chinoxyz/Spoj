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
#define Vi64 vector<i64>
#define Vu64 vector<u64>


int main(){

        int arr[4] = {1, 1, 1, 1}, brr[4], ans;

        while(ans != 4)
        {
                for(int i = 0; i < 4; ++i)
                {
                    printf("%d%c", arr[i], i == 3 ? 10 : 32);
                }

                fflush(stdout);
                ans = 0;
                for(int i = 0; i < 4; ++i)
                {
                        scanf("%d", brr + i);
                        if(brr[i] != 1)
                        {
                            ++arr[i];
                        }
                        ans += brr[i];
                }
        }
        return 0;
}

