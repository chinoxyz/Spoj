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


#define MAXN 33
#define MAXL 999

map<string,int> mp;
int n,m;
char buff[MAXL],buff2[MAXL];
double costt;

double dp[MAXN][MAXN];
bool poss;

int main()
{
    freopen("Text/ARBITRAG.txt","r",stdin);

    int cases=0,u,v;

    while(true)
    {
        mp.clear();
        poss=false;
        MSET(dp,0);
        ++cases;
        //scanf("%d",&n);
        cin>>n;

        if(n==0)
        {
            break;
        }



        for(int i=1;i<=n;++i)
        {
            //scanf("%s",buff);
            cin>>buff;
            string s(buff);
            mp[s]=i;
        }



        //scanf("%d",&m);
        cin>>m;

        for(int i=0;i<m;++i)
        {
            //scanf("%s %lf %s",buff,&costt,buff2);
            cin>>buff>>costt>>buff2;
            string us(buff);
            string vs(buff2);
            u=mp[us];
            v=mp[vs];
            dp[u][v]=costt;
        }

        //printf("N\t%d\n",n);

        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]*dp[k][j]);
                }
            }
        }


        for(int i=1;i<=n;++i)
        {
            if(dp[i][i]>1.0)
            {
                poss=true;
                break;
            }
        }

        if(poss)
        {
           printf("Case %d: Yes\n",cases);
        }
        else
        {
            printf("Case %d: No\n",cases);
        }
    }


    return 0;
}
