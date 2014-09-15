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


#define INF 999999999
#define MAXX 93

int dp[MAXX][MAXX];
int num_keys,num_letters;
int freq[MAXX];
char keys[MAXX];
char letters[MAXX];
int last[MAXX][MAXX];
int sum_freq;
int letters_ct[MAXX];


void solve()
{

    int one,two;

    for(int i=1;i<=num_letters;++i)
    {
        dp[0][i]=INF;
    }
    for(int i=1;i<=num_keys;++i)
    {
        for(int j=0;j<=num_letters;++j)
        {
            if(j<i)
            {
                dp[i][j]=INF;
                continue;
            }

/*
            one=dp[i-1][j-1]+freq[j];
            two=dp[i][j-1]+(last[i][j-1]+1)*freq[j];

            if(one<two)
            {
                dp[i][j]=one;
                last[i][j]=1;
            }
            else
            {
                dp[i][j]=two;
                last[i][j]=last[i][j-1]+1;
            }
*/

            dp[i][j]=INF;

            for(int k=j-i+1;k>=1;--k)
            {
                one=dp[i-1][j-k];

                for(int tt=1;tt<=k;++tt)
                {
                    one+=(tt*freq[j-k+tt]);
                }
                if(dp[i][j]>one)
                {
                    dp[i][j]=one;
                    last[i][j]=k;
                }
            }

            //printf("%d\n",dp[i][j]);
        }
        //printf("\n\n\n\n\n");
    }
/*

    for(int i=0;i<=num_keys;++i)
    {
        for(int j=0;j<=num_letters;++j)
        {
            printf("%d\n",dp[i][j]);
        }
        printf("\n\n\n\n\n");
    }
*/

    //printf("%d\n",dp[num_keys][num_letters]);
}

int main()
{
    freopen("Text/IKEYB.txt","r",stdin);
    int cases,st,x,y,z;

    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        MSET(last,0);
        sum_freq=0;
        scanf("%d %d",&num_keys,&num_letters);
        scanf("%s %s",keys,letters);

        for(int i=1;i<=num_letters;++i)
        {
            scanf("%d",freq+i);
            sum_freq+=freq[i];
        }

        solve();
        //printf("SUM FREQ\t%d\n",sum_freq);

            x=num_keys;
            y=num_letters;

            for(int j=num_keys;j>0;--j)
            {
                z=last[x][y];
                //printf("ZZZZZZZZZZZ\t%d\n",z);
                letters_ct[x-1]=z;
                --x;
                y-=z;
            }

        printf("Keypad #%d:\n",t);
        st=0;

        for(int i=0;i<num_keys;++i)
        {
            printf("%c: ",keys[i]);

            for(int j=0;j<letters_ct[i];++j)
            {
                printf("%c",letters[st+j]);
            }
            st+=letters_ct[i];


            printf("\n");
        }
        printf("\n");

    }


    return 0;
}


