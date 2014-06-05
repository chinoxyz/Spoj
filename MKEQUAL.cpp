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


int main()
{
    //printf("DD");
    //freopen("C:/Users/Deepak/Desktop/Deepak/Programs/Spoj/Text/MKEQUAL.txt","r",stdin);
    int cases,i,j;

    i64 sum,temp,n;


    scanf("%d",&cases);

    while(cases--)
    {
        sum=0;
        scanf("%lld",&n);

        for(i=0;i<n;++i)
        {
            scanf("%lld",&temp);
            sum+=temp;
        }

        if(sum%n)
        {
            printf("%lld\n",n-1);
        }
        else
        {
            printf("%lld\n",n);
        }
    }
    return 0;
}

