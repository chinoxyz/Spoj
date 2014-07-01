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

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}



//#define gc getchar_unlocked
#define gc getchar



inline i64 readPosLLD()
{
    i64 ret=0;
    char c;
    c=gc();

    while(c!=EOF && (c<'0' || c>'9'))
    {
        //scanf("%c",&c);
        c=gc();
        //printf("DD\n");
    }

    while((c>='0' && c<='9'))
    {
        ret=ret*10+(c-'0');
        c=gc();
        //printf("MM\n");
    }

    return ret;
}

#define MOD 1000000007

map<i64,int> mp;
map<i64,int> mp1;
map<i64,int> mp2;

int main()
{

    freopen("Text/DIVISION.txt","r",stdin);
    int j,ans;
    i64 n,i,mx;
    int a[3],b[3];
    mp[0]=1;
    mp1[0]=0;
    mp2[0]=0;
    mx=0;

    while((n=readPosLLD())>0)
    {
        a[0]=mp[n];

        if(a[0]==0)
        {
            MSET(b,0);
            a[0]=mp[mx];
            a[1]=mp1[mx];
            a[2]=mp2[mx];

            b[0]=a[0];
            b[1]=a[1];
            b[2]=a[2];

            for(i=mx;i<n;++i)
            {
                if(i&1)
                {
                    b[0]+=a[1];
                    b[1]+=a[2];
                    b[2]+=a[0];
                }
                else
                {
                    b[0]+=a[2];
                    b[1]+=a[0];
                    b[2]+=a[1];
                }
                b[0]%=MOD;
                b[1]%=MOD;
                b[2]%=MOD;

                a[0]=b[0];
                a[1]=b[1];
                a[2]=b[2];

                mp[i+1]=a[0];
                mp1[i+1]=a[1];
                mp2[i+1]=a[2];
            }

            mx=n;

        }
        printf("%d\n",a[0]);
    }

	return 0;
}
