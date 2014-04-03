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

using namespace std;
#define i64 long long

int a[5002][5002],n;
char b[5002];
int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/IOIPALIN.txt","r",stdin);
    int i,j,t1,t2,t3;

    scanf("%d",&n);
    scanf("%s",b);

    t1=n-2;
    for(i=0;i<=t1;++i)
    {
        if(b[i]!=b[i+1])
        {
            a[i][i+1]=1;
        }
    }

    for(i=3;i<=n;++i)
    {
        t1=n-i;
        t2=i-1;
        t3=i-2;
        for(j=0;j<=t1;++j)
        {
            if(b[j]==b[j+t2])
            {
                a[j][j+t2]=a[j+1][j+t3];
            }
            else
            {
                a[j][j+t2]=1+min(a[j+1][j+t2],a[j][j+t3]);
            }
        }
    }

    printf("%d\n",a[0][n-1]);

    return 0;
}

