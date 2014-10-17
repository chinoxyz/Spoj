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


string mnn,mxx;

int absurdd(string s)
{
    int len=s.length();
   int en=len-1;

   while(s[en]=='0')
   {
       --en;
   }

   int ret;

   if(s[en]=='5')
   {
       ret=(en+1)*2-1;
   }
   else
   {
       ret=(en+1)<<1;
   }

   return ret;
}




int main()
{
    freopen("Text/ABSURD.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    bool poss;
    int num,mn,mx;
    int val;
    int i;
    string str;
    int diff;


    while(cases--)
    {
        mnn="";
        cin>>str;
        stringstream ss(str);
        ss>>num;

        mn=ceil(.95*num);
        mx=1.05*num;

        ostringstream os;
        os<<mn;
        mnn=os.str();

        ostringstream os2;
        os2<<mx;
        mxx=os2.str();

        poss=false;

        val=absurdd(str);

        if(mnn.size()!=mxx.size())
        {
            mn=2;
        }
        else if(mn!=mx)
        {
            int ct=0;

            while(mnn[ct]==mxx[ct])
            {
                ++ct;
            }
            mn=2*(ct+1);

            if(mnn[ct]<'5' && mxx[ct]>='5')
            {
                --mn;
            }
        }
        else
        {
            mn=9999999;
        }

        mn=min(mn,absurdd(mnn));

        if(mn<val)
        {
            poss=true;
        }

        if(poss)
        {
            printf("absurd\n");
        }
        else
        {
            printf("not absurd\n");
        }
    }



    return 0;
}
