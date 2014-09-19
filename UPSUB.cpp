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

#define MAXL 105

char str[MAXL];
int len;

VI prevv[MAXL];
int ml[MAXL];
int gl_best;
VI gl_list;
set<string> st;


void solve(int pos, string s)
{
    if(prevv[pos].size()==0)
    {
        s=str[pos]+s;
        s+="\0";
        st.insert(s);
        return;
    }

    s=str[pos]+s;

    for(int i=0;i<prevv[pos].size();++i)
    {
        solve(prevv[pos][i],s);
    }
}

int main() {

    freopen("Text/UPSUB.txt","r",stdin);

    int cases;
    set<string>::iterator it;

    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%s",str);
        len=strlen(str);
        gl_list.clear();
        st.clear();

        for(int i=0;i<len;++i)
        {
            prevv[i].clear();
            ml[i]=1;
            gl_best=1;
            gl_list.PB(i);
        }


        for(int i=1;i<len;++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(str[j]<=str[i])
                {
                    int ti=ml[j]+1;
                    if(ti>ml[i])
                    {
                        prevv[i].clear();
                        prevv[i].PB(j);
                        ml[i]=ti;
                        if(ml[i]>gl_best)
                        {
                            gl_best=ml[i];
                            gl_list.clear();
                            gl_list.PB(i);
                        }
                        else if(gl_best==ml[i])
                        {
                            gl_list.PB(i);
                        }
                    }
                    else if(ti==ml[i])
                    {
                        prevv[i].PB(j);

                        if(ml[i]>gl_best)
                        {
                            gl_best=ml[i];
                            gl_list.clear();
                            gl_list.PB(i);
                        }
                        else if(gl_best==ml[i])
                        {
                            gl_list.PB(i);
                        }
                    }
                }
            }
        }

        for(int i=0;i<gl_list.size();++i)
        {
            solve(gl_list[i],"");
        }

        for(it=st.begin();it!=st.end();++it)
        {
            printf("%s\n",(*it).c_str());
        }
        printf("\n");
    }


    return 0;
}
