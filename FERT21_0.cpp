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
#include <string>
#include <set>
#include <queue>

using namespace std;
#define i64 long long

#define maxx 1010
string ans[maxx];
int n;
char buff[4],b2[4];

string addd(string a,string b)
{
    int i,j,la,lb,t1;
    string tem;
    if(a.length() < b.length())
    {
        tem=a;
        a=b;
        b=tem;
    }

    la=a.length();
    lb=b.length();
    int c=0;
    string ret;


    for(i=la-1,j=lb-1;j>=0;--i,--j)
    {
        t1=(a[i]-'0')+(b[j]-'0');
        t1+=c;
        sprintf(b2,"%d\0",t1%10);
        ret.insert(0,b2);
        c=t1/10;
    }

    for(;i>=0;--i)
    {
        t1=a[i]-'0';
        t1+=c;
        sprintf(b2,"%d\0",t1%10);
        ret.insert(0,b2);
        c=t1/10;
    }

    if(c)
    {
        sprintf(b2,"%d\0",c);
        ret.insert(0,b2);
    }

    //printf("AAAA\n");
    return ret;

}
string multt(string a,string b)
{
    //printf("MMM\n");
    int i,j,la,lb,k;
    la=a.length();
    lb=b.length();
    string ret="0";
    string tem,tem2;
    int c=0;
    int t1;


    //printf("%d\t%d\n",la,lb);

    for(i=lb-1;i>=0;--i)
    {
        c=0;
        tem="";
        for(k=lb-1;k>i;--k)
        {
            tem.insert(0,"0\0");
        }
        for(j=la-1;j>=0;--j)
        {
            t1=(b[i]-'0')*(a[j]-'0');
            t1+=c;
            sprintf(buff,"%d\0",t1%10);
            tem.insert(0,buff);
            c=t1/10;
        }
        if(c)
        {
            sprintf(buff,"%d\0",c);
            tem.insert(0,buff);
        }
        //printf("%d\tMMMMMAAAAAAA\n",i);
        ret=addd(ret,tem);
    }

    return ret;
}

string mul2(string a)
{
    int i,j,la,c=0,t1;
    string ret;
    char b3[4];

    la=a.length();

    for(i=la-1;i>=0;--i)
    {
        t1=(a[i]-'0')*5;
        t1+=c;
        sprintf(b3,"%d",t1%10);
        ret.insert(0,b3);
        c=t1/10;
    }

    if(c)
    {
        sprintf(b3,"%d",c);
        ret.insert(0,b3);
    }

    return ret;

}

void solve()
{
    int i;
    string ret="1";
    string five="5";
    int tn=n;

    while(n>0)
    {
        if(n&1)
        {
            ret=multt(five,ret);
        }
        five=multt(five,five);
        n>>=1;
    }


    printf("0.");
    int diff=tn-ret.length();

    for(i=0;i<diff;++i)
    {
        printf("0");
    }
    printf("%s\n",ret.c_str());
}

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/FERT21_0.txt","r",stdin);
    int i,j,cases;
    int diff,tn;
    ans[0]="1";

    for(i=1;i<maxx;++i)
    {
        //ans[i]=multt(ans[i-1],"5");
        ans[i]=mul2(ans[i-1]);
    }
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("1\n");
        }
        else
        {
            --n;
            tn=n;

            printf("0.");
            diff=tn-ans[tn].length();

            for(i=0;i<diff;++i)
            {
                printf("0");
            }

            printf("%s\n",ans[tn].c_str());
            //solve();
        }
    }
    return 0;
}


