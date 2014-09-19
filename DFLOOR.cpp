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


#define MAXX 17
int width,height;
char arr[MAXX][MAXX];

bool vis[16][1<<16];
bool poss;

int data[MAXX];
VI pp;


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




bool solve(int level,int compulsory,int prevv,int cnt)
{
    //printf("%d\t%d\t%d\t%d\n",level,compulsory,prevv,cnt);
    if(level<0)
    {
        if(compulsory==0)
        {
            printf("%d\n",cnt);
            //printf("%d\t%d\t%d\t%d\n",level,compulsory,prevv,cnt);
            return true;
        }
        else
        {
            return false;
        }
    }

    int tt=s_bitcount(compulsory);
    //printf("%d\n",tt);
    cnt+=tt;

    int init=data[level];

    for(int i=0;i<width;++i)
    {
        if(prevv&(1<<i))
        {
            init^=(1<<i);
        }
    }

    for(int i=0;i<width;++i)
    {
        if(compulsory&(1<<i))
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

    //printf("INIt\t%d\n",init);

    if(vis[level][init])
    {
        //return false;
    }

    vis[level][init]=true;


    int nxt_com=((1<<width)-1)^init;

    if(solve(level-1,nxt_com,compulsory,cnt))
    {
        //printf("%d\t%d\t%d\t%d\n",level,compulsory,prevv,cnt);
        for(int j=0;j<width;++j)
        {
            if(compulsory&(1<<j))
            {
                printf("%d %d\n",j+1,level+1);
                //pp.PB(j+1);
                //pp.PB(level+1);
            }
        }


        return true;
    }

    return false;

}

int main(){

    freopen("Text/DFLOOR.txt","r",stdin);

    while(true)
    {
        scanf("%d %d",&width,&height);

        if(height==0 || width==0)
        {
            break;
        }

        MSET(vis,0);
        MSET(data,0);
        poss=false;
        pp.clear();

        for(int i=0;i<height;++i)
        {
            scanf("%s",&arr[i]);

            for(int j=0;j<width;++j)
            {
                if(arr[i][j]=='1')
                {
                    data[i]|=(1<<j);
                }
            }

            //printf("DD\t%d\n",data[i]);
        }

        //printf("%d\n",s_bitcount(99));

        for(int i=0;i<(1<<width);++i)
        {
            if(solve(height-1,i,0,0))
            {
                poss=true;
/*
                for(int j=0;j<width;++j)
                {
                    if(i&(1<<j))
                    {
                        printf("%d %d\n",i,j);
                    }
                }
*/

/*

                for(int j=pp.size()-1;j>0;j-=2)
                {
                    printf("%d %d\n",pp[j-1],pp[j]);
                }

*/
                break;
            }
        }

        if(!poss)
        {
            printf("-1\n");
        }

        printf("\n");

    }


    return 0;
}
