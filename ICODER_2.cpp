#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,temp;
    char str[6];
    while(~scanf("%d",&n) && n){
        int ans = 65536;
        bool flag = true;
        for(int i = 1;i <= n;i ++){
            scanf("%s %d",str,&temp);
            if(str[0] == 'M'){
                if(temp == 0)  {flag = false;continue;}
                while(temp % 2 == 0){
                    ans >>= 1;
                    temp /= 2;
                }
            }
        }
        if(!flag || !ans) printf("%d\n",1);
        else printf("%d\n",ans);
    }
    return 0;
}
