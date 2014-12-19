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

class compp
{
public :
    bool operator()(int a,int b)
    {
        return a>b;
    }
};

void MAIN()
{
    int n,sz=0;

	int cases;
	scanf("%d",&cases);


	while(cases--)
	{
	    priority_queue<int> leftt;
        priority_queue<int,vector<int>,compp> rightt;
	    while(true)
	    {
	        scanf("%d",&n);
	        if(n==-1)
            {
                printf("%d\n",leftt.top());
                leftt.pop();

                if(sz>1 && !(sz&1))
                {
                    leftt.push(rightt.top());
                    rightt.pop();
                }

                --sz;
            }
            else if(n==0)
            {
                sz=0;
                printf("\n");
                break;
            }
            else
            {
                if(sz==0)
                {
                    leftt.push(n);
                }
                else if(sz&1)
                {
                    if(n>=leftt.top())
                    {
                        rightt.push(n);
                    }
                    else
                    {
                        leftt.push(n);
                        rightt.push(leftt.top());
                        leftt.pop();
                    }
                }
                else
                {
                    if(n<=leftt.top())
                    {
                        leftt.push(n);
                    }
                    else
                    {
                        rightt.push(n);
                        leftt.push(rightt.top());
                        rightt.pop();
                    }
                }
                ++sz;
            }
	    }

	}
}

int main()
{

	freopen("Text/RMID2.txt","r",stdin);

    MAIN();

	return 0;
}
