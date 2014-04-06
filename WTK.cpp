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

int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position
       k%n + 1 as position 1 */
    return (josephus(n - 1, k+1) + k-1) % n + 1;
}

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/WTK.txt","r",stdin);
    int i,j,x,y,z,k,cases,sum,m,temp,n,s;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        printf("%d\n",josephus(n,1));
    }


    return 0;
}

