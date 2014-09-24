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



set<string> set_str;


int main(){

    freopen("Text/IITKWPCA.txt","r",stdin);
    int cases;

    char buff[10006];

    //scanf("%d\n",&cases);
    scanf("%d",&cases);
    getchar();
    //cin>>cases;

    while(cases--)
    {
        set_str.clear();

        string str;
        getline(cin,str);

        //gets(buff);
        //puts(buff);

        //string str(buff);

        stringstream str_stream(str);
        string str2;

        while(str_stream>>str2)
        {
            set_str.insert(str2);
        }

        printf("%d\n",set_str.size());
    }


	return 0;
}


