#include <cstdio>
#include <algorithm>
#include<iostream>
int main()
{
    freopen("Text/TCOUNT2.txt","r",stdin);

    int cases;
    long double n;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%Lf",&n);

        printf("%.0Lf\n",n/2.0*(7.0*n*n+4.5*n+1.0));
    }



    return 0;
}
