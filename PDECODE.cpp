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


#define MAXN 85
int arr[MAXN];
char buff[MAXN];
char buff2[MAXN];
bool vis[MAXN];
int n,m;

VI tv;


int main()
{
    freopen("Text/PDECODE.txt","r",stdin);

    int ti;
    while(true)
    {
        //printf("DD\n");
        //scanf("%d %d",&n,&m);
        cin>>n>>m;
        if(n==0 && m==0)
        {
            break;
        }
        MSET(vis,0);
        for(int i=0;i<n;++i)
        {
            //scanf("%d",arr+i);
            cin>>arr[i];
            --arr[i];
        }
        //scanf("\n");

        //scanf("%s",buff);
        gets(buff);
        gets(buff);
        MSET(buff2,0);
        //cout<<buff<<endl;

        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                tv.clear();

                ti=i;

                while(!vis[ti])
                {
                    vis[ti]=true;
                    tv.PB(ti);
                    ti=arr[ti];
                }

                for(int j=0;j<tv.size();++j)
                {
                    //printf("JTV\t%d\t%d\n",j,tv[j]);
                    buff2[tv[(j+m)%tv.size()]]=buff[tv[j]];
                    //buff[tv[j]]=buff[(tv[j]+m)%tv.size()];
                }
            }
        }

        printf("%s\n",buff2);


    }

    return 0;
}
