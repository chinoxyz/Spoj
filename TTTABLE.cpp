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


int tt,n,m;

vector<PIPII > trains;




int main()
{
    freopen("Text/TTTABLE.txt","r",stdin);

    int cases;
    char buff[55],buff2[55];

    scanf("%d",&cases);
    int hh,mm,hh2,mm2;
    int tot,ans0,ans1,st,timeb,timee;

    for(int cn=1;cn<=cases;++cn)
    {
        priority_queue<int> av0,av1;
        trains.clear();
        scanf("%d",&tt);
        scanf("%d %d",&n,&m);

        for(int i=0;i<n;++i)
        {
            scanf("%s %s",buff,buff2);
            sscanf(buff,"%d:%d",&hh,&mm);
            sscanf(buff2,"%d:%d",&hh2,&mm2);
            trains.PB(MP(hh*60+mm,MP(hh2*60+mm2,0)));
        }

        for(int i=0;i<m;++i)
        {
            scanf("%s %s",buff,buff2);
            sscanf(buff,"%d:%d",&hh,&mm);
            sscanf(buff2,"%d:%d",&hh2,&mm2);
            trains.PB(MP(hh*60+mm,MP(hh2*60+mm2,1)));
        }

        sort(trains.begin(),trains.end());
        tot=n+m;

        ans0=ans1=0;

        for(int i=0;i<tot;++i)
        {
            st=trains[i].second.second;
            timeb=trains[i].first;
            timee=trains[i].second.first;

            if(st==0)
            {
                if(av0.size()==0 || -av0.top()>timeb)
                {
                    ++ans0;
                }
                else
                {
                    av0.pop();
                }

                av1.push(-(timee+tt));
            }
            else
            {
                if(av1.size()==0 || -av1.top()>timeb)
                {
                    ++ans1;
                }
                else
                {
                    av1.pop();
                }

                av0.push(-(timee+tt));
            }
        }


        printf("Case #%d: %d %d\n",cn,ans0,ans1);

    }


    return 0;
}
