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

double m,n;

void solve()
{
    int k=(20.0*m)/n+.5f;

    int p=(100.0*m)/n+.5f;

    //printf("%d\t%d\n",k,p);

    string ret="";

    for(int i=0;i<20;++i)
    {
        if(i<k)
        {
            ret+="*";
        }
        else
        {
            ret+="-";
        }
    }

    //cout << ret.substr(0,9-(p==100)) << k << "%" << ret.substr(11+(k>=10),19) << endl;


    cout<<ret.substr(0,9-(p==100));
    cout<<p;
    cout<<"%";
    cout<<ret.substr(11+(p>=10),19);

    cout<<endl;


}


int main()
{
    freopen("Text/INDIPROG.txt","r",stdin);


    while(true)
    {
        cin>>m>>n;

        if(m==-1)
        {
            break;
        }
        solve();

    }

    return 0;
}

