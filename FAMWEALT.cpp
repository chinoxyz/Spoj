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

#define MAXN 1000006


double arr[MAXN];

int lca(int x,int y)
{
    if(x<y)
    {
        swap(x,y);
    }

    while(x!=y)
    {
        while(x>y)
        {
            x/=2;
        }

        swap(x,y);
    }

    return x;
}

void gett(int x,int y)
{

    //cout<<arr[x]<<endl;
    if(x==y)
    {
        //printf("Y\t%d\t%f\n",x,arr[x]);
        return;
    }

    int par=x/2;

    gett(par,y);

    if( (x&1) && (par&1))
    {
        arr[x]=arr[par]/4.0;
    }
    else if((x&1) && !(par&1))
    {
        arr[x]=arr[par]/2.0;
    }
    else if(!(x&1) && (par&1))
    {
        arr[x]=arr[par]/2.0;
    }
    else
    {
        arr[x]=arr[par]/2.0;
    }

    //printf("Y\t%d\t%f\n",x,arr[x]);


}


int main()
{
    freopen("Text/FAMWEALT.txt","r",stdin);

    int cases;
    int x,y;
    double w;

    //scanf("%d",&cases);
    cin>>cases;
    int par;
    int midd;

    while(cases--)
    {
        //MSET(arr,0);
        //scanf("%d %d %f",&x,&y,&w);
        cin>>x>>y>>w;

        midd=lca(x,y);
        arr[x]=w;

        while(x>midd)
        {
            par=x/2;
            if((x&1) && (par&1))
            {
                arr[par]=4*arr[x];
            }
            else if((x&1) && !(par&1))
            {
                arr[par]=2*arr[x];
            }
            else if(!(x&1) && (par&1))
            {
                arr[par]=2*arr[x];
            }
            else
            {
                arr[par]=2*arr[x];
            }

            //printf("X\t%d\t%d\n",x,par);
            x=par;
            //cout<<arr[x]<<endl;
            //printf("X\t%d\t%f\n",x,arr[x]);
        }

        //cout<<arr[x]<<endl;
        //printf("X\t%d\t%f\n",x,arr[x]);


        gett(y,midd);



        printf("%.6f\n",arr[y]);


    }



    return 0;
}

