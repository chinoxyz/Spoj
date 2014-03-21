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

i64 solve(i64 n,i64 tln)
{
    if(tln<=0)
    {
        return 1;
    }

    if(!(n&(n+1)))
    {
        return n+1;
    }

    i64 temp=n-(((tln+1)>>1));
    if(temp<0)
    {
        temp=n;
        i64 ret=solve(temp,((tln+1)>>1)-1);

        return ret;
    }
    else
    {
        i64 ret=solve(temp,((tln+1)>>1)-1);
        return 2*ret;
    }

}

int main()
{
    //freopen("C:/Users/MINTOO/Desktop/Programs/Codeblocks/Spoj/Text/HLP_RAMS.txt","r",stdin);

    int i,j,cases;
    i64 n,tln,oddd;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld",&n);
        tln=log2(n);
        tln=pow(2,tln+1);
        tln-=1;
        oddd=solve(n,tln);

        printf("%lld %lld\n",n+1-oddd,oddd);
    }



    return 0;
}

