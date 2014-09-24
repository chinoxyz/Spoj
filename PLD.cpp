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

#define MAXX 30001

//const i64 C=1000000007LL;
const i64 C = (i64)1e9 + 7;

i64 hash_left[MAXX],hash_right[MAXX],poww[MAXX];

int main()
{

    int k,ret=0,ti;
    string str;
    int len;

    freopen("Text/PLD.txt","r",stdin);

    poww[0]=1;

    for(int i=1;i<MAXX;++i)
    {
        poww[i]=poww[i-1]*C;
    }

    //scanf("%d",&k);
    cin>>k;
    cin>>str;
    len=str.size();

    //printf("%d%s%d\n",k,str.c_str(),len);

    for(int i=0;i<k;++i)
    {
        hash_left[0]+=poww[k-i-1]*str[i];
    }

    for(int i=1;(i+k-1)<len;++i)
    {
        hash_left[i]=(hash_left[i-1]-poww[k-1]*str[i-1])*C+str[i+k-1];
    }


    reverse(str.begin(),str.end());

    for(int i=0;i<k;++i)
    {
        hash_right[0]+=poww[k-i-1]*str[i];
    }

    for(int i=1;(i+k-1)<len;++i)
    {
        hash_right[i]=(hash_right[i-1]-poww[k-1]*str[i-1])*C + str[i+k-1];
    }

    for(int i=0;(i+k-1)<len;++i)
    {
        ti=i+k-1;

        if(hash_left[i]==hash_right[len-1-ti])
        {
            ++ret;
        }
    }

    printf("%d\n",ret);

    return 0;
}
