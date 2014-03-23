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

using namespace std;
#define i64 long long

#define maxn 101

int zeroo[maxn][maxn];
int onee[maxn][maxn];


void precomp()
{
    int i,j,k;

    zeroo[1][0]=1;
    onee[1][0]=1;

    for(i=2;i<maxn;++i)
    {
        for(j=0;j<i;++j)
        {
            zeroo[i][j]=zeroo[i-1][j]+onee[i-1][j];
            onee[i][j]=zeroo[i-1][j];

            if(j>0)
            {
                onee[i][j]+=onee[i-1][j-1];
            }
        }
    }
}

int main()
{
    //freopen("C:/Users/MINTOO/Desktop/Programs/Codeblocks/Spoj/Text/GNYR09F.txt","r",stdin);

    int cases,i,j,k,p,n;


    scanf("%d",&cases);

    precomp();

    while(cases--)
    {
        scanf("%d %d %d",&p,&n,&k);

        printf("%d %d\n",p,zeroo[n][k]+onee[n][k]);
    }


    return 0;
}

