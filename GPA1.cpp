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


int get_attendance(double a)
{
    if(a<51.0)
		return 5;
    if(a<61.0)
		return 4;
	if(a<71.0)
		return 3;
	if(a<81.0)
		return 2;
	if(a<91.0)
		return 1;
	else
		return 0;
}


int get_gp(double a)
{
	if(a>=91.0f)
		return 10;
    if(a>=81.0f)
		return 9;
	if(a>=71.0f)
		return 8;
	if(a>=61.0f)
		return 7;
	if(a>=51.0f)
		return 6;
	if(a==50.0f)
		return 5;
	else
		return 0;
}


int main(){

    freopen("Text/GPA1.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        int credit[6];
        int i;
        double gp=0.0,smcr=0.0;

        char a[10],b[10],c[10],d[10];

        bool flag=false;

        for(i=0;i<6;++i)
        {
            scanf("%d",credit+i);
            smcr+=credit[i];
        }


        for(i=0;i<6;++i)
        {
            double internals[3],fi,att,in;
            cin>>a>>b>>c>>d;

            if(!strcmp(a,"ab"))
            {
                internals[0]=0.0;
            }
            else
            {
                internals[0]=atof(a);
            }

            if(!strcmp(b,"ab"))
            {
                internals[1]=0.0;
            }
            else
            {
                internals[1]=atof(b);
            }

            if(!strcmp(c,"ab"))
            {
                internals[2]=0.0;
            }
            else
            {
                internals[2]=atof(c);
            }

            if(strcmp(d,"ab")==0)
            {
                fi = 0.0;
            }
			else
            {
                fi  = atof(d);
            }

            cin>>a;
            att=atof(a);

            sort(internals,internals+3);
            in=(internals[1]+internals[2])*45.0/40.0;
            att=get_attendance(att);
            fi/=2.0;
            fi=fi+att+in;
            fi=get_gp(fi);
            gp+=fi*credit[i];

            if(fi==0.0)
            {
                flag=true;
            }
        }

        gp/=smcr;

        if(flag)
        {
            printf("FAILED, %.2f\n",gp);
        }
		else
        {
            printf("PASSED, %.2f\n",gp);
        }

    }

    return 0;
}


