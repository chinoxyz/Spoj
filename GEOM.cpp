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

double m[4];
bool MINF[4];
double c[4];
double pts[4][2];
bool vall[4];
bool poss=true;
#define EPS 1e-8

bool eqq(double x,double y)
{
    if(fabs(x-y)<=EPS)
    {
        return true;
    }

    return false;
}



int main()
{
    freopen("Text/GEOM.txt","r",stdin);


    double x1,y1,x2,y2,l;

    cin>>x1>>y1;
    cin>>l;
    cin>>x2>>y2;

    pts[0][0]=x1-l/2.0;
    pts[0][1]=y1-l/2.0;

    pts[1][0]=x1-l/2.0;
    pts[1][1]=y1+l/2.0;

    pts[2][0]=x1+l/2.0;
    pts[2][1]=y1+l/2.0;

    pts[3][0]=x1+l/2.0;
    pts[3][1]=y1-l/2.0;

    for(int i=0;i<4;++i)
    {
        vall[i]=1;
        if(eqq(pts[(i+1)%4][1],y2))
        {
            MINF[i]=1;
            c[i]=pts[i][0];
        }
        else
        {
            m[i]=-(pts[(i+1)%4][0]-x2)/(pts[(i+1)%4][1]-y2);
            c[i]=pts[i][1]-m[i]*pts[i][0];
        }
    }

    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            if(i==j || !vall[j])
            {
                continue;
            }

            if(MINF[i] && MINF[j])
            {
                if(eqq(c[i],c[j]))
                {
                    vall[i]=0;
                    break;
                }
                else
                {
                    poss=false;
                }
            }
            else
            {
                if(eqq(m[i],m[j]))
                {
                    if(eqq(c[i],c[j]))
                    {
                        vall[i]=0;
                        break;
                    }
                    else
                    {
                        poss=false;
                    }
                }
            }
        }
    }

    VD xs;
    VD ys;
    double tx,ty;

    for(int i=0;i<4;++i)
    {
        //printf("%d\n",vall[i]);
    }

    if(poss)
    {

        for(int i=0;i<4;++i)
        {
            if(!vall[i])
            {
                continue;
            }
            for(int j=i+1;j<4;++j)
            {
                if(!vall[j])
                {
                    continue;
                }

                tx=(c[j]-c[i])/(m[i]-m[j]);
                ty=m[i]*tx+c[i];
                xs.PB(tx);
                ys.PB(ty);
                //printf("%.1f %.1f\n",tx,ty);
            }
        }


        if(xs.size()==0)
        {
            //printf("ccccccccDD\n");
            poss=0;
        }

        for(int i=1;i<xs.size();++i)
        {
            if(!eqq(xs[i],xs[i-1]) || !eqq(ys[i],ys[i-1]))
            {
                poss=0;
                break;
            }
        }

        if(!poss)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            printf("%.1f %.1f\n",xs[0],ys[0]);
        }




    }

    return 0;

}

