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
#include<cmath>


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

#define MAXN 11
char a[MAXN],b[MAXN];
i64 c;
bool poss;
i64 xl,xr,yl,yr;

bool xt,yt;
set<char> invals;
map<char,i64> mp;
i64 tr22, tr11,tl11,tl22;
i64 ml1,ml2,mr1,mr2;


void pree()
{
    invals.insert('A');
    invals.insert('C');
    invals.insert('M');
    invals.insert('I');
    invals.insert('P');

    for(char i='A';i<='Z';++i)
    {
        if(invals.count(i))
        {
            //printf("%c\n",i);
            continue;
        }

        mp[i]=tl22++;
    }

    tl11=26;
    tr11=10;
    tr22=10;


    i64 ti=25;
    for(int i=0;i<3;++i)
    {
        ml1+=ti;
        ti*=26;
    }

    ti=9;

    for(int i=3;i<7;++i)
    {
        mr1+=ti;
        ti*=10;
    }



    ti=tl22-1;
    for(int i=0;i<5;++i)
    {
        ml2+=ti;
        ti*=tl22;
    }

    ti=9;
    for(int i=5;i<7;++i)
    {
        mr2+=ti;
        ti*=10;
    }

    //printf("PREE\n");

    //printf("%lld\t%lld\t%lld\t%lld\t%lld\n\n",ml1,mr1,ml2,mr2,tl22);
}


i64 fromEnd(i64 l,i64 r)
{
    i64 ret=0;

    //printf("%lld\t%lld\n",ml1,mr1);

    ret+=(ml1-l)*(mr1+1);
    ret+=mr1-r;
    return ret;
}

i64 fromBeg(i64 l,i64 r)
{
    //i64 tot=(ml2+1)*(mr2+1);
    i64 ret=0;

    //ret+=(ml2-l)*(mr2+1);
    //ret+=(mr2-r);

    //ret=tot-ret-1;

    ret+=l*(mr2+1);
    ret+=r;

    return ret;

}

bool is_valid(char *s)
{
    if(s[3]>='0' && s[3]<='9' && s[4]>='A' && s[4]<='Z')
    {
        return 0;
    }

    if(s[3]>='A' && s[3]<='Z' && s[4]>='0' && s[4]<='9')
    {
        return 0;
    }

    return 1;
}

void setType(char *s,bool &t)
{
    if(s[3]>='0' && s[3]<='9')
    {
        t=0;
    }
    else
    {
        t=1;
    }
}

i64 calc(char *s,int st,int en,i64 &ret,i64 poww,char d)
{
    ret=0;
    for(int i=st;i<en;++i)
    {
        ret*=poww;
        ret+=s[i]-d;
    }
}

i64 calc2(char *s,int st,int en,i64 &ret,i64 poww,char d)
{
    ret=0;
    for(int i=st;i<en;++i)
    {
        ret*=poww;
        ret+=mp[s[i]];
    }
}

bool containsInvalid(char *s)
{
    for(int i=0;i<7;++i)
    {
        if(invals.count(s[i]))
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    freopen("Text/CPC.txt","r",stdin);
    pree();
    i64 d;

    while(true)
    {

        xl=xr=yl=yr=0;
        poss=1;
        //scanf("%s %s %lld",a,b,&c);
        cin>>a>>b>>c;
        if(strcmp(a,"*")==0)
        {
            break;
        }

        if(!is_valid(b))
        {
            poss=0;
        }
        else
        {

            setType(a,xt);
            setType(b,yt);

            if(yt==1 && containsInvalid(b))
            {

                poss=0;
            }
            else
            {

                if(strcmp(a,b)==0)
                {
                    poss=0;
                }
                else if(xt==1 && yt==0)
                {
                    poss=0;
                }
                else if(xt==0 && yt==0)
                {

                    if(strcmp(a,b)>=0)
                    {

                        poss=0;
                    }
                    else
                    {
                        calc(a,0,3,xl,tl11,'A');
                        calc(a,3,7,xr,tr11,'0');

                        calc(b,0,3,yl,tl11,'A');
                        calc(b,3,7,yr,tr11,'0');

                        d=fromEnd(xl,xr)-fromEnd(yl,yr);

                        if(d<=c && d>0)
                        {
                            poss=1;
                        }
                        else
                        {
                            poss=0;
                        }
                    }

                }
                else if(xt==0 && yt==1)
                {
                    calc(a,0,3,xl,tl11,'A');
                    calc(a,3,7,xr,tr11,'0');

                    calc2(b,0,5,yl,tl22,'A');
                    calc(b,5,7,yr,tr22,'0');

                    d=fromEnd(xl,xr)+fromBeg(yl,yr)+1;



                    if(d<=c && d>0)
                    {
                        poss=1;
                    }
                    else
                    {
                        poss=0;
                    }


                }
                else
                {
                    if(strcmp(a,b)>=0)
                    {
                        poss=0;
                    }
                    else
                    {
                        calc2(a,0,5,xl,tl22,'A');
                        calc(a,5,7,xr,tr22,'0');

                        calc2(b,0,5,yl,tl22,'A');
                        calc(b,5,7,yr,tr22,'0');

                        d=fromBeg(yl,yr)-fromBeg(xl,xr);



                        if(d<=c && d>0)
                        {
                            poss=1;
                        }
                        else
                        {
                            poss=0;
                        }
                    }
                }
            }
        }


        //printf("%lld\t%lld\t%lld\t%lld\t%lld\t%d\t%d\n",xl,xr,yl,yr,d,xt,yt);



        if(poss)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }

    return 0;
}
