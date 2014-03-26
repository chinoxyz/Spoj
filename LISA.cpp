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
#include <climits>


using namespace std;
#define i64 long long
#define u64 unsigned long long

u64 INF=ULLONG_MAX;

char str[103];
int len,numl,signl;
int nums[100];
char signs[100];
u64 ans[102][102];
u64 ans2[102][102];

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/LISA.txt","r",stdin);

    int i,j,cases,temp,temp1,temp2,k;

    scanf("%d",&cases);

    while(cases--)
    {
        memset(nums,0,sizeof(nums));
        memset(signs,0,sizeof(signs));
        memset(ans,0,sizeof(ans));
        //memset(ans2,0,sizeof(ans2));
        numl=0;
        signl=0;

        scanf("%s",str);
        len=strlen(str);

        i=0;
        temp=0;
        while(i<len)
        {
            temp=0;
            while(i<len && str[i]>='0' && str[i]<='9')
            {
                temp*=10;
                temp+=str[i]-'0';
                ++i;
            }
            nums[numl++]=temp;

            if(i<len)
            {
                signs[signl++]=str[i++];
            }
        }

        for(i=0;i<=numl;++i)
        {
            for(j=0;j<=numl;++j)
            {
                ans2[i][j]=ULLONG_MAX;
            }
        }

        for(i=0;i<numl;++i)
        {
            ans[i][i]=nums[i];
            ans2[i][i]=nums[i];
        }



        for(i=2;i<=numl;++i)
        {
            for(j=0;j<=numl-i;++j)
            {
                for(k=1;k<=i-1;++k)
                {
                    temp1=ans[j][j+k-1];
                    temp2=ans2[j][j+k-1];

                    if(signs[j+k-1]=='+')
                    {
                        temp1+=ans[j+k][j+i-1];
                        temp2+=ans2[j+k][j+i-1];
                    }
                    else
                    {
                        temp1*=ans[j+k][j+i-1];
                        temp2*=ans2[j+k][j+i-1];
                    }

                    if(temp1>ans[j][j+i-1])
                    {
                        ans[j][j+i-1]=temp1;
                    }

                    if(temp2<ans2[j][j+i-1])
                    {
                        ans2[j][j+i-1]=temp2;
                    }
                }
            }
        }

        printf("%llu %llu\n",ans[0][numl-1],ans2[0][numl-1]);
    }


    return 0;
}

