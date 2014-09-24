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


int main()
{

    freopen("Text/MB1.txt","r",stdin);

    int n,cases;

    int a[]={2, 3, 5, 7, 11, 101, 131, 151, 181, 191, 313, 353, 373, 383, 727, 757, 787, 797, 919, 929, 10301, 10501, 10601, 11311, 11411, 12421, 12721, 12821, 13331, 13831, 13931, 14341, 14741, 15451, 15551, 16061, 16361, 16561, 16661, 17471, 17971, 18181, 18481, 19391, 19891, 19991, 30103, 30203, 30403, 30703, 30803, 31013, 31513, 32323, 32423, 33533, 34543, 34843, 35053, 35153, 35353, 35753, 36263, 36563, 37273, 37573, 38083, 38183, 38783, 39293, 70207, 70507, 70607, 71317, 71917, 72227, 72727, 73037, 73237, 73637, 74047, 74747, 75557, 76367, 76667, 77377, 77477, 77977, 78487, 78787, 78887, 79397, 79697, 79997, 90709, 91019, 93139, 93239, 93739, 94049, 94349, 94649, 94849, 94949, 95959, 96269, 96469, 96769, 97379, 97579, 97879, 98389, 98689};
    int b[]={3, 5, 11, 17, 2, 2, 5, 11, 19, 23, 23, 197, 307, 359, 521, 1553, 2693, 3083, 419, 953, 5, 11, 13, 5, 7, 53, 107, 131, 103, 359, 419, 223, 613, 541, 691, 151, 593, 1069, 1321, 1193, 3083, 311, 1619, 1543, 4813, 5519, 23, 61, 151, 307, 359, 23, 197, 593, 827, 2789, 5443, 9311, 1427, 1427, 5039, 13249, 4813, 13697, 6857, 19447, 4211, 4211, 38197, 12197, 521, 1553, 1931, 853, 3083, 2693, 11353, 3083, 6857, 23789, 6007, 53881, 60761, 51713, 111599, 72871, 100169, 244691, 134587, 248851, 288359, 127081, 272141, 424243, 4127, 419, 5519, 12197, 49681, 10627, 36677, 79349, 109037, 124181, 202987, 57559, 124181, 229727, 127081, 222863, 373019, 170627, 364523};

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        printf("%d %d",a[n-1],b[n-1]);
        printf("\n");
    }

    return 0;
}
