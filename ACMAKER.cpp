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


#define MAXN 95

#define MAXL 152

int dp[MAXN][MAXN][MAXN];

set<string> insignificant;

string abbr;
VS letters;
char buff[MAXL];
int num_insig;



inline void solve()
{
    MSET(dp,0);
    dp[0][0][0]=1;

	int i,j,k,l;
	int s1,s2,s3,s4,s5;
	s1=letters.size();
	s3=abbr.size();
    for(i=0;i<s1;++i)
    {
        s2=letters[i].size();
        for(j=0;j<s2;++j)
        {
            for(k=i;k<s3;++k)
            {
                if(abbr[k]==letters[i][j])
                {
                    if(i==0)
                    {
                        dp[k+1][i+1][j+1]+=dp[k][i][0];
                    }
                    else
                    {
                        s4=letters[i-1].size();
                        for(l=1;l<=s4;++l)
                        {
                            dp[k+1][i+1][j+1]+=dp[k][i][l];
                        }
                    }

                    for(l=1;l<=j;++l)
                    {
                        dp[k+1][i+1][j+1]+=dp[k][i+1][l];
                    }

                    //printf("%d\t%d\t%d\t%d\n",k+1,i+1,dp[k+1][i+1],j+1);
                }
            }
        }
    }

    int ans=0;

    s5=letters[s1-1].size();
    for(i=1;i<=s5;++i)
    {
        ans+=dp[s3][s1][i];
    }

    if(ans==0)
    {
        printf("%s is not a valid abbreviation\n",abbr.c_str());
    }
    else
    {
        printf("%s can be formed in %d ways\n",abbr.c_str(),ans);
    }
}

int main()
{
    freopen("Text/ACMAKER.txt","r",stdin);

    string ts;
    int i,j;


    while(true)
    {
        scanf("%d\n",&num_insig);

        if(num_insig==0)
        {
            break;
        }

        insignificant.clear();


        for(i=0;i<num_insig;++i)
        {
            gets(buff);

            for(j=0;j<strlen(buff);++j)
            {
                buff[j]=toupper(buff[j]);
            }
            string str(buff);
            insignificant.insert(str);
            //printf("INS\tXX%sXX\n",str.c_str());
        }

        while(true)
        {
            letters.clear();
            gets(buff);

            if(strcmp(buff,"LAST CASE")==0)
            {
                break;
            }

            stringstream sstream(buff);
            sstream>>abbr;

            //printf("ABBR\tXX%sXX\n",abbr.c_str());

            while(!sstream.eof())
            {
                sstream>>ts;
                for(j=0;j<ts.size();++j)
                {
                    ts[j]=toupper(ts[j]);
                }

                if(insignificant.count(ts)==0)
                {
                    //printf("LE\tXX%sXX\n",ts.c_str());
                    letters.PB(ts);
                }
            }

            solve();

        }
    }



    return 0;
}
