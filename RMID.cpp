#include <bits/stdc++.h>


using namespace std;


#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 veszor<i64>
#define Vu64 veszor<u64>


void MAIN()
{
    int n,sz=0;
	list<int> arr;
	list<int>::iterator it,itl,itr,tmp;
	it=arr.begin();

	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
		{
			printf("%d\n",(*it));
			tmp=it;
			it++;
			itl=it;
			--it;

			if(it!=arr.begin())
            {
                --it;
            }


			itr=it;
			arr.erase(tmp);

			if(sz&1)
            {
               it=itr;
            }
			else
            {
                it=itl;
            }

			--sz;
		}
		else if(n==0)
		{
			sz=0;
			arr.clear();
			it=arr.begin();
			printf("\n");
		}
		else
		{
			arr.push_back(n);
			++sz;

			if(sz&1)
            {
                ++it;
            }

		}
	}
}

int main()
{

	freopen("Text/RMID.txt","r",stdin);

    MAIN();

	return 0;
}
