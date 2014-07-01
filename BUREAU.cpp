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

#define MAXN 100000

int a[MAXN];
bitset<MAXN> bs;
VI ans;
int tot;

int main()
{

    freopen("Text/BUREAU.txt","r",stdin);
    int cases,n,i,num,sz;

    scanf("%d",&cases);
    char buff[10];

    while(cases--)
    {
        ans.clear();
        scanf("%d",&n);
        bs.reset();
        REP(i,n)
        {
            scanf("%s",buff);
            if(!strcmp(buff,"declare"))
            {
                a[i]=-1;
            }
            else
            {
                scanf("%d",&num);
                --num;
                a[i]=num;
            }
        }

        for(i=n-1;i>=0;--i)
        {
            if(a[i]>=0 && !bs.test(i))
            {
                bs.set(a[i]);
            }
        }

        REP(i,n)
        {
            if(!bs.test(i))
            {
                ans.PB(i);
            }
        }

        tot=ans.size();
        printf("%d\n",tot);
        --tot;

        REP(i,tot)
        {
            printf("%d ",ans[i]+1);
        }
        printf("%d\n",ans[i]+1);

    }

	return 0;
}
