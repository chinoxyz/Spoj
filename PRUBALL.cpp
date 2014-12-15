#include <cstdio>
#include <algorithm>
#include <iostream>
#include<sstream>
#include<cstring>


using namespace std;
#define i64 long long

#define MAXB 51
#define MAXF 1001

int arr[MAXF][MAXB];
int f,b;


void pree()
{
    for(int i=1;i<MAXB;++i)
    {
        arr[1][i]=1;
    }

    for(int i=1;i<MAXF;++i)
    {
        arr[i][1]=i;
    }

    for(int i=2;i<MAXF;++i)
    {
        for(int j=2;j<MAXB;++j)
        {
            arr[i][j]=MAXF;
            for(int k=1;k<=i;++k)
            {
                arr[i][j]=min(arr[i][j],1+max(arr[k-1][j-1],arr[i-k][j]));
            }
        }
    }
}

int main()
{
    freopen("Text/PRUBALL.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    int t;

    pree();

    while(cases--)
    {
        scanf("%d %d %d",&t,&b,&f);
        printf("%d %d\n",t,arr[f][b]);
    }



    return 0;
}
