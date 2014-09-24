#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define MAXK 52
#define MAXN 10001
#define MODD 5000000

int freq[MAXK][MAXN],lastt[MAXK][MAXN],m=0;
int arr[MAXN],sorted_arr[MAXN];
map<int,int> values_to_compression;

int read(int *b,int x)
{
    if(b==freq[0])
    {
        return 1;
    }

    int ret=0;

    for(;x;)
    {
        ret+=b[x];
        if(ret>=MODD)
        {
            ret-=MODD;
        }
        x-=(x & -x);
    }

    return ret;
}


void update(int *b,int x,int v)
{
    for(;x<MAXN;)
    {
        b[x]+=v;
        if(b[x]>=MODD)
        {
            b[x]-=MODD;
        }
        x+=(x&-x);
    }
}

int main(void){

    freopen("Text/INCDSEQ.txt","r",stdin);

    int k,n,t,z;

    scanf("%d %d",&n,&k);

    for(int i=0;i<n;++i)
    {
        scanf("%d",arr+i);
        sorted_arr[i]=arr[i];
    }

    sort(sorted_arr,sorted_arr+n);

    for(int i=0;i<n;++i)
    {
        if(!values_to_compression.count(sorted_arr[i]))
        {
            values_to_compression[sorted_arr[i]]=++m;
        }
    }


    for(int i=0;i<n;++i)
    {
        z=values_to_compression[arr[i]];

        for(int l=1;l<=k;++l)
        {
            int &x=lastt[l-1][z-1];
            t=read(freq[l-1],z-1);

            if(t!=x)
            {
                int temp=t;
                t-=x;
                if(t<0)
                {
                    t+=MODD;
                }
                x=temp;

                update(freq[l],z,t);
            }
        }
    }

    printf("%d\n",read(freq[k],MAXN-1));

	return 0;
}

