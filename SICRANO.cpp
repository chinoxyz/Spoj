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
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MAXX 51


int points[MAXX][2];
int seg[MAXX][6];


bool checkk(int linee,int pt)
{
    int dx1=seg[linee][4];
    int dy1=seg[linee][5];
    int dx2=seg[linee][0]-points[pt][0];
    int dy2=seg[linee][1]-points[pt][1];

    if (!(dx1*dy2==dx2*dy1))
    {
        return false;
    }

    int x1=min(seg[linee][0],seg[linee][2]);
    int x2=max(seg[linee][0],seg[linee][2]);
    int y1=min(seg[linee][1],seg[linee][3]);
    int y2=max(seg[linee][1],seg[linee][3]);

    if(points[pt][0]>=x1 && points[pt][0]<=x2 && points[pt][1]>=y1 && points[pt][1]<=y2)
    {
        return true;
    }

    return false;
}


int main()
{
    freopen("Text/SICRANO.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int n,m;
    int x1,y1,x2,y2;
    int ct;
    double ti;

    while(cases--)
    {
        //scanf("%d %d",&n,&m);
        cin>>n>>m;

        for(int i=0;i<n;++i)
        {
            //scanf("%d %d",&points[i][0],&points[i][1]);
            cin>>points[i][0]>>points[i][1];
        }

        for(int i=0;i<m;++i)
        {
            //scanf("%d %d %d %d",&seg[i][0],&seg[i][1],&seg[i][2],&seg[i][3]);
            cin>>seg[i][0]>>seg[i][1]>>seg[i][2]>>seg[i][3];
            seg[i][4]=seg[i][0]-seg[i][2];
            seg[i][5]=seg[i][1]-seg[i][3];
        }

        for(int i=0;i<m;++i)
        {
            ct=0;

            for(int j=0;j<n;++j)
            {
                if(checkk(i,j))
                {
                    ++ct;
                }
            }

            printf("%d\n",ct);
        }
    }


    return 0;
}
