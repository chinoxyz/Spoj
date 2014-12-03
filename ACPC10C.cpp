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

#define MAXN 32008
char arr[MAXN];
int n;
int visd[MAXN];
int md;
int vd[MAXN];
int nodes[MAXN];
VI child[MAXN];
int mp;
int depth[MAXN];

int solve(int l,int r,int dp)
{
    int cn=mp;
    depth[cn]=dp;
    md=max(dp,md);

    if(l==r)
    {
        if(arr[l]=='T')
        {
            nodes[mp]=1;
        }
        else
        {
            nodes[mp]=0;
        }

        ++mp;
        return (mp-1);
    }

    int ll=l+1;
    int ct=0;
    ++mp;
    int ti;
    int ti2;

    while(ll<=r)
    {
        if(arr[ll]=='(')
        {
            ti=ll;
            ++ll;
            ct=1;

            while(ct && ll<=r)
            {
                if(arr[ll]=='(')
                {
                    ++ct;
                }
                else if(arr[ll]==')')
                {
                    --ct;
                }
                ++ll;
            }

            --ll;
            ti2=solve(ti,ll,dp+1);
            child[cn].PB(ti2);

        }
        else if(arr[ll]!=')')
        {
            ti2=solve(ll,ll,dp+1);
            child[cn].PB(ti2);
        }
        ++ll;
    }

    return cn;
}


int main()
{
    freopen("Text/ACPC10C.txt","r",stdin);

    int cases=0;
    int i;
    int j,ti,v;

    while(true)
    {
        //MSET(visd,0);
        //MSET(vd,0);
        md=0;
        //MSET(nodes,0);
        //MSET(depth,0);




        mp=0;
        ++cases;
        scanf("%s",arr+1);
        if(strcmp(arr+1,"()\0")==0)
        {
            break;
        }
        n=strlen(arr+1);
        arr[0]='(';
        arr[n+1]=')';
        arr[n+2]='\0';
        n+=2;
        //printf("%s\n",arr);

        for(i=0;i<n;++i)
        {
            child[i].clear();
        }

        solve(0,n-1,0);

        ti=0;
        for(i=md-1;i>=0;--i)
        {
            vd[i]=ti;
            ti^=1;
        }

        for(i=mp-1;i>=0;--i)
        {
            if(child[i].size())
            {
                v=nodes[child[i][0]];

                if(vd[depth[i]])
                {
                    for(j=1;j<child[i].size();++j)
                    {
                        v|=nodes[child[i][j]];
                    }
                }
                else
                {
                    for(j=1;j<child[i].size();++j)
                    {
                        v&=nodes[child[i][j]];
                    }
                }

                nodes[i]=v;
            }


        }

        printf("%d. ",cases);

        if(nodes[0])
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }


    return 0;
}
