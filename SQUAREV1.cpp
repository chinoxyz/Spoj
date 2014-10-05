#include<cmath>
#include <iostream>
using namespace std;
int main()
{int i=0,s,n,j,a,t;for(;i<50;++i){a=0;cin>>n;s=sqrt(n/2);for(j=0;j<=s;++j){t=sqrt(n-(j*j));if((t*t+j*j)==n){++a;}}cout<<a<<"\n";}return 0;}

