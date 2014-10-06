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


#define MAXN 205

char arr[MAXN][MAXN];
int n,m,k;
int han=0,gret=0;
char ans,pree;
int ct,x,y,dx,dy;

bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    {
        return false;
    }

    return true;
}

void solve()
{
    ans='.';

    ct=0;
    for(int i=0;i<n;++i)
    {
        ct=0;
        pree='.';
        for(int j=0;j<m;++j)
        {
            if(arr[i][j]==pree)
            {
                ++ct;
            }
            else
            {
                if(ct>=k && pree!='.')
                {
                    ans=pree;
                }
                ct=1;
                pree=arr[i][j];
            }
        }

        if(ct>=k && pree!='.')
        {
            ans=pree;
        }
    }


    ct=0;
    for(int i=0;i<m;++i)
    {
        ct=0;
        pree='.';
        for(int j=0;j<n;++j)
        {
            if(arr[j][i]==pree)
            {
                ++ct;
            }
            else
            {
                if(ct>=k && pree!='.')
                {
                    ans=pree;
                }
                ct=1;
                pree=arr[j][i];
            }
        }

        if(ct>=k && pree!='.')
        {
            ans=pree;
        }
    }

    dx=-1;
    dy=1;
    for(int i=0;i<n;++i)
    {
        pree='.';
        ct=0;
        x=i;
        y=0;
        //for(int j=0;j<=min(i,m-1);++j)
        while(is_valid(x,y))
        {
            if(arr[x][y]==pree)
            {
                ++ct;
            }
            else
            {
                if(ct>=k && pree!='.')
                {
                    ans=pree;
                }
                ct=1;
                pree=arr[x][y];
            }

            x+=dx;
            y+=dy;
        }

        if(ct>=k && pree!='.')
        {
            ans=pree;
        }
    }



    for(int i=0;i<m;++i)
    {
        pree='.';
        ct=0;
        x=n-1;
        y=i;
        //for(int j=0;j<=min(n-i-1,m-1);++j)
        while(is_valid(x,y))
        {
            if(arr[x][y]==pree)
            {
                ++ct;
            }
            else
            {
                if(ct>=k && pree!='.')
                {
                    ans=pree;
                }
                ct=1;
                pree=arr[x][y];
            }

            x+=dx;
            y+=dy;
        }

        if(ct>=k && pree!='.')
        {
            ans=pree;
        }
    }












    dx=1;
    dy=1;
    for(int i=0;i<n;++i)
    {
        pree='.';
        ct=0;
        x=i;
        y=0;
        //for(int j=0;j<=min(n-i-1,m-1);++j)
        while(is_valid(x,y))
        {
            if(arr[x][y]==pree)
            {
                ++ct;
            }
            else
            {
                if(ct>=k && pree!='.')
                {
                    ans=pree;
                }
                ct=1;
                pree=arr[x][y];
            }

            x+=dx;
            y+=dy;
        }

        if(ct>=k && pree!='.')
        {
            ans=pree;
        }
    }




    for(int i=0;i<m;++i)
    {
        pree='.';
        ct=0;
        x=0;
        y=i;
        //for(int j=0;j<=min(m-i-1,n-1);++j)
        while(is_valid(x,y))
        {
            if(arr[x][y]==pree)
            {
                ++ct;
            }
            else
            {
                if(ct>=k && pree!='.')
                {
                    ans=pree;
                }
                ct=1;
                pree=arr[x][y];
            }

            x+=dx;
            y+=dy;
        }

        if(ct>=k && pree!='.')
        {
            ans=pree;
        }
    }









    if(ans=='x')
    {
        ++han;
    }
    else if(ans=='o')
    {
        ++gret;
    }
}


int main()
{
    freopen("Text/KROW.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&m,&n,&k);

        for(int i=0;i<n;++i)
        {
            scanf("%s",&arr[i]);
        }

        solve();
    }

    printf("%d:%d\n",han,gret);

    return 0;
}
