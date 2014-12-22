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
#include <cassert>
#include<cmath>


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
#define Vi64 vector<i64>
#define Vu64 vector<u64>


int n;
i64 arr[4][4];
i64 ans;

bool isEven(int x)
{
    return ((x%2)==0);
}

void MAIN()
{
    int cases;
    scanf("%d",&cases);
    int ct=0;
    int x,y;
    int i,j,k,l;

    while(cases--)
    {
        MSET(arr,0);
        ans=0;

        scanf("%d",&n);
        for(i=0;i<n;++i)
        {
            scanf("%d %d",&x,&y);

            if(x>0 && y>0)
            {
                if(isEven(x) && isEven(y))
                {
                    ++arr[0][0];
                }
                else if(isEven(x) && !isEven(y))
                {
                    ++arr[0][1];
                }
                else if(!isEven(x) && isEven(y))
                {
                    ++arr[0][2];
                }
                else
                {
                    ++arr[0][3];
                }
            }
            else if(x>0 && y<0)
            {
                if(isEven(x) && isEven(y))
                {
                    ++arr[1][0];
                }
                else if(isEven(x) && !isEven(y))
                {
                    ++arr[1][1];
                }
                else if(!isEven(x) && isEven(y))
                {
                    ++arr[1][2];
                }
                else
                {
                    ++arr[1][3];
                }
            }
            else if(x<0 && y<0)
            {
                if(isEven(x) && isEven(y))
                {
                    ++arr[2][0];
                }
                else if(isEven(x) && !isEven(y))
                {
                    ++arr[2][1];
                }
                else if(!isEven(x) && isEven(y))
                {
                    ++arr[2][2];
                }
                else
                {
                    ++arr[2][3];
                }
            }
            else if(x<0 && y>0)
            {
                if(isEven(x) && isEven(y))
                {
                    ++arr[3][0];
                }
                else if(isEven(x) && !isEven(y))
                {
                    ++arr[3][1];
                }
                else if(!isEven(x) && isEven(y))
                {
                    ++arr[3][2];
                }
                else
                {
                    ++arr[3][3];
                }
            }
        }

        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
            {
                for(k=0;k<4;++k)
                {
                    for(l=0;l<4;++l)
                    {
                        ct=0;

                        if(i==j)
                        {
                            ++ct;
                        }

                        if(j==k)
                        {
                            ++ct;
                        }

                        if(k==l)
                        {
                            ++ct;
                        }

                        if(l==i)
                        {
                            ++ct;
                        }

                        if(isEven(ct))
                        {
                            ans+=arr[0][i]*arr[1][j]*arr[2][k]*arr[3][l];
                        }
                    }
                }
            }
        }

        printf("%lld\n",ans);

    }
}

int main()
{
	freopen("Text/CHEFMAY.txt","r",stdin);

    MAIN();

	return 0;
}

