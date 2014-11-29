#include<bits/stdc++.h>
using namespace std;
int n;
int ct[10];
void solve()
{
    if(n==0)
    {
        printf("%d\n",10);
        return;

    }
    if(n<10)
    {
        printf("%d\n",n);
        return;
    }
    memset(ct,0,sizeof(ct));
    for(int i=9;i>1;--i)
    {
        while(n%i==0)
        {
            ++ct[i];
            n/=i;
        }
    }
    if(n>1)
    {
        printf("-1\n");
    }
    else
    {
        for(int i=1;i<=9;++i)
        {
            while(ct[i])
            {
                --ct[i];
                printf("%d",i);
            }
        }

        printf("\n");
    }
}
int main()
{
    freopen("Text/SNGINT.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        solve();
    }
    return 0;
}
