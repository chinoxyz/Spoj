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

using namespace std;

#define i64 long long



int main()
{
    //freopen("C:/Users/MINTOO/Desktop/Programs/Codeblocks/Spoj/Text/EMTY2.txt","r",stdin);

    int i,j,cases,l,ct1,ct0;
    char a[120005];
    bool poss;

    scanf("%d",&cases);

    for(i=1;i<=cases;++i)
    {
        ct1=ct0=0;
        scanf("%s",a);
        l=strlen(a);
        poss=true;

        for(j=l-1;j>=0;--j)
        {
            if(a[j]=='0')
            {
                ++ct0;
            }
            else
            {
                ct0-=2;
                if(ct0<0)
                {
                    poss=false;
                    break;
                }
            }
        }

        if(ct0!=0)
        {
            poss=false;
        }

        if(poss)
        {
            printf("Case %d: yes\n",i);
        }
        else
        {
            printf("Case %d: no\n",i);
        }
    }



    return 0;
}

