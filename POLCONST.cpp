#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("Text/POLCONST.txt","r",stdin);

    int cases;

    int ti;

    scanf("%d",&cases);

    int arr[]={3,5,17,257,65537};

    while(cases--)
    {
       int n;
       scanf("%d",&n);

       while(!(n&1))
       {
           n/=2;
       }

       for(int i=0;i<5;++i)
       {
           if(!(n%arr[i]))
           {
               n/=arr[i];
           }
       }

        if(n==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

    }


    return 0;
}

