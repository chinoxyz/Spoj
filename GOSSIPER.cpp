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

#define MAXN 2101
#define MAXM 12001


map<string,int> mp;
bitset<MAXN> goss[MAXN];
bool poss;

int main() {

    freopen("Text/GOSSIPER.txt","r",stdin);
    int i,x,y;
    char buff[100],buff2[100];
    int n,m;

    while(true)
    {
        scanf("%d %d",&n,&m);

        if(n==0 && m==0)
        {
            break;
        }
        poss=true;
        MSET(goss,0);
        mp.clear();

        REP(i,n)
        {
            scanf("%s",buff);
            string str(buff);
            mp.insert(MP(str,i+1));
            goss[i].set(i);
        }

        REP(i,m)
        {
            scanf("%s %s",buff,buff2);
            string str1(buff);
            string str2(buff2);
            x=mp[str1];
            y=mp[str2];
            --x;
            --y;

            goss[x]|=goss[y];
            goss[y]|=goss[x];
        }

        REP(i,n)
        {
            if(goss[i].count()!=n)
            {
                poss=false;
                break;
            }
        }

        if(poss)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
