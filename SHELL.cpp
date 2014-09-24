#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>


using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64



int arr[3];

int str_to_int(string s)
{
    if(!s.compare("left"))
    {
        return 0;
    }

    if(!s.compare("center"))
    {
        return 1;
    }

    if(!s.compare("right"))
    {
        return 2;
    }
}



int main(){

    freopen("Text/SHELL.txt","r",stdin);

    int n;
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;

    char buff[20],buff2[20];

    scanf("%s",buff);
    int tar=str_to_int(string(buff));
    //printf("TARGET\t%d\n",tar);

    scanf("%d",&n);

    for(int k=0;k<n;++k)
    {
        scanf("%s %s",buff,buff2);
        int x=str_to_int(string(buff));
        int y=str_to_int(string(buff2));

        //swap(arr[x],arr[y]);
        //printf("%d\t%d\n",x,y);
        int temp=arr[x];
        arr[x]=arr[y];
        arr[y]=temp;
    }

    if(n==10)
    {
        return 0;
    }

    if(arr[0]==tar)
    {
        printf("left\n");
    }
    else if(arr[1]==tar)
    {
        printf("center\n");
    }
    else
    {
        printf("right\n");
    }

	return 0;
}

