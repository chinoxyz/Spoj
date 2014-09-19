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


#define MAXN 10005
#define INF 99999999

char tree[MAXN];
int node_num;

int left_child[MAXN],right_child[MAXN];
int dpmax[MAXN][3];
int dpmin[MAXN][3];
int pos=0;

int make_tree()
{
    if(tree[pos]=='0')
    {
        ++node_num;
        ++pos;
        return (node_num-1);
    }

    if(tree[pos]=='1')
    {
        int curr=node_num;
        ++node_num;

        ++pos;
        left_child[curr]=make_tree();
        return curr;
    }

    if(tree[pos]=='2')
    {
        int curr=node_num;
        ++node_num;
        ++pos;
        left_child[curr]=make_tree();
        right_child[curr]=make_tree();
        return curr;
    }
}













int solve_max(int curr,int col)
{
    if(curr>=node_num || curr<0)
    {
        return 0;
    }

    if(dpmax[curr][col]!=-1)
    {
        return dpmax[curr][col];
    }

    int &ret=dpmax[curr][col];
    ret=0;

    if(col==0)
    {
        if(left_child[curr]!=-1 && right_child[curr]!=-1)
        {
            ret=max(ret,1+solve_max(left_child[curr],1)+solve_max(right_child[curr],2));
            ret=max(ret,1+solve_max(left_child[curr],2)+solve_max(right_child[curr],1));
        }
        else if(left_child[curr]!=-1)
        {
            ret=max(ret,1+solve_max(left_child[curr],1));
            ret=max(ret,1+solve_max(left_child[curr],2));
        }
        else if(right_child[curr]!=-1)
        {
            ret=max(ret,1+solve_max(right_child[curr],1));
            ret=max(ret,1+solve_max(right_child[curr],2));
        }
        else
        {
            ret=1;
        }
    }
    else if(col==1)
    {
        if(left_child[curr]!=-1 && right_child[curr]!=-1)
        {
            ret=max(ret,solve_max(left_child[curr],0)+solve_max(right_child[curr],2));
            ret=max(ret,solve_max(left_child[curr],2)+solve_max(right_child[curr],0));
        }
        else if(left_child[curr]!=-1)
        {
            ret=max(ret,solve_max(left_child[curr],0));
            ret=max(ret,solve_max(left_child[curr],2));
        }
        else if(right_child[curr]!=-1)
        {
            ret=max(ret,solve_max(right_child[curr],0));
            ret=max(ret,solve_max(right_child[curr],2));
        }
        else
        {
            ret=0;
        }
    }
    else
    {
        if(left_child[curr]!=-1 && right_child[curr]!=-1)
        {
            ret=max(ret,solve_max(left_child[curr],0)+solve_max(right_child[curr],1));
            ret=max(ret,solve_max(left_child[curr],1)+solve_max(right_child[curr],0));
        }
        else if(left_child[curr]!=-1)
        {
            ret=max(ret,solve_max(left_child[curr],0));
            ret=max(ret,solve_max(left_child[curr],1));
        }
        else if(right_child[curr]!=-1)
        {
            ret=max(ret,solve_max(right_child[curr],0));
            ret=max(ret,solve_max(right_child[curr],1));
        }
        else
        {
            ret=0;
        }
    }

    return dpmax[curr][col];
}











int solve_min(int curr,int col)
{
    if(curr>=node_num || curr<0)
    {
        return 0;
    }

    if(dpmin[curr][col]!=-1)
    {
        return dpmin[curr][col];
    }

    int &ret=dpmin[curr][col];
    ret=INF;

    if(col==0)
    {
        if(left_child[curr]!=-1 && right_child[curr]!=-1)
        {
            ret=min(ret,1+solve_min(left_child[curr],1)+solve_min(right_child[curr],2));
            ret=min(ret,1+solve_min(left_child[curr],2)+solve_min(right_child[curr],1));
        }
        else if(left_child[curr]!=-1)
        {
            ret=min(ret,1+solve_min(left_child[curr],1));
            ret=min(ret,1+solve_min(left_child[curr],2));
        }
        else if(right_child[curr]!=-1)
        {
            ret=min(ret,1+solve_min(right_child[curr],1));
            ret=min(ret,1+solve_min(right_child[curr],2));
        }
        else
        {
            ret=1;
        }
    }
    else if(col==1)
    {
        if(left_child[curr]!=-1 && right_child[curr]!=-1)
        {
            ret=min(ret,solve_min(left_child[curr],0)+solve_min(right_child[curr],2));
            ret=min(ret,solve_min(left_child[curr],2)+solve_min(right_child[curr],0));
        }
        else if(left_child[curr]!=-1)
        {
            ret=min(ret,solve_min(left_child[curr],0));
            ret=min(ret,solve_min(left_child[curr],2));
        }
        else if(right_child[curr]!=-1)
        {
            ret=min(ret,solve_min(right_child[curr],0));
            ret=min(ret,solve_min(right_child[curr],2));
        }
        else
        {
            ret=0;
        }
    }
    else
    {
        if(left_child[curr]!=-1 && right_child[curr]!=-1)
        {
            ret=min(ret,solve_min(left_child[curr],0)+solve_min(right_child[curr],1));
            ret=min(ret,solve_min(left_child[curr],1)+solve_min(right_child[curr],0));
        }
        else if(left_child[curr]!=-1)
        {
            ret=min(ret,solve_min(left_child[curr],0));
            ret=min(ret,solve_min(left_child[curr],1));
        }
        else if(right_child[curr]!=-1)
        {
            ret=min(ret,solve_min(right_child[curr],0));
            ret=min(ret,solve_min(right_child[curr],1));
        }
        else
        {
            ret=0;
        }
    }

    return dpmin[curr][col];
}

int main(){

    freopen("Text/THREECOL.txt","r",stdin);

    int cases;
    int minn,maxx;
    scanf("%d",&cases);

    while(cases--)
    {
        node_num=0;
        MSET(dpmin,-1);
        MSET(dpmax,-1);
        MSET(left_child,-1);
        MSET(right_child,-1);
        minn=INF;
        maxx=-1;
        pos=0;

        scanf(" %s",tree);
        make_tree();
/*
        for(int i=0;i<node_num;++i)
        {
            printf("%d\t%d\t%d\n",i,left_child[i],right_child[i]);
        }
*/
        for(int i=0;i<3;++i)
        {
            minn=min(minn,solve_min(0,i));
            maxx=max(maxx,solve_max(0,i));
        }

        printf("%d %d\n",maxx,minn);

    }


    return 0;
}
