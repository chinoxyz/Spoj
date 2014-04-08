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

i64 n,m,len,curr,pre,x,dd;
i64 a[1000001];
i64 diff[1000001];

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/EKO.txt","r",stdin);
    int i,j;

    scanf("%lld %lld",&n,&m);

    for(i=0;i<n;++i)
    {
        scanf("%lld",a+i);
    }

    a[n]=0;

    sort(a,a+n+1);
    reverse(a,a+n+1);

    for(j=0;j<n;++j)
    {
        diff[j]=a[j]-a[j+1];
    }

    pre=0;
    curr=0;
    len=0;

    for(i=1;i<=n;++i)
    {
        pre=curr;
        curr+=i*diff[i-1];

        if(curr>=m)
        {
            if(curr==m)
            {
                len+=diff[i-1];
            }
            break;
        }
        len+=diff[i-1];
    }

    if(curr>m)
    {
        dd=m-pre;
        x=ceil(dd/(double)i);
    }
    else
    {
        x=0;
    }
    len+=x;

    //printf("%lld\n",len);
    printf("%lld\n",a[0]-len);


    return 0;
}

