#include <cstdio>
#include <iostream>
#include<bitset>
using namespace std;
#define MAXN 1000000
bitset<MAXN> bs;
int main()
{
    int p1,p2,p3,p4,p5,p6,n=0,ti,s1,s2,s3,s4,s5;
    for(p6=0;p6<10;++p6){for(p5=0;p5<10;++p5){s1=p5+p6;for(p4=0;p4<10;++p4){s2=s1+p4;for(p3=0;p3<10;++p3){s3=s2+p3;for(p2=0;p2<10;++p2){s4=p2+s3;for(p1=0;p1<10;++p1){s5=s4+p1;ti=s5+n;if(ti<MAXN){bs.set(ti);}++n;}}}}}}for(p1=1;p1<MAXN;++p1){if(!bs.test(p1)){printf("%d\n",p1);}}return 0;}
