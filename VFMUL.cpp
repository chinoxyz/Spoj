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


#define BASE 5
#define BASEP 100000
#define MAXL 310000
#define BTS 16
#define BTSX2 32
#define BTSM1 15
#define BTSP 65536
#define BTSPM1 65535

const LD PI=acos(0.0L)*2;

typedef complex<LD> Complex;

unsigned int revv[BTSP];

static char numma[MAXL];
static char nummb[MAXL];


void pree()
{
    int i,j,k;

    for(i=0;i<BTSP;++i)
    {
        j=0;

        for(k=0;k<BTS;++k)
        {
            j|=((i>>k)&1)<<((BTSM1)-k);
        }

        revv[i]=j;
    }
}


void FFT(Complex *a,int n,int ninv)
{
    int lgn;
    lgn=log2(n)+0.5;
    int tn,tnb2;

    int s,k,j;
    unsigned int i;

    for(i=0;i<n;++i)
    {
        unsigned int j=((revv[i&(BTSPM1)]<<BTS) | revv[i>>BTS])>>(BTSX2-lgn);
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }

    for(s=1;s<=lgn;++s)
    {
        tn=1<<s;
        tnb2=tn>>1;

        Complex w,tw=exp(Complex(0,ninv*2*PI/tn));

        for(k=0;k<n;k+=tn)
        {
            w=1;
            for(j=0;j<tnb2;++j)
            {
                Complex ti=w*a[k+tnb2+j];
                a[k+tnb2+j]=a[k+j]-ti;
                a[k+j]+=ti;
                w*=tw;
            }
        }

    }
}

void str_to_complex(vector<Complex> &v,const char *numm)
{
    int n=strlen(numm);
    int m=(n+BASE-1)/BASE;
    v.resize(m);
    int i,a,b,ti;

    for(i=0;i<m;++i)
    {
        b=n-BASE*i;
        ti=0;

        for(a=max(0,b-BASE);a<b;++a)
        {
            ti*=10;
            ti+=numm[a]-'0';
        }

        v[i]=ti;
    }
}

void display(const vector<Complex> &v)
{
    int i,n=v.size();
    Vi64 arr(n+1,0);

    for(i=0;i<n;++i)
    {
        arr[i]=(i64)(v[i].real()+.5);
    }

    i64 c=0;

    for(i=0;i<n;++i)
    {
        c+=arr[i];
        arr[i]=c%BASEP;
        c/=BASEP;
    }

    for(i=n-1;i>0 && arr[i]==0;--i);

    printf("%lld",arr[i]);

    for(i--;i>=0;--i)
    {
        printf("%.*lld",BASE,arr[i]);
    }

    printf("\n");
}


int main()
{
    freopen("Text/VFMUL.txt","r",stdin);
    pree();

    int cases;
    int n;
    scanf("%d",&cases);
    int i,mx;

    while(cases--)
    {
        scanf("%s %s",numma,nummb);
        //printf("%s\t%s\n",numma,nummb);

        vector<Complex> A,B;
        str_to_complex(A,numma);
        str_to_complex(B,nummb);

        n=1;
        mx=max(A.size(),B.size());
        while(n<mx)
        {
            n<<=1;
        }
        n<<=1;

        A.resize(n);
        B.resize(n);


        FFT(&A[0],n,1);
        FFT(&B[0],n,1);

        for(i=0;i<n;++i)
        {
            A[i]*=B[i];
        }

        FFT(&A[0],n,-1);

        for(i=0;i<n;++i)
        {
            A[i]/=n;
        }

        display(A);
    }


    return 0;
}
