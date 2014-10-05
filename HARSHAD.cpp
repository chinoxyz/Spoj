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
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXX 1000007

int deva[MAXX];
VI dev_prime;

void sieveee()
{

	bool primes[MAXX];
	int rootn,i,j;
	rootn=sqrt(MAXX)+100;

	for(i=0;i<MAXX;i++)
	{
		primes[i]=1;
	}

	//printf("DdD\n");

	for(i=2;i<rootn;i++)
	{
		if(primes[i]==1)
		{
			for(j=(i*i);j<MAXX;j=j+i)
            {
                primes[j]=0;
            }
		}
	}




	for(i=2;i<MAXX;i++)
    {
        if(primes[i]&&deva[i]==0)
        {
            dev_prime.PB(i);
        }
    }

}



int main()
{
	freopen("Text/HARSHAD.txt","r",stdin);


	for(int i=0; i<MAXX; i++)
    {
        deva[i]=0;
    }

	for(int i=0; i<MAXX; i++)
	{
		int temp=i,summ=0;
		while(temp!=0)
		{
			summ=summ+temp%10;
			temp/=10;
		}
		if(summ+i<MAXX)
        {
            deva[summ+i]=1;
        }
	}




	sieveee();


	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		//printf("%d\t%d\n",x,y);
		printf("%d\n",(int)(lower_bound(dev_prime.begin(),dev_prime.end(),y+1)-lower_bound(dev_prime.begin(),dev_prime.end(),x)));
	}
	return 0;
}
