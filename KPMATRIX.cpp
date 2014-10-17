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

#define MAXN 255
#define DUMMY 0

int n,m,a,b;
int arr[MAXN][MAXN];
int summ[MAXN];
int reqa[MAXN],reqb[MAXN];
int bitt[3*MAXN];
VI nums;
int nums_len;
VI::iterator it;


void update(int pos)
{
    //printf("%d\n",pos);
    while(pos<nums_len)
    {
        //printf("DD\t%d\n",pos);
        ++bitt[pos];
        pos+=(pos&(-pos));
    }
}

int query(int pos)
{
    int ret=0;

    while(pos>0)
    {
        ret+=bitt[pos];
        pos-=(pos&(-pos));
    }

    return ret;
}

void solve()
{
    int ret=0;

    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {

            nums.clear();
            nums.PB(DUMMY);

            summ[0]=0;
            reqa[0]=summ[0]-a;
            reqb[0]=summ[0]-b-1;

            nums.PB(summ[0]);
            nums.PB(reqa[0]);
            nums.PB(reqb[0]);


            for(int k=1;k<=m;++k)
            {

                summ[k]=summ[k-1]+arr[j][k]-arr[i-1][k];
                reqa[k]=summ[k]-a;
                reqb[k]=summ[k]-b-1;

                nums.PB(summ[k]);
                nums.PB(reqa[k]);
                nums.PB(reqb[k]);
            }



            sort(nums.begin()+1,nums.end());
            it=unique(nums.begin()+1,nums.end());
            nums.resize(distance(nums.begin(),it));



            nums_len=nums.size();
            int ti;

            MSET(bitt,0);
            it=lower_bound(nums.begin()+1,nums.end(),summ[0]);
            ti=it-nums.begin();

            //printf("Nums Len\t%d\n",nums_len);

            update(ti);

            for(int k=1;k<=m;++k)
            {
                //printf("DD\n");
                int en=lower_bound(nums.begin()+1,nums.end(),reqa[k])-nums.begin();
                int st=lower_bound(nums.begin()+1,nums.end(),reqb[k])-nums.begin();

                ret+=query(en)-query(st);

                it=lower_bound(nums.begin()+1,nums.end(),summ[k]);
                ti=it-nums.begin();

                update(ti);
            }
        }
    }

    printf("%d\n",ret);
}


int main()
{
    freopen("Text/KPMATRIX.txt","r",stdin);

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&arr[i][j]);
            arr[i][j]+=arr[i-1][j];
        }
    }

    scanf("%d %d",&a,&b);
    solve();

    return 0;
}
