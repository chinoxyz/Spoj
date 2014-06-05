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

#define maxx 10000001

int a[maxx];
int b[maxx],c[maxx];

int mx=1,n;

int main()
{

    //freopen("C:/Users/Deepak/Desktop/Deepak/Programs/Spoj/Text/GONESORT.txt","r",stdin);
    int cases,i,j;

    scanf("%d",&cases);

    while(cases--)
    {
        mx=1;
        scanf("%d",&n);
        fill(c,c+n,1);
        for(i=0;i<n;++i)
        {
            scanf("%d",a+i);
            b[a[i]]=i;
        }
        sort(a,a+n);

        for(i=1;i<n;++i)
        {
            if(b[a[i-1]]<b[a[i]])
            {
                c[i]=c[i-1]+1;
                if(c[i]>mx)
                {
                    mx=c[i];
                }
            }
        }

        printf("%d\n",n-mx);
    }
    return 0;
}

