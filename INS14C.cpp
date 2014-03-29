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

int n,k,ct,z,o,ze,oe;
char a[2000];
vector<int> zero;
vector<int> one;
int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/INS14C.txt","r",stdin);

    int i,j,cases;
    scanf("%d",&cases);

    while(cases--)
    {
        zero.clear();
        one.clear();

        scanf("%d %d",&n,&k);
        ct=n-k;

        scanf("%s",a);

        for(i=0;i<n;++i)
        {
            if(a[i]=='0')
            {
                zero.push_back(i);
            }
            else
            {
                one.push_back(i);
            }
        }
        o=(ct+1)/2;
        z=ct-o;
        ze=zero.size();
        oe=one.size();

        if(z>ze)
        {
            oe-=z-ze;
        }
        else if(o>oe)
        {
            ze-=o-oe;
        }

        while(o<oe && z<ze)
        {
            if(zero[z]<one[o])
            {
                printf("%c",a[zero[z]]);
                ++z;
            }
            else
            {
                printf("%c",a[one[o]]);
                ++o;
            }
        }
        while(o<oe)
        {
            printf("%c",a[one[o]]);
            ++o;
        }

        while(z<ze)
        {
            printf("%c",a[zero[z]]);
            ++z;
        }
        printf("\n");



    }

    return 0;
}

