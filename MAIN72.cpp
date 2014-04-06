#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <bitset>
#include<string>
#include <set>

using namespace std;
#define i64 long long

#define pii pair< int,int >
#define piii pair< pii,int >
#define ff first.first
#define fs first.second

#define EPS 1e-9

bitset<1000000> a;
vector<int> v;

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/MAIN72.txt","r",stdin);
    int i,j,x,y,z,k,cases,sum,m,temp,n,s;

    scanf("%d",&cases);

    while(cases--)
    {
        v.clear();
        a.reset();
        a.set(0);
        v.push_back(0);
        sum=0;

        scanf("%d",&n);

        for(i=0;i<n;++i)
        {
            scanf("%d",&m);
            s=v.size();

            for(j=0;j<s;++j)
            {
                temp=v[j]+m;
                if(!a.test(temp))
                {
                    a.set(temp);
                    v.push_back(temp);
                    sum+=temp;
                }
            }
        }

        printf("%d\n",sum);
    }


    return 0;
}

