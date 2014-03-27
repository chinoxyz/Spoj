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

int ct[10];
int sum,modd;

bool hasother;


void printnums()
{
    int i,j;

    for(i=9;i>=0;--i)
    {
        for(j=0;j<ct[i];++j)
        {
            printf("%d",i);
        }
    }
    //printf("\n");
}

char digits[1024];

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/DIV15.txt","r",stdin);

    int i,j,cases;
    char c;

    scanf("%d\n",&cases);

    while(cases--)
    {
        hasother=false;
        sum=0;

        memset(ct,0,sizeof(ct));
        scanf("%s",digits);
        for(i = 0; digits[i]; ++i)
        {
            ct[digits[i]-'0']++;
            sum+=(digits[i]-'0');
        }

        modd=sum%3;


        if(modd==1)
        {
            if(ct[1])
            {
                --ct[1];
                modd=0;
            }
            else if(ct[4])
            {
                --ct[4];
                modd=0;
            }
            else if(ct[7])
            {
                --ct[7];
                modd=0;
            }
            else if(ct[2]>1)
            {
                ct[2]-=2;
                modd=0;
            }
            else if(ct[5] && ct[2] && (ct[0] || ct[5]>1))
            {
                --ct[2];
                --ct[5];
                modd=0;
            }
            else if(ct[5]>1 && (ct[0] || ct[5]>2))
            {
                ct[5]-=2;
                modd=0;
            }
            else if(ct[8] && ct[2])
            {
                --ct[2];
                --ct[8];
                modd=0;
            }
            else if(ct[8] && ct[5] && (ct[0] || ct[5]>1))
            {
                --ct[5];
                --ct[8];
                modd=0;
            }
            else if(ct[8]>1)
            {
                ct[8]-=2;
                modd=0;
            }
        }
        else if(modd==2)
        {
            if(ct[2])
            {
                --ct[2];
                modd=0;
            }
            else if(ct[5] && (ct[0] || ct[5]>1))
            {
                --ct[5];
                modd=0;
            }
            else if(ct[8])
            {
                --ct[8];
                modd=0;
            }
            else if(ct[1]>1)
            {
                ct[1]-=2;
                modd=0;
            }
            else if(ct[1] && ct[4])
            {
                --ct[1];
                --ct[4];
                modd=0;
            }
            else if(ct[4]>1)
            {
                ct[4]-=2;
                modd=0;
            }
            else if(ct[1] && ct[7])
            {
                --ct[1];
                --ct[7];
                modd=0;
            }
            else if(ct[4] && ct[7])
            {
                --ct[4];
                --ct[7];
                modd=0;
            }
            else if(ct[7]>1)
            {
                ct[7]-=2;
                modd=0;
            }
        }



        if(modd==0)
        {

            for(i=1;i<10;++i)
            {
                if(i!=5 && ct[i])
                {
                    hasother=true;
                    break;
                }
            }


            if(ct[0]==0)
            {
                if(ct[5]==0)
                {
                    printf("impossible\n");
                }
                else
                {
                    --ct[5];
                    printnums();
                    printf("5\n");
                }
            }
            else
            {
                if(!hasother && ct[5]==0)
                {
                    printf("0\n");
                }
                else
                {
                    printnums();
                    printf("\n");
                }
            }
        }
        else if(ct[0])
        {
            printf("0\n");
        }
        else
        {
            printf("impossible\n");
        }
    }

    return 0;
}

