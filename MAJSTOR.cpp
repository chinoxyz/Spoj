#include <iostream>
#include <cstdio>
using namespace std;
char a[52];
int c[52][3];
char t[52];
int main()
{
    int i,j,n,r,p=0,q=0,x,y,z;
    scanf("%d",&r);
    scanf("%s",&a);
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%s",t);
        for(j=0;j<r;++j)
        {
            if(t[j]=='R')
            {
                ++c[j][0];
            }
            else if(t[j]=='S')
            {
                ++c[j][1];
            }
            else
            {
                ++c[j][2];
            }
        }
    }
    for(i=0;i<r;++i)
    {
        x=c[i][0];
        x+=2*c[i][1];
        y=c[i][1];
        y+=2*c[i][2];
        z=c[i][2];
        z+=2*c[i][0];
        if(a[i]=='R')
        {
            p+=x;
        }
        else if(a[i]=='S')
        {
            p+=y;
        }
        else
        {
            p+=z;
        }

        q+=max(x,max(y,z));

    }
    printf("%d\n%d\n",p,q);
    return 0;
}

