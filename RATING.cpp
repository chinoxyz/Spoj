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


#define MAXN 300003
int score1[MAXN],score2[MAXN];
int score1_sorted[MAXN],score2_sorted[MAXN];
int mp1[MAXN],rk2[MAXN];

bool myfunction1 (int i,int j)
{
    if(score1[i]==score1[j])
    {
        return (score2[i]>score2[j]);
    }
    return (score1[i]>score1[j]);
}

bool myfunction2 (int i,int j)
{
    if(score2[i]==score2[j])
    {
        return (score1[i]<=score1[j]);
    }
    return (score2[i]<score2[j]);
}


int n;

int ct[MAXN];
int tree[MAXN];
map<int,int> amp;

int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }

    return sum;
}


void update(int idx ,int val){
    //printf("Update\t%d\t%d\n",idx,val);
	while (idx <=n){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int main() {

    freopen("Text/RATING.txt","r",stdin);

    scanf("%d",&n);
    //printf("N\t%d\n",n);
    MSET(tree,0);

    for(int i=0;i<n;++i)
    {
        scanf("%d %d",score1+i,score2+i);
        score1_sorted[i]=i;
        score2_sorted[i]=i;
    }

    sort(score1_sorted,score1_sorted+n,myfunction1);
    sort(score2_sorted,score2_sorted+n,myfunction2);

    int j=0;
    amp.insert(MP(score2[score2_sorted[0]],1));

    j=1;
    for(int i=1;i<n;++i)
    {
        //if(amp.count(score2[score2_sorted[i]])<=0)
        if(score2[score2_sorted[i]]!=score2[score2_sorted[i-1]])
        {
            ++j;
            amp.insert(MP(score2[score2_sorted[i]],j));
        }
    }


    for(int i=0;i<n;++i)
    {
        mp1[score1_sorted[i]]=i;
    }


    for(int i=0;i<n;++i)
    {
        //rk2[mp1[score2_sorted[i]]]=i;
        rk2[i]=amp[score2[score1_sorted[i]]];
    }



    for(int i=n-1;i>=0;--i)
    {
        ct[i]=read(rk2[i]);
        update(rk2[i],1);
    }



    int cnt=0;
    for(int i=n-2;i>=0;--i)
    {
        if(score1[score1_sorted[i]]==score1[score1_sorted[i+1]] && score2[score1_sorted[i]]==score2[score1_sorted[i+1]])
        {
            ++cnt;
            ct[i]-=cnt;
        }
        else
        {
            cnt=0;
        }
    }

    for(int i=0;i<n;++i)
    {
        printf("%d\n",ct[mp1[i]]);
    }


    return 0;
}
