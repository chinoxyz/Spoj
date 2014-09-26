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

const int MAXN=1<<17;
VI a,ones;
int n,ans;

void fill_part(VI &part,int maxv[],bool met[],int *start,int delta,int *stop)
{
    part.clear();
    int curr_max=1;
    maxv[0]=curr_max;

    for(int *i=start;i!=stop && !met[*i];i+=delta)
    {
        part.PB(*i);
        met[*i]=true;
        curr_max=max(curr_max,*i);
        maxv[part.size()]=curr_max;
    }
}


int max_take_q[MAXN];

int solve_assuming_max_at_p(VI &p,VI &q,bool met_at_p[],int maxv_at_p[],int maxv_at_q[])
{
    int best=0;
    int take_q=q.size();
    for(int take_p=p.size();take_p>=0;--take_p)
    {
        int curr_max=maxv_at_p[take_p];

        while(take_q>0 && maxv_at_q[take_q]>=curr_max)
        {
            --take_q;
        }

        max_take_q[take_p]=take_q;
    }

    take_q=0;

    for(int take_p=p.size();take_p>=0;--take_p)
    {
        int curr_max=maxv_at_p[take_p];

        while(take_q<q.size() && !met_at_p[q[take_q]])
        {
            ++take_q;
        }

        int new_take_q=min(take_q,max_take_q[take_p]);

        if(new_take_q+take_p+1==curr_max)
        {
            best=max(best,curr_max);
        }

        if(take_p)
        {
            met_at_p[p[take_p-1]]=false;
        }
    }


    return best;
}



VI left_part,right_part;
int maxv_at_left[MAXN],maxv_at_right[MAXN];
bool met_at_left[MAXN],met_at_right[MAXN];



int process_around_one(int center,int left_stop,int right_stop)
{
    fill_part(left_part,maxv_at_left,met_at_left,&a[center-1],-1,&a[left_stop]);
    fill_part(right_part,maxv_at_right,met_at_right,&a[center+1],+1,&a[right_stop]);

    return max(solve_assuming_max_at_p(left_part,right_part,met_at_left,maxv_at_left,maxv_at_right),
                solve_assuming_max_at_p(right_part,left_part,met_at_right,maxv_at_right,maxv_at_left));
}

int main(){

    freopen("Text/LPERMUT.txt","r",stdin);

    scanf("%d",&n);

    //ones.reserve(n+2);
    ones.PB(-1);
    int v;

    for(int i=0;i<n;++i)
    {
        scanf("%d",&v);
        a.PB(v);
        if(v==1)
        {
            ones.PB(i);
        }
    }

    ones.PB(n);

    MSET(met_at_left,0);
    MSET(met_at_right,0);

    ans=0;


    for(int i=1;i<ones.size()-1;++i)
    {
        ans=max(ans,process_around_one(ones[i],ones[i-1],ones[i+1]));
    }

    printf("%d\n",ans);


    return 0;
}


