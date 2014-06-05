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
#include <string>
#include <set>
#include <queue>

using namespace std;
#define i64 long long

i64 a[32],b[32];

int main()
{
    //freopen("C:/Users/Deepak/Desktop/Deepak/Programs/Spoj/Text/MAIN113.txt","r",stdin);
    int cases,i,j;

    a[1]=3;
    b[1]=3;
    a[2]=3;
    b[2]=6;

    for(i=3;i<=30;++i)
    {
        a[i]=a[i-1]+b[i-1];
        b[i]=2*a[i-1]+b[i-1];
        //printf("%d\t%lld\n",i,a[i]+b[i]);
    }

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&j);
        printf("%lld\n",a[j]+b[j]);
    }
    return 0;
}

