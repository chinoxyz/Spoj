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

#define INF 999999999

#define MAXX 18
int width,height;
char arr[MAXX][MAXX];

bool vis[MAXX][1<<MAXX];
int data[MAXX];
int minn;


int s_bitcount(int set1)
{
    int ret=0;

    ret=(set1&0x55555555) + ((set1>>1) & 0x55555555);
    ret=(ret&0x33333333) + ((ret>>2) & 0x33333333);
    ret=(ret&0x0F0F0F0F) + ((ret>>4) & 0x0F0F0F0F);
    ret=(ret&0x00FF00FF) + ((ret>>8) & 0x00FF00FF);
    ret=(ret&0x0000FFFF) + ((ret>>16));

    return ret;
}


void solve(int level,int compulsory,int prevv,int cnt)
{
    //printf("%d\t%d\t%d\t%d\n",level,compulsory,prevv,cnt);

    if(level<0)
    {
        if(compulsory==0)
        {
            minn=min(minn,cnt);
        }

        return;
    }

    int tt=s_bitcount(compulsory);
    cnt+=tt;


    int init=data[level];

    for(int i=0;i<width;++i)
    {
        if(prevv &(1<<i))
        {
            init^=(1<<i);
        }
    }


    for(int i=0;i<width;++i)
    {
        if(compulsory & (1<<i))
        {
            if(i>0)
            {
                init^=(1<<(i-1));
            }
            init^=(1<<i);

            if(i<(width-1))
            {
                init^=(1<<(i+1));
            }
        }
    }

    int nxt_com=init;

    solve(level-1,nxt_com,compulsory,cnt);


}






int main()
{

    freopen("Text/CERC07B.txt","r",stdin);


    while(true)
    {
        scanf("%d %d",&height,&width);
        //printf("%d\t%d\n",height,width);

        if(height==0 || width==0)
        {
            break;
        }

        minn=INF;

        MSET(vis,0);
        MSET(data,0);


        for(int i=0;i<height;++i)
        {
            scanf("%s",&arr[i]);
            //printf("%s\n",arr[i]);

            for(int j=0;j<width;++j)
            {
                if(arr[i][j]=='X')
                {
                    data[i]|=(1<<j);
                }
            }
        }


        for(int i=0;i<(1<<width);++i)
        {
            solve(height-1,i,0,0);
        }

        if(minn==INF)
        {
            printf("Damaged billboard.\n");
        }
        else
        {
            printf("You have to tap %d tiles.\n",minn);
        }

    }



    return 0;
}
