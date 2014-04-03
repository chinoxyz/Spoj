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

using namespace std;
#define i64 long long

char a[20003];
int pos=0,maxl,minc,ct,n;

void dfs(int l)
{
    if(pos>=n)
    {
        return;
    }
    if(a[pos]=='1')
    {
        ++ct;
    }

    if(maxl<l)
    {
        maxl=l;
        minc=ct;
    }

    if(a[pos]=='1')
    {
        ++pos;
        dfs(l+1);
        dfs(l+1);
    }
    else
    {
        ++pos;
    }
}

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/DYZIO.txt","r",stdin);
    int i,j,cases=10;

    while(cases--)
    {
        scanf("%d %s",&n,a);
        ct=0;
        pos=0;
        minc=0;
        maxl=-1;

        if(a[0]=='0')
        {
            printf("0\n");
        }
        else
        {
            dfs(0);
            printf("%d\n",minc);
        }
    }






    return 0;
}

