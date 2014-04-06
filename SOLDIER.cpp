#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <bitset>
#include<string>
#include <set>

using namespace std;
#define i64 long long

#define pii pair< int,int >
#define piii pair< pii,int >
#define ff first.first
#define fs first.second

#define EPS 1e-9

int dp[8][1001];
vector< pii > G[8];
int n,t;


int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/SOLDIER.txt","r",stdin);
    int i,j,x,y,z,k;

    scanf("%d %d",&n,&t);

    for(i=0;i<n;++i)
    {
        scanf("%d %d %d",&x,&y,&z);
        G[x].push_back(pii(y,z));
    }

    for(i=0;i<G[1].size();++i)
    {
        for(j=G[1][i].first;j<=t;++j)
        {
            dp[1][j]=max(dp[1][j],G[1][i].second);
        }
    }

    for(i=2;i<=6;++i)
    {
        for(j=0;j<G[i].size();++j)
        {
            for(k=G[i][j].first;k<=t;++k)
            {
                dp[i][k]=max(dp[i][k],min(G[i][j].second,dp[i-1][k-G[i][j].first]));
            }
        }
    }

    printf("%d\n",dp[6][t]);

    return 0;
}

