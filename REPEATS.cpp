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

#define MAXN 50010


char str[MAXN];
int rankk[MAXN],SA[MAXN];

bool bh[MAXN],b2h[MAXN];
int longest_common_prefix[MAXN],nextt[MAXN],ct[MAXN];

int f[MAXN][20],logg2[MAXN];


bool smaller_first_char(int a,int b)
{
    return str[a]<str[b];
}


void suffix_sort(int n)
{
    int i;
    int j,buckets;
    REP(i,n)
    {
        SA[i]=i;
    }

    sort(SA,SA+n,smaller_first_char);


    REP(i,n)
    {
        bh[i]= i==0 || str[SA[i-1]]!=str[SA[i]];
        b2h[i]=false;
    }

    for(int h=1;h<n;h<<=1)
    {
        buckets=0;
        for(i=0,j=0;i<n;i=j)
        {
            j=i+1;
            while(j<n && !bh[j])
            {
                ++j;
            }
            nextt[i]=j;
            ++buckets;
        }

        if(buckets==n)
        {
            break;
        }

        for(i=0;i<n;i=nextt[i])
        {
            ct[i]=0;
            for(j=i;j<nextt[i];++j)
            {
                rankk[SA[j]]=i;
            }
        }

        ct[rankk[n-h]]++;
        b2h[rankk[n-h]]=true;

        for(i=0;i<n;i=nextt[i])
        {
            for(j=i;j<nextt[i];++j)
            {
                int s=SA[j]-h;

                if(s>=0)
                {
                    int head=rankk[s];
                    rankk[s]=head+ct[head]++;
                    b2h[rankk[s]]=true;
                }
            }

            for(j=i;j<nextt[i];++j)
            {
                int s=SA[j]-h;
                if(s>=0 && b2h[rankk[s]])
                {
                    for(int k=rankk[s]+1;!bh[k] && b2h[k];++k)
                    {
                        b2h[k]=false;
                    }
                }
            }
        }

        REP(i,n)
        {
            SA[rankk[i]]=i;
            bh[i]|=b2h[i];
        }

    }

    REP(i,n)
    {
        rankk[SA[i]]=i;
    }
}



void calc_longest_common_prefix(int n)
{
    int h,i,j;
    REP(i,n)
    {
        rankk[SA[i]]=i;
    }
    longest_common_prefix[0]=0;

    for(i=0,h=0;i<n;++i)
    {
        if(rankk[i]>0)
        {
            j=SA[rankk[i]-1];
            while(i+h<n && j+h<n && str[i+h]==str[j+h])
            {
                ++h;
            }

            longest_common_prefix[rankk[i]]=h;
            if(h>0)
            {
                --h;
            }
        }
    }

}


void rmq(int n){
     int i,j;
     for (i=1;i<=n;i++)
       f[i][0]=longest_common_prefix[i];
     for (j=1;j<20;j++)
         for (i=1;i+(1<<j)-1<=n;i++)
         f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
     return;
}


int lcp(int a,int b){
    int x=rankk[a],y=rankk[b];
    if (x>y) {int t=x; x=y; y=t;}
    x++;
    int t=logg2[y-x+1];
    return min(f[x][t],f[y-(1<<t)+1][t]);
}


void solve(int n){
     int l,i,k,max=0,r=0,t;
     for (l=1;l<n;l++)
         for (i=0;i+l<n;i+=l){
             k=lcp(i,i+l);
             r=k/l+1;
             t=i-(l-k%l);
             if (t>=0)
                if (lcp(t,t+l)>=k) r++;
             if (r>max)
               max=r;
         }
     printf("%d\n",max);
     return;
}
int main()
{
    freopen("Text/REPEATS.txt","r",stdin);

    int i,cases,n;
    char x;

    for(int i=0;i<MAXN;++i)
    {
        //logg2[i]=log2(i);
        logg2[i]=int(double(log(i))/log(2.00));
    }

    scanf("%d",&cases);
    //printf("CASES\t%d\n",cases);


    while(cases--)
    {
        MSET(longest_common_prefix,0);
        MSET(rankk,0);
        MSET(ct,0);
        MSET(bh,0);
        MSET(b2h,0);
        MSET(SA,0);
        MSET(nextt,0);
        MSET(str,0);
        MSET(f,0);



        scanf("%d\n",&n);
        //printf("N\t%d\n",n);

        for(int i=0;i<n;++i)
        {
            scanf("%c\n",&x);
            str[i]=x;
        }
        str[n]=0;

        //printf("Str\t%s\n",str);

        suffix_sort(n);
        calc_longest_common_prefix(n);


        for(int i=0;i<n;++i)
        {
            ++rankk[i];
        }

        for(int i=n;i>0;--i)
        {
            SA[i]=SA[i-1];
            longest_common_prefix[i]=longest_common_prefix[i-1];
        }
        SA[0]=n;

/*
        for(int i=0;i<=n;++i)
        {
            printf("%d\t%d\t%d\n",rankk[i],SA[i],longest_common_prefix[i]);
        }
*/


        rmq(n);
        solve(n);
    }

    return 0;
}
