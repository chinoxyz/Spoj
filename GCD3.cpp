#include <cstdio>
#include <algorithm>
#include <iostream>
#include<sstream>
#include<cstring>


using namespace std;
#define i64 long long


#define MAXN 20006
char a[MAXN],b[MAXN];
int l1,l2;
i64 numm;
int k;


int main()
{
    freopen("Text/GCD3.txt","r",stdin);

    int cases;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%s %s %d",a,b,&k);
        //printf("DD\n");
        l1=strlen(a);
        l2=strlen(b);
        k=min(k,l1);
        sscanf(a+l1-k,"%lld",&numm);

        if((a[l1-1]-'0')&1)
        {
            printf("%lld\n",1LL);
        }
        else
        {
            for(int i=k;i>0;--i)
            {
                if(!(numm&((1LL<<i)-1LL)))
                {
                    printf("%lld\n",1LL<<i);
                    break;
                }
            }
        }


    }

    return 0;
}
