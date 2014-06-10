#include<iostream>
#include<cstdio>

using namespace std;
int main()
{
int t;
long long int w,b;
scanf("%d",&t);
while(t--)
{
scanf("%lld%lld",&w,&b);
if(!(b&1))
printf("0.000000\n");
else
printf("1.000000\n");
}
return 0;
}