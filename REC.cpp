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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 222

struct Matrix
{
    int arr[2][2];
};

Matrix leftt;


char a[MAXN],b[MAXN],n[MAXN];
int la,lb,ln;
int m;

int modd(char *s,int m,int lenn)
{
    int ret=0;

    for(int i=0;i<lenn;++i)
    {
        ret*=10;
        ret+=s[i]-'0';
        ret%=m;
    }

    return ret;
}


void multt(Matrix &a,Matrix &b)
{
    Matrix ti;

    int i,j,k;

    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            ti.arr[i][j]=0;
            for(k=0;k<2;++k)
            {
                ti.arr[i][j]+=(((i64)a.arr[i][k]*b.arr[k][j])%m);
                ti.arr[i][j]%=m;
            }
        }
    }

    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            a.arr[i][j]=ti.arr[i][j];
        }
    }
}


bool greater0(char *n)
{
    int lenn=strlen(n);
    if(lenn==1 && n[0]=='0')
    {
        return 0;
    }

    return 1;
}

bool isOdd(char *n)
{
    int lenn=strlen(n);
    if((n[lenn-1]-'0')&1)
    {
        return 1;
    }

    return 0;
}


void divide2(char *n)
{
    int lenn=strlen(n);
    //printf("%d\n",lenn);
    int i;

    if(lenn==1 && n[0]=='1')
    {
        n[0]='0';
        n[1]=0;
        return;
    }
    char t[MAXN];
    int st,numm;
    int pos=0;

    if(n[0]=='1')
    {
        numm=1;
        st=1;
    }
    else
    {
        numm=0;
        st=0;
    }

    for(;st<lenn;++st,++pos)
    {
        numm*=10;
        numm+=n[st]-'0';
        t[pos]=(numm/2)+'0';
        numm%=2;
    }

    t[pos]=0;

    memcpy(n,t,sizeof(t));
    //printf("N\t%s\n",n);

}

void poww(Matrix &m,char *p,int lenn)
{
    Matrix ret;
    ret.arr[0][0]=ret.arr[1][1]=1;
    ret.arr[0][1]=ret.arr[1][0]=0;

    while(greater0(p))
    {
        if(isOdd(p))
        {
            multt(ret,m);
        }

        divide2(p);
        multt(m,m);
    }

    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            m.arr[i][j]=ret.arr[i][j];
        }
    }
}

void MAIN()
{
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        cin>>a>>b>>n>>m;
        la=strlen(a);
        lb=strlen(b);
        ln=strlen(n);

        leftt.arr[0][0]=modd(a,m,la);
        leftt.arr[0][1]=modd(b,m,lb);
        leftt.arr[1][0]=0;
        leftt.arr[1][1]=1;

        poww(leftt,n,ln);

        printf("%d\n",(leftt.arr[0][0]+leftt.arr[0][1])%m);

    }


}

int main()
{
	freopen("Text/REC.txt","r",stdin);

    MAIN();

	return 0;
}
