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
#define VI vector<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
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

#define MAXR 305
#define INF 99999999

char buff[MAXR][MAXR];
int arr[MAXR][MAXR];
int r,c,k;
int ans;


void solve()
{
    int i,j;
    int st;
    int ct;
    int en;

    for(i=1;i<=r;++i)
    {
        for(j=i;j<=r;++j)
        {
            st=1;
            en=0;
            ct=0;

            while(true)
            {
                for(++en;en<=c;++en)
                {
                    ct+=arr[j][en]-arr[i-1][en];
                    if(ct>=k)
                    {
                        break;
                    }
                }

                while(ct>=k && st<=en)
                {
                    ans=min(ans,(j-i+1)*(en-st+1));
                    ct-=(arr[j][st]-arr[i-1][st]);
                    ++st;
                }

                //printf("%d\t%d\t%d\t%d\t%d\n",ans,i,j,st,en);

                if(en>=c)
                {
                    break;
                }
            }
        }
    }
}



void MAIN()
{
    int i,j;
    while(true)
    {
        ans=INF;
        //scanf("%d %d %d",&r,&c,&k);
        cin>>r>>c>>k;
        //printf("%d\t%d\t%d\n",r,c,k);
        if(r+c+k==0)
        {
            break;
        }

        for(i=1;i<=r;++i)
        {
            scanf("%s",&buff[i][1]);
            //gets(&buff[i][1]);
            for(j=1;j<=c;++j)
            {
                arr[i][j]=arr[i-1][j];
                if(buff[i][j]=='.')
                {
                    ++arr[i][j];
                }
            }
            //printf("%s\n",buff[i][1]);
            //cout<<buff[i]+1<<endl;
        }

        if(k==1)
        {
            ans=1;
        }
        else
        {
            solve();
        }

        printf("%d\n",ans);
    }
}

int main()
{
	freopen("Text/FSEATS.txt","r",stdin);

    MAIN();

	return 0;
}

