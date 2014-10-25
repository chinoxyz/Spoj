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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXN 100005

map<string,int> person;
map<string,int> gp;

int arr[MAXN];
int mpp[MAXN];
int n,m;
int chan;
string rmp[MAXN];

int rn;
string namee,locc;
int rm;
string xx,yy;


int main()
{
    freopen("Text/HMRO.txt","r",stdin);
    int cases;

    scanf("%d",&cases);
    int ti;

    while(cases--)
    {
        scanf("%d",&n);
        rn=0;
        rm=0;

        person.clear();
        gp.clear();

        for(int i=1;i<=n;++i)
        {
            cin>>namee>>locc;
            if(!person[namee])
            {
                ++rn;
                person[namee]=rn;
            }

            if(!gp[locc])
            {
                ++rm;
                gp[locc]=rm;
            }

            rmp[gp[locc]]=locc;

            arr[person[namee]]=gp[locc];
        }

        for(int i=1;i<=rm;++i)
        {
            mpp[i]=i;
        }

        scanf("%d",&chan);

        for(int i=1;i<=chan;++i)
        {
            cin>>xx>>yy;

            mpp[gp[xx]]=mpp[gp[yy]];
        }

        for(int i=1;i<=rm;++i)
        {
            ti=i;

            while(mpp[ti]!=ti)
            {
                ti=mpp[ti];
            }

            mpp[i]=ti;
            //printf("%d\t%d\t%s\n",i,mpp[i],rmp[i].c_str());
        }

        scanf("%d",&m);

        for(int i=1;i<=m;++i)
        {
            cin>>xx;
            cout<<xx<<" ";
            cout<<rmp[mpp[arr[person[xx]]]]<<endl;
        }

        printf("\n");
    }

    return 0;
}
