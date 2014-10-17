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


int main()
{
    freopen("Text/HANDS.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    char buff[10];

    i64 vhn=360LL;
    i64 vhd=12LL*60LL*60LL;

    i64 vmn=360LL*12LL;
    i64 vmd=12LL*60LL*60LL;

    i64 rel_veln=vmn-vhn;
    i64 rel_veld=vmd;

    i64 ans,sth,stm,sts,enh,enm,ens;
    double stha,stma,diff;

    while(cases--)
    {
        ans=0;
        scanf("%s",buff);
        sth=(buff[0]-'0')*10LL+buff[1]-'0';
        stm=(buff[3]-'0')*10LL+buff[4]-'0';
        sts=sth*60LL*60LL+stm*60LL;
        //printf("ST\t%s\n",buff);

        scanf("%s",buff);
        //printf("EN\t%s\n",buff);
        enh=(buff[0]-'0')*10LL+buff[1]-'0';
        enm=(buff[3]-'0')*10LL+buff[4]-'0';
        ens=enh*60LL*60LL+enm*60LL;

        i64 ts=ens-sts;
        //printf("TSSSSS\t%lld\n",ts);

        stha=(((i64)sth%12LL)*360LL/12LL+ (double)(stm*360LL)/(double)(12LL*60LL));

        while(stha>=360.0)
        {
            stha-=360.0;
        }
        stma=0;
        stma=(stm*360LL/60LL)%360LL;

        //printf("%f\t%f\n",stha,stma);

        if(stha>=stma)
        {
            diff=stha-stma;
        }
        else
        {
            diff=360.0-stma+stha;
        }

        //diff=stha-stma;

        //printf("DIFF\t%f\n",diff);

        double t1=diff*rel_veld;
        double leftt=ts-(t1/(double)rel_veln);
        //printf("LEFTT\t%f\n",leftt);
        if(leftt>=0.0)
        {
            //printf("DD\n");
            if(diff)
            {
                ++ans;
            }

            double ti=(leftt*rel_veln/rel_veld)/360.0;
            //printf("TIII\t%lld\n",ti);
            ans+=ti;
        }

        printf("%lld\n",ans);
    }



    return 0;
}
