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

#define MAXC 100003
#define MAXN 100003

int data[MAXN];
int idx[MAXN];
bool vis[MAXN];
int num_child,num_nei;


int main() {

    freopen("Text/HALLOW.txt","r",stdin);

    int ti,summ;
    int i,j,sz,span,st,en;

    while(true)
    {

        scanf("%d %d",&num_child,&num_nei);

        if(num_child==0 && num_nei==0)
        {
            break;
        }

        MSET(idx,0);
        MSET(vis,0);
        span=MAXN;
        summ=0;
        idx[0]=-1;
        vis[0]=true;


        REP(i,num_nei)
        {
            scanf("%d",data+i);
        }

        REP(i,num_nei)
        {
            summ+=data[i];
            summ%=num_child;

            if(vis[summ])
            {
                if(i-idx[summ]<span)
                {
                    span=i-idx[summ];
                    st=idx[summ]+1;
                    en=i;
                }
            }

            idx[summ]=i;
            vis[summ]=1;
        }

        for(i=st+1;i<=en;++i)
        {
            printf("%d ",i);
        }
        printf("%d\n",i);

    }

    return 0;
}
