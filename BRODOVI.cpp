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

#define MAXN 1000000001

bitset<5000> vis;

int arr[5000];


int main(){

    freopen("Text/BRODOVI.txt","r",stdin);

    int n,ct=0,ti,st;
    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        scanf("%d",arr+i);
    }

    for(int i=1;i<n;++i)
    {
        if(!vis.test(i))
        {
            vis.set(i);
            ++ct;
            int lt=arr[i];

            int diff=arr[i]-arr[0];

            for(int j=i+1;j<n;++j)
            {
                if(lt+diff==arr[j])
                {
                    vis.set(j);
                    lt=arr[j];
                }
            }
        }
    }

    printf("%d\n",ct);

	return 0;
}

